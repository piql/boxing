#ifndef BOXING_SYMBOLCONVERTER_H
#define BOXING_SYMBOLCONVERTER_H

/*****************************************************************************
**
**  Definition of the symbol converter codec
**
**  Creation date:  2017/09/27
**  Created by:     Piql AS
**
**
**  Copyright (c) 2017 Piql AS. All rights reserved.
**
**  This file is part of the boxing library
**
*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "boxing/codecs/codecbase.h"
#include "boxing/platform/types.h"

typedef struct boxing_codec_symbol_converter_s
{
    boxing_codec base;
    unsigned int encoded_levels_per_symbol;
    unsigned int decoded_levels_per_symbol;
} boxing_codec_symbol_converter;

boxing_codec * boxing_codec_symbol_converter_create(GHashTable * properties, const boxing_config * config);
void           boxing_codec_symbol_converter_free(boxing_codec *codec);

static const char codec_symbol_converter_name[] = "SymbolConverter";

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
