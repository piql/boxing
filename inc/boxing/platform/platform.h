#ifndef BOXING_PLATFORM_H
#define BOXING_PLATFORM_H

/*****************************************************************************
**
**  Definition of the platform interface - platform dependant functions
**
**  Creation date:  2016/10/10
**  Created by:     Ole Liabo
**
**
**  Copyright (c) 2016 Piql AS. All rights reserved.
**
**  This file is part of the boxing library
**
*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#include "boxing/platform/types.h"

#if defined (BOXING_USE_C99_LIBRARIES) || defined (BOXING_USE_C89_LIBRARIES)
#   include <stdarg.h>
#   include <assert.h>
#   include <stdio.h>
#   include <stdlib.h>
#   include <string.h>
#   if defined (D_OS_WIN32)
#       include <malloc.h>
#   else
#       include <alloca.h>
#   endif
#else
#   define DLOG_DISABLED
#   define assert(expression)
#   ifndef NULL
#       define NULL 0
#   endif

void *malloc(size_t size);
void free(void *ptr);
void *memset(void *s, int c, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void *alloca(size_t size);

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
