/*****************************************************************************
**
**  Definition of platform spesific functions
**
**  Creation date:  2016/10/14
**  Created by:     Ole Liabo
**
**
**  Copyright (c) 2016 Piql AS. All rights reserved.
**
**  This file is part of the boxing library
**
*****************************************************************************/

//  PROJECT INCLUDES
//
#include "boxing/platform/platform.h"


/*! 
  * \ingroup platform
  * \{
  */


//----------------------------------------------------------------------------
/*!
 *  \fn  void *malloc(size_t size)
 *  \brief Allocate dynamic memory
 *
 *  malloc() allocates size bytes and returns a pointer to the allocated memory.  
 *  The memory is not cleared.  If size is 0, then malloc() returns either NULL,  
 *  or  a  unique  pointer value that can later be successfully passed to free().
 *
 *  \param  size   Size of memory buffer to allocate in bytes.
 *  \return NULL or unique pointer
 */

//----------------------------------------------------------------------------
/*!
 *  \fn  void free(void *ptr)
 *  \brief Free dynamic memory
 *
 *  free() frees the memory space pointed to by ptr, which must have been 
 *  returned by a previous call to malloc().  Otherwise, or if free(ptr) has 
 *  already been called before, undefined behavior occurs. If ptr is NULL, no 
 *  operation is performed.
 *
 *  \param  ptr   Unique pointer to free.
 */

//----------------------------------------------------------------------------
/*!
 *  \fn  void *memset(void *s, int c, size_t n)
 *  \brief Fill memory with a constant byte
 *
 *  The  memset() function fills the first n bytes of the memory area pointed 
 *  to by s with the constant byte c.
 *
 *  \param  s   Pointer to memory area.
 *  \param  c   Constant byte 
 *  \param  n   Number of bytes to set.
 *  \return A pointer to the memory area s.
 */

//----------------------------------------------------------------------------
/*!
 *  \fn void *memcpy(void *dest, const void *src, size_t n)
 *  \brief Copy memory area
 *
 *  The memcpy() function copies n bytes from memory area src to memory area 
 *  dest. The memory areas should not overlap. 
 *
 *  \param  dest   Pointer to destination memory area.
 *  \param  src    Pointer to source memory area. 
 *  \param  n      Number of bytes to copy.
 *  \return A pointer to dest.
 */

//----------------------------------------------------------------------------
/*!
 *  \fn void *alloca(size_t size)
 *  \brief Allocate memory that is automatically freed
 *
 *  The alloca() function allocates size bytes of space in the stack frame of 
 *  the caller. This temporary space is automatically freed when the function 
 *  that called alloca() returns to its caller. 
 *
 *  \param  size   Size of memory buffer to allocate in bytes.
 *  \return NULL or unique pointer
 */


//----------------------------------------------------------------------------
/*!
  * \} end of platform group
  */


typedef int remove_iso_compilers_warning; // Unused type definition to avoid warnings - ISO C requires a translation unit to contain at least one declaration
