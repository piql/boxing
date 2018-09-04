#ifndef BOXING_MODULATOR_H
#define BOXING_MODULATOR_H

/*****************************************************************************
**
**  Definition of the modulator functions
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

typedef struct boxing_codec_modulator_s
{
    boxing_codec base;
    unsigned int num_data_pixels_per_frame;
    unsigned int num_bits_per_pixel;
} boxing_codec_modulator;

boxing_codec * boxing_codec_modulator_create(GHashTable * properties, const boxing_config * config);
void           boxing_codec_modulator_free(boxing_codec *codec);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
