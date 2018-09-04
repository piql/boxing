#ifndef BOXING_INTERLEAVING_H
#define BOXING_INTERLEAVING_H

/*****************************************************************************
**
**  Definition of the interleaving functions
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

typedef enum 
{
    BOXING_INTERLEAVING_SYMBOL_BIT,
    BOXING_INTERLEAVING_SYMBOL_BYTE,
} boxing_codec_interleaving_symbol;

typedef struct boxing_codec_interleaving_s
{
    boxing_codec                     base;
    boxing_codec_interleaving_symbol interleaving_symbol;
    uint32_t                         distance;
} boxing_codec_interleaving;

boxing_codec * boxing_interleaving_create(GHashTable * properties, const boxing_config * config);
void           boxing_interleaving_free(boxing_codec *codec);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
