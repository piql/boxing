#ifndef BOXING_REFERENCEPOINT_H
#define BOXING_REFERENCEPOINT_H

/*****************************************************************************
**
**  Definition of the reference point interface
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
//  CLASS:  boxing_reference_point
typedef struct boxing_reference_point_s
{
    boxing_component    base;
    int                 gap_size;
} boxing_reference_point;

void boxing_reference_point_init(boxing_reference_point * point, int gap_size);

//============================================================================

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
