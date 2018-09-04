#ifndef BOXING_MEMORY_H
#define BOXING_MEMORY_H

/*****************************************************************************
**
**  Definition of the memory interface
**
**  Creation date:  2016/06/15
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

//  PROJECT INCLUDES
//
#include "boxing/platform/platform.h"

#define BOXING_MEMORY_ALLOCATE_TYPE( type ) (type*)malloc( sizeof( type ) )
#define BOXING_MEMORY_ALLOCATE_TYPE_ARRAY( type, count ) (type*)malloc( sizeof( type ) * (count) )
#define BOXING_MEMORY_ALLOCATE_TYPE_ARRAY_CLEAR( type, count ) (type*)boxing_memory_allocate_and_clear( sizeof( type ) * (count) )
#define BOXING_STACK_ALLOCATE_TYPE_ARRAY( type, count ) (type*)alloca( sizeof( type ) * (count) )
#define BOXING_NULL_POINTER NULL

void*   boxing_memory_allocate(size_t size_in_bytes);
void*   boxing_memory_allocate_and_clear( size_t size_in_bytes );
void    boxing_memory_free(void* pointer_to_memory);
void    boxing_memory_clear(void* pointer_to_memory, size_t size_in_bytes);
void    boxing_memory_copy(void* pointer_to_memory_destination, const void* pointer_to_memory_source, size_t size_in_bytes);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
