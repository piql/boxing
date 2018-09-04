#ifndef BOXING_CRC32_H
#define BOXING_CRC32_H

/*****************************************************************************
**
**  Definition of the CRC 32 functions
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
#include "boxing/math/crc32.h"

typedef struct boxing_codec_crc32_s
{
    boxing_codec  base;
    uint8_t       size;
    uint32_t      polynom;
    uint32_t      seed;
    dcrc32 *      crc_calculator;
    void *        frame_buffer;
} boxing_codec_crc32;

boxing_codec * boxing_crc32_create(GHashTable * properties, const boxing_config * config);
void           boxing_crc32_free(boxing_codec *codec);

static const char codec_crc32_name[] = "CRC32";

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
