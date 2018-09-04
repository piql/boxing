#ifndef BOXING_PACKETHEADER_H
#define BOXING_PACKETHEADER_H

/*****************************************************************************
**
**  Definition of packet header functions
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

typedef struct boxing_codec_packet_header_s
{
    boxing_codec                     base;
} boxing_codec_packet_header;

boxing_codec * boxing_codec_packet_header_create(GHashTable * properties, const boxing_config * config);
void           boxing_codec_packet_header_free(boxing_codec *codec);

static const char codec_packet_header_name[] = "PacketHeader";

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
