#ifndef BOXING_CRC64_H
#define BOXING_CRC64_H

/*****************************************************************************
**
**  Definition of the CRC64 functions
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
#include "boxing/math/crc64.h"
#include "boxing/platform/types.h"

typedef struct boxing_codec_crc64_s
{
    boxing_codec  base;
    uint8_t       size;
    uint64_t      polynom;
    uint64_t      seed;
    dcrc64 *      crc_calculator;
    void *        frame_buffer;
} boxing_codec_crc64;

boxing_codec * boxing_crc64_create(GHashTable * properties, const boxing_config * config);
void           boxing_crc64_free(boxing_codec *codec);

static const char codec_crc64_name[] = "CRC64";

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
