/* ALLOC.C - Routine to allocate memory and complain if it doesn't work. */

/* Copyright (c) 1995-2012 by Radford M. Neal.
 *
 * Permission is granted for anyone to copy, use, modify, and distribute
 * these programs and accompanying documents for any purpose, provided
 * this copyright notice is retained and prominently displayed, and note
 * is made of any changes made to these programs.  These programs and
 * documents are distributed without any warranty, express or implied.
 * As the programs were written for research purposes only, they have not
 * been tested to the degree that would be advisable in any important
 * application.  All use of these programs is entirely at the user's own
 * risk.
 */

#include "boxing/platform/memory.h"

//#include <stdlib.h>
#include <stdio.h>

#include "alloc.h"

//----------------------------------------------------------------------------
/*!
 *  \brief Calls 'calloc' and exits with error if it fails.
 *
 *  ALLOCATE SPACE AND CHECK FOR ERROR.  Calls 'calloc' to allocate space,
 *  and then displays an error message and exits if the space couldn't be found.
 *
 *  \ingroup unbox
 *  \param[in]  n     Number of elements.
 *  \param[in]  size  Size of each element.
 */

void *chk_alloc(unsigned n, unsigned size)
{
    void *p;

    p = boxing_memory_allocate(n * size);

    if (p == 0)
    {
        fprintf(stderr, "Ran out of memory (while trying to allocate %d bytes)\n",
            n*size);
        exit(1);
    }

    return p;
}
