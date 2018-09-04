/*****************************************************************************
**
**  Implementation of the reed solomon codec interface
**
**  Creation date:  2016/06/28
**  Created by:     Piql
**
**
**  Copyright (c) 2016 Piql AS. All rights reserved.
**
**  This file is part of the boxing library
**
*****************************************************************************/

//  PROJECT INCLUDES
//
#include "boxing/log.h"
#include "boxing/platform/memory.h"
#include <stdio.h>
#include "mod2sparse.h"
#include "mod2dense.h"
#include "rcode.h"
#include "boxing/codecs/ldpccodec.h"
#include "enc.h"
#include "dec.h"
#include "boxing/utils.h"

//  DEFINES
//

#define MAX_DEGREE_LIMIT 256
#define CODEC_MEMBER(name) (((boxing_codec_ldpc *)codec)->name)
#define CODEC_BASE_MEMBER(name) (((boxing_codec_ldpc *)codec)->base.name)


//  CONSTANTS
//


//  PRIVATE INTERFACE
//

static DBOOL codec_encode(void * codec, gvector * data);
static DBOOL codec_decode(void * codec, gvector * data, gvector * erasures, boxing_stats_decode * stats, void* user_data);


/*! 
  * \ingroup codecs
  * \{
  */


//----------------------------------------------------------------------------
/*!
 *  \var    codec_ldpc_name
 *  \brief  Ldpc codec name constant.
 *  
 *  Ldpc codec name constant.
 */


//----------------------------------------------------------------------------
/*!
 *  \struct     boxing_codec_ldpc_s  ldpccodec.h
 *  \brief      Ldpc codec data storage.
 *
 *  \param base        Base boxing_codec instance.
 *  \param iterations  Iteration.
 *  \param gen_matrix  Generator matrix.
 *
 *  Structure for storing ldpc codec data.
 */


// PUBLIC LDPC FUNCTIONS
//

//----------------------------------------------------------------------------
/*!
 *  \brief Create an boxing_codec_ldpc instance.
 *
 *  Allocate memory for the boxing_codec_ldpc type
 *  and initializes all structure data according to the input values.
 *  Return instance of allocated structure.
 *
 *  \param[in]  properties  Hash table with codec properties.
 *  \param[in]  config      Pointer to the boxing_config structure.
 *  \return instance of allocated boxing_codec_ldpc structure reduced to boxing_codec structure.
 */

boxing_codec * boxing_codec_ldpc_create(GHashTable * properties, const boxing_config * config)
{
    BOXING_UNUSED_PARAMETER( config );
    boxing_codec_ldpc * codec = BOXING_MEMORY_ALLOCATE_TYPE(boxing_codec_ldpc);

    g_variant * var_message_size = g_hash_table_lookup(properties, PARAM_NAME_MESSAGE_SIZE);
    if (var_message_size == NULL)
    {
        DLOG_ERROR("Requires property 'messageSize' to be set");
        return NULL;
    }
    
    g_variant * var_parity_size = g_hash_table_lookup(properties, PARAM_NAME_PARITY_SIZE);
    if (var_parity_size == NULL)
    {
        DLOG_ERROR("Requires property 'byteParityNumber' to be set");
        return NULL;
    }

    boxing_codec_init_base((boxing_codec *)codec);
    codec->base.free = boxing_codec_ldpc_free;
    codec->base.is_error_correcting = DTRUE;
    codec->base.name = codec_ldpc_name;

    /* convert to bits */
    int message_size = g_variant_to_uint(var_message_size) * 8;
    /* convert to bits */
    int parity_size = g_variant_to_uint(var_parity_size) * 8;

    // configure ldpc
    // ex-ldpc36-1000a.pchk 1600 16000 1 evenboth 3 no4cycle
    codec->iterations = 25;
    int seed = 1;
    int no4cycle = 1;
    distrib *d = distrib_create("3");
    mod2sparse * H = ldcp_pchk_make(seed, pchk_evenboth, d, no4cycle, parity_size, parity_size + message_size);
    codec->gen_matrix = ldpc_generator_make_dense_mixed(H, gen_dense);
    mod2sparse_free(H);

    codec->base.decoded_symbol_size = 8;
    codec->base.decoded_block_size = message_size / 8;

    codec->base.encoded_symbol_size = 1;
    codec->base.encoded_block_size = message_size + parity_size;

    codec->base.decode = codec_decode;
    codec->base.encode = codec_encode;

    return (boxing_codec *)codec;
}


//----------------------------------------------------------------------------
/*!
 *  \brief Frees occupied memory of boxing_codec_ldpc structure.
 *
 *  Frees occupied memory of all internal structure pointers and structure pointer.
 *
 *  \param[in]  codec  Pointer to the boxing_codec structure.
 */

void boxing_codec_ldpc_free(boxing_codec * codec)
{
    ldpc_generator_free(CODEC_MEMBER(gen_matrix));
    boxing_codec_release_base(codec);
    boxing_memory_free(codec);
}


//----------------------------------------------------------------------------
/*!
  * \} end of codecs group
  */


// PRIVATE LDPC CODEC FUNCTIONS
//

static void unpack_data(char *src, char *dst, unsigned int src_size)
{
    uint32_t *value = (uint32_t *)dst;
    char *src_end = src + src_size;
    while (src != src_end)
    {
        *value++ =
            (0x10 & *src) << 20 |
            (0x20 & *src) << 11 |
            (0x40 & *src) << 2  |
            (0x80 & *src) >> 7;
        *value++ =
            (0x01 & *src) << 24 |
            (0x02 & *src) << 15 |
            (0x04 & *src) << 6  |
            (0x08 & *src) >> 3;
        src++;
    }
}

