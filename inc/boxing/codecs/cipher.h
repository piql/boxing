#ifndef BOXING_CIPHER_H
#define BOXING_CIPHER_H

/*****************************************************************************
**
**  Definition of the cipher functions
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

typedef struct boxing_codec_cipher_s
{
    boxing_codec base;
    DBOOL        auto_key;
    int          ones[256];
    uint32_t     key;
} boxing_codec_cipher;

boxing_codec * boxing_codec_cipher_create(GHashTable * properties, const boxing_config * config);
void           boxing_codec_cipher_free(boxing_codec *codec);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
