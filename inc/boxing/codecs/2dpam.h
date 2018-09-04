#ifndef BOXING_PAM2D_H
#define BOXING_PAM2D_H

/*****************************************************************************
**
**  Definition of the 2D PAM functions
**
**  Creation date:  2017/11/04
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
#include "boxing/codecs/syncpointinserter.h"

typedef struct boxing_codec_2dpam_s
{
    boxing_codec base;
    unsigned int num_data_pixels_per_frame;
    boxing_codec_syncpointinserter *syncpointinserter;
} boxing_codec_2dpam;

static const char codec_2dpam_name[] = "2DPAM";

boxing_codec * boxing_codec_2dpam_create(GHashTable * properties, const boxing_config * config);
void           boxing_codec_2dpam_free(boxing_codec *codec);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
