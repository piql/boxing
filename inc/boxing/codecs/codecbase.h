#ifndef BOXING_CODECBASE_H
#define BOXING_CODECBASE_H

/*****************************************************************************
**
**  Definition of the codex base functions
**
**  Creation date:  2014/12/16
**  Created by:     Piql AS
**
**
**  Copyright (c) 2014 Piql AS. All rights reserved.
**
**  This file is part of the boxing library
**
*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "boxing/bool.h"

#include "gvector.h"
#include "g_variant.h"
#include "ghash.h"
#include "boxing/stats.h"
#include "boxing/config.h"
#include "boxing/codecs/codec_cb.h"

#define PARAM_NAME_CODEC_MULTI_FRAME_STRIPE_SIZE    "DataStripeSize"
#define PARAM_NAME_DISTANCE                         "distance"
#define PARAM_NAME_MESSAGE_SIZE                     "messageSize"
#define PARAM_NAME_PARITY_SIZE                      "byteParityNumber"
#define PARAM_NAME_POLYNOM                          "polynom"
#define PARAM_NAME_SEED                             "seed"
#define PARAM_NAME_INTERLEAVING_TYPE_BLOCK          "block"
#define PARAM_NAME_INTERLEAVING_TYPE_FRAME          "frame"
#define PARAM_NAME_SYMBOL_TYPE                      "symboltype"
#define PARAM_NAME_SYMBOL_TYPE_BIT                  "bit"
#define PARAM_NAME_SYMBOL_TYPE_BYTE                 "byte"

struct boxing_codec_s;

typedef DBOOL (*boxing_codec_pencode)(void * codec, gvector * data);
typedef DBOOL (*boxing_codec_pdecode)(void * codec, gvector * data, gvector * erasures, boxing_stats_decode * stats, void* user_data);
typedef DBOOL (*boxing_codec_pset_property)(void * codec, const char * name, const g_variant * value);
typedef void  (*reset_callback)(void *codec);
typedef void  (*free_callback)(struct boxing_codec_s *codec);
typedef DBOOL (*boxing_codec_init_capacity)(struct boxing_codec_s *codec, int size); 

typedef struct boxing_codec_s
{
    int                           is_error_correcting;
    int                           pre_zero_pad_data;
    const char *                  name;
    boxing_codec_pencode          encode;
    boxing_codec_pdecode          decode;
    boxing_codec_pset_property    set_property;
    boxing_codec_init_capacity    init_capacity;
    unsigned int                  decoded_data_size;
    unsigned int                  encoded_data_size;
    unsigned int                  decoded_block_size;
    unsigned int                  encoded_block_size;
    unsigned int                  encoded_symbol_size;
    unsigned int                  decoded_symbol_size;
    unsigned int                  reentrant;
    codec_decode_cb               decode_cb;
    codec_encode_cb               encode_cb;
    reset_callback                reset;
    free_callback                 free;
} boxing_codec;

boxing_codec *  boxing_codec_create(const char *codec_name, GHashTable * properties, const boxing_config * config);
void            boxing_codec_init_base(boxing_codec *codec);
void            boxing_codec_release_base(boxing_codec *codec);
void            boxing_codec_release(boxing_codec *codec);

#ifdef __cplusplus
} /*extern "C" */
#endif

#endif
