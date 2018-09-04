#ifndef BOXING_BORDER_H
#define BOXING_BORDER_H

/*****************************************************************************
**
**  Definition of the border interface
**
**  Creation date:  2014/12/16
**  Created by:     Haakon Larsson
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

//  PROJECT INCLUDES
//
#include "boxing/graphics/component.h"

//============================================================================
//  STRUCT:  boxing_border
typedef struct boxing_border_s
{
    boxing_component    base;
    boxing_component *  container;
    int                 border_size;
    int                 gap_size;
} boxing_border;

void boxing_border_init(boxing_border * border, int border_size, int gap_size);
void boxing_border_free(boxing_component * border);

//============================================================================
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
