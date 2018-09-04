#ifndef BOXING_CODECDISPATCHER_H
#define BOXING_CODECDISPATCHER_H

/*****************************************************************************
**
**  Definition of the codex dispatcher C interface
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

#include "boxing/codecs/codecbase.h"
#include "boxing/platform/types.h"
#ifndef  D_OS_WIN32
#include <sys/types.h> // For the type off_t
#endif

#define CODEC_DISPATCHER_DATA_CODING_SCHEME "DataCodingScheme"
#define CODEC_DISPATCHER_METADATA_CODING_SCHEME "MetedataCodingScheme"

#define BOXING_CODEC_MODULATION_PAM2 2
#define BOXING_CODEC_MODULATION_PAM4 4
#define BOXING_CODEC_MODULATION_PAM6 6

/*!
 *  \ingroup codecs
 *
 * Boxing codec order types
 */

enum 
{
    BOXING_CODEC_ORDER_ENCODE = 0,
    BOXING_CODEC_ORDER_DECODE = 1,
};

/*!
 *  \ingroup codecs
 *
 * Boxing codec symbol alignment types
 */

enum
{
    BOXING_CODEC_SYMBOL_ALIGNMENT_BIT = 0,
    BOXING_CODEC_SYMBOL_ALIGNMENT_BYTE = 1,
};

typedef struct boxing_codecdispatcher_version_s
{
    int major;
    int minor;
} boxing_codecdispatcher_version;

typedef struct boxing_codecdispatcher_s
{
    gvector                         decode_codecs; 
    gvector                         encode_codecs; 
    int                             order;
    int                             symbol_alignment;
    uint32_t                        packet_size;
    uint8_t                         color_depth;
    const char          *           codeing_scheme;
    const boxing_config *           config;
    boxing_codecdispatcher_version  version;
    int                             multi_frame_size;
} boxing_codecdispatcher;

int boxing_codecdispatcher_get_stripe_size(const boxing_config * config);
DBOOL boxing_codecdispatcher_is_data_striped(const boxing_config * config);

boxing_codecdispatcher * boxing_codecdispatcher_create(uint32_t packet_size, uint32_t modulation_levels, const boxing_config * config, const char * scheme/* = FORWARD_ERROR_CORRECTION_PROCESS*/);
void  boxing_codecdispatcher_callback_setup(boxing_codecdispatcher * codec_dispatcher, const boxing_codec_cb * callbacks);
void  boxing_codecdispatcher_free(boxing_codecdispatcher * dispatcher);
DBOOL boxing_codecdispatcher_encode(boxing_codecdispatcher *dispatcher, gvector * data);
DBOOL boxing_codecdispatcher_encode_step(boxing_codecdispatcher *dispatcher, gvector * data, int step);
DBOOL boxing_codecdispatcher_encode_step_codec(boxing_codec * codec, gvector * data);
DBOOL boxing_codecdispatcher_decode(boxing_codecdispatcher *dispatcher, gvector * data, boxing_stats_decode *stats, void* user_data);
DBOOL boxing_codecdispatcher_decode_step(boxing_codecdispatcher *dispatcher, gvector * data, gvector * erasures, int step, boxing_stats_decode *stats, void* user_data);
DBOOL boxing_codecdispatcher_decode_step_codec(boxing_codec * codec, gvector * data, gvector * erasures, boxing_stats_decode *stats, void* user_data);

void  boxing_codecdispatcher_reset(boxing_codecdispatcher *dispatcher);

unsigned int boxing_codecdispatcher_get_coding_steps(boxing_codecdispatcher *dispatcher);
boxing_codec * boxing_codecdispatcher_get_encode_codec(boxing_codecdispatcher *dispatcher, int step);
boxing_codec * boxing_codecdispatcher_get_decode_codec(boxing_codecdispatcher *dispatcher, int step);

uint32_t boxing_codecdispatcher_get_encoded_packet_size(boxing_codecdispatcher *dispatcher);
uint32_t boxing_codecdispatcher_get_encoded_packet_size_step(boxing_codecdispatcher *dispatcher, int step);
uint32_t boxing_codecdispatcher_get_decoded_packet_size(boxing_codecdispatcher *dispatcher);
uint32_t boxing_codecdispatcher_get_decoded_packet_size_step(boxing_codecdispatcher *dispatcher, int step);
uint32_t boxing_codecdispatcher_get_bytes_per_frame(boxing_codecdispatcher *dispatcher);

int      boxing_codecdispatcher_version_cmp(const boxing_codecdispatcher_version * a, const boxing_codecdispatcher_version *b);

#if defined ( D_OS_WIN32 )
uint32_t boxing_codecdispatcher_get_data_frames(boxing_codecdispatcher *dispatcher, __int64 file_size);
#else
uint32_t boxing_codecdispatcher_get_data_frames(boxing_codecdispatcher *dispatcher, off_t file_size);
#endif

extern const boxing_codecdispatcher_version boxing_codecdispatcher_version_1_0;
extern const boxing_codecdispatcher_version boxing_codecdispatcher_version_0_9;
#define BOXING_CODEC_DISPATCHER_1_0     boxing_codecdispatcher_version_1_0
#define BOXING_CODEC_DISPATCHER_PRE_1_0 boxing_codecdispatcher_version_0_9


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
