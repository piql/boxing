#ifndef BOXING_REEDSOLOMON_H
#define BOXING_REEDSOLOMON_H

/*****************************************************************************
**
**  Definition of reel solomon functions
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
#include "rs.h"


typedef struct boxing_codec_reedsolomon_s
{
    boxing_codec    base;
    rs_codec *      rs;
    unsigned int    message_size;
    unsigned int    parity_size;

} boxing_codec_reedsolomon;

boxing_codec * boxing_codec_reedsolomon_create(GHashTable * properties, const boxing_config * config);
void           boxing_codec_reedsolomon_free(boxing_codec *codec);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
