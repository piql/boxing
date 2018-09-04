#ifndef BOXING_LDPCCODEC_H
#define BOXING_LDPCCODEC_H

/*****************************************************************************
**
**  Definition of BCH codec functions
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

static const char codec_ldpc_name[] = "LDPC";

typedef struct boxing_codec_ldpc_s
{
    boxing_codec       base;
    unsigned int       iterations;
    generator_matrix * gen_matrix;
} boxing_codec_ldpc;

boxing_codec * boxing_codec_ldpc_create(GHashTable * properties, const boxing_config * config);
void           boxing_codec_ldpc_free(boxing_codec *codec);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