static void pack_data(char *src, char *dst, unsigned int src_size)
{
    uint32_t *unpacked_data = (uint32_t *)src;
    char      packed_data;
    while (src_size)
    {
        packed_data =
            (0x01000000 & *unpacked_data) >> 20 |
            (0x00010000 & *unpacked_data) >> 11 |
            (0x00000100 & *unpacked_data) >> 2  |
            (0x00000001 & *unpacked_data) << 7;
        unpacked_data++;
        packed_data |=
            (0x01000000 & *unpacked_data) >> 24 |
            (0x00010000 & *unpacked_data) >> 15 |
            (0x00000100 & *unpacked_data) >> 6  |
            (0x00000001 & *unpacked_data) << 3;
        unpacked_data++;

        *dst = packed_data;
        dst++;
        src_size -= 8;
    }
}

static DBOOL codec_encode(void * codec, gvector * data)
{
    boxing_codec_ldpc * ldpc_codec = (boxing_codec_ldpc*)codec;

    generator_matrix *gen_matrix = ldpc_codec->gen_matrix;
    gvector  *encoded_data = gvector_create(data->item_size, ldpc_codec->base.encoded_data_size);

    char *src = data->buffer;
    char *dst = encoded_data->buffer;
    int   blocks = (int)encoded_data->size / ldpc_codec->base.encoded_block_size;
    char *unpacked_data_block = BOXING_MEMORY_ALLOCATE_TYPE_ARRAY(char, ldpc_codec->base.decoded_block_size*ldpc_codec->base.decoded_symbol_size);

    for (int i = 0; i < blocks; i++)
    {
        // convert data from byte to bit stream 
        unpack_data(src, unpacked_data_block, ldpc_codec->base.decoded_block_size);

        ldpc_encode(gen_matrix, unpacked_data_block, dst);
        src += ldpc_codec->base.decoded_block_size;
        dst += ldpc_codec->base.encoded_block_size;
    }
    boxing_memory_free(unpacked_data_block);
    gvector_swap(data, encoded_data);
    gvector_free(encoded_data);
    return DTRUE;
}

static DBOOL codec_decode(void * codec, gvector * data, gvector * erasures, boxing_stats_decode * stats, void* user_data)
{
    BOXING_UNUSED_PARAMETER(erasures);
    BOXING_UNUSED_PARAMETER(user_data);


    BOXING_UNUSED_PARAMETER(stats); // not shure how to do this

    boxing_codec_ldpc * ldpc_codec = (boxing_codec_ldpc*)codec;

    generator_matrix *gen_matrix = ldpc_codec->gen_matrix;
    gvector * decoded_data = gvector_create(data->item_size, ldpc_codec->base.decoded_data_size);

    char *src = data->buffer;
    char *dst = decoded_data->buffer;
    int blocks = (int)decoded_data->size / ldpc_codec->base.decoded_block_size;
    double *lratio = BOXING_MEMORY_ALLOCATE_TYPE_ARRAY(double, gen_matrix->N);
    char   *pchk   = BOXING_MEMORY_ALLOCATE_TYPE_ARRAY(char,   gen_matrix->M);
    double *bitpr  = BOXING_MEMORY_ALLOCATE_TYPE_ARRAY(double, gen_matrix->N);
    char *recoverd_block_sd = BOXING_MEMORY_ALLOCATE_TYPE_ARRAY(char, gen_matrix->N);
    char *recoverd_block_hd = BOXING_MEMORY_ALLOCATE_TYPE_ARRAY(char, gen_matrix->N);
    char *data_block = BOXING_MEMORY_ALLOCATE_TYPE_ARRAY(char, gen_matrix->N - gen_matrix->M);
    char *data_block_ptr;

    for (int i = 0; i < blocks; i++)
    {
        /* convert from packed log likelyhood ratio (char)
         * to likelyhood ratio (double)
         */
        for (int bit = 0; bit < gen_matrix->N; bit++)
        {
            lratio[bit] = exp(src[bit]/10.0f);
            recoverd_block_hd[bit] = (lratio[bit] > 1.0f) ? 1 : 0;
        }
        (void)ldpc_decode_prprp(gen_matrix->H, lratio, recoverd_block_sd, pchk, bitpr, ldpc_codec->iterations);

        int bit_alterations = 0;
        for (int bit = 0; bit < gen_matrix->N; bit++)
        {
            bit_alterations += (recoverd_block_hd[bit] != recoverd_block_sd[bit]) ? 1 : 0;
        }
        //extract data
        data_block_ptr = data_block;
        for (int i = gen_matrix->M; i < gen_matrix->N; i++)
        {
            *data_block_ptr++ = recoverd_block_sd[(int)gen_matrix->cols[i]];
        }

        int c = 0;
        for (int i = 0; i < gen_matrix->M; i++)
        {
            c += pchk[i];
        }

        if (c)
        {
            stats->unresolved_errors += bit_alterations;
        }
        else
        {
            stats->resolved_errors += bit_alterations;
        }
        // convert data from bit to byte stream 
        pack_data(data_block, dst, gen_matrix->N - gen_matrix->M);

        dst += ldpc_codec->base.decoded_block_size;
        src += ldpc_codec->base.encoded_block_size;
        //dst += ldpc_codec->base.decoded_block_size; 
    }

    boxing_memory_free(lratio);
    boxing_memory_free(pchk);
    boxing_memory_free(bitpr);
    boxing_memory_free(recoverd_block_sd);
    boxing_memory_free(recoverd_block_hd);
    boxing_memory_free(data_block);

    gvector_swap(data, decoded_data);
    gvector_free(decoded_data);
    return DTRUE;
}
