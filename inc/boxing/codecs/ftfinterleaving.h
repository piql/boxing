#ifndef BOXING_FTFINTERLEAVING_H
#define BOXING_FTFINTERLEAVING_H

/*****************************************************************************
**
**  Definition of FTF interleaving functions
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

typedef struct boxing_codec_ftf_interleaving_s
{
    boxing_codec                     base;
    uint32_t                         distance;
    uint32_t                         preload_frames;
    GList *                          encode_buffer;
    GList *                          decode_buffer;
} boxing_codec_ftf_interleaving;

boxing_codec * boxing_ftf_interleaving_create(GHashTable * properties, const boxing_config * config);
void           boxing_ftf_interleaving_free(boxing_codec *codec);

static const char codec_ftf_interleaving_name[] = "FTFInterleaving";

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
