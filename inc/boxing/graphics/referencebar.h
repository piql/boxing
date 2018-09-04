#ifndef BOXING_REFERENCEBAR_H
#define BOXING_REFERENCEBAR_H

/*****************************************************************************
**
**  Definition of the reference bar interface
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
//  CLASS:  DReferenceBar

typedef struct boxing_reference_bar_s
{
    boxing_component  base;
    enum boxing_align alignment; 
    int               quiet_zone_size;
    int               reference_bar_freq_divider;
    int               reference_bar_sync_distance;
    int               reference_bar_sync_offset;
} boxing_reference_bar;

void boxing_reference_bar_init(boxing_reference_bar * bar, enum boxing_align alignment, int reference_bar_freq_divider, int reference_bar_sync_distance, int reference_bar_sync_offset);

//============================================================================

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
