#ifndef BOXING_BITUTILS_H
#define BOXING_BITUTILS_H

/*****************************************************************************
**
**  Definition of the bit manipulation functions
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

#include "boxing/platform/types.h"

inline uint64_t htobell(uint64_t hostlonglong)
{
    uint64_t value;
    unsigned char *ptr = (unsigned char *)&value;
    *(ptr++) = (unsigned char)((hostlonglong >> 56) & 0xFF);
    *(ptr++) = (unsigned char)((hostlonglong >> 48) & 0xFF);
    *(ptr++) = (unsigned char)((hostlonglong >> 40) & 0xFF);
    *(ptr++) = (unsigned char)((hostlonglong >> 32) & 0xFF);
    *(ptr++) = (unsigned char)((hostlonglong >> 24) & 0xFF);
    *(ptr++) = (unsigned char)((hostlonglong >> 16) & 0xFF);
    *(ptr++) = (unsigned char)((hostlonglong >> 8) & 0xFF);
    *ptr = (unsigned char)((hostlonglong)& 0xFF);
    return value;
}

inline uint32_t htobel(uint32_t hostlong)
{
    uint32_t value;
    unsigned char *ptr = (unsigned char *)&value;
    *(ptr++) = (unsigned char)((hostlong >> 24) & 0xFF);
    *(ptr++) = (unsigned char)((hostlong >> 16) & 0xFF);
    *(ptr++) = (unsigned char)((hostlong >> 8) & 0xFF);
    *ptr = (unsigned char)((hostlong)& 0xFF);
    return value;
}


inline uint16_t htobes(uint16_t hostshort)
{
    uint16_t value;
    unsigned char *ptr = (unsigned char *)&value;
    *(ptr++) = (unsigned char)((hostshort >> 8) & 0xFF);
    *ptr = (unsigned char)((hostshort)& 0xFF);
    return value;
}

inline uint64_t betohll(uint64_t belonglong)
{
    uint64_t value = 0;
    unsigned char *ptr = (unsigned char *)&belonglong;
    value |= ((uint64_t)*(ptr++)) << 56;
    value |= ((uint64_t)*(ptr++)) << 48;
    value |= ((uint64_t)*(ptr++)) << 40;
    value |= ((uint64_t)*(ptr++)) << 32;
    value |= ((uint64_t)*(ptr++)) << 24;
    value |= ((uint64_t)*(ptr++)) << 16;
    value |= ((uint64_t)*(ptr++)) << 8;
    value |= ((uint64_t)*(ptr++));
    return value;
}

inline uint32_t betohl(uint32_t belong)
{
    uint32_t value = 0;
    unsigned char *ptr = (unsigned char *)&belong;
    value |= ((uint32_t)*(ptr++)) << 24;
    value |= ((uint32_t)*(ptr++)) << 16;
    value |= ((uint32_t)*(ptr++)) << 8;
    value |= ((uint32_t)*(ptr++));
    return value;
}

inline uint16_t betohs(uint16_t beshort)
{
    uint16_t value = 0;
    unsigned char *ptr = (unsigned char *)&beshort;
    value |= ((uint16_t)*(ptr++)) << 8;
    value |= ((uint16_t)*(ptr++));
    return value;
}

#define BIT_IS_ON(byte_array, position) (((byte_array)[(position) >> 3] & (0x80 >> ((position) & 7))) > 0)

#define BIT_SET_ON(byte_array, position) *((byte_array) + ((position) >> 3)) |= (0x80 >> ((position)  & 7));
#define BIT_SET_OFF(byte_array, position) *((byte_array) + ((position) >> 3)) &= ~(0x80 >> ((position)  & 7));

#ifdef __cplusplus
}
#endif

#endif
