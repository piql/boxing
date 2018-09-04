#ifndef BOXING_AREASAMPLER_H
#define BOXING_AREASAMPLER_H

/*****************************************************************************
**
**  Definition of the boxing_areasampler struct
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
#include "boxing/unboxer/sampler.h"

//============================================================================
//  struct:  boxing_areasampler

typedef struct boxing_areasampler_s
{
    boxing_sampler base;
    int radius;
} boxing_areasampler;

//============================================================================

boxing_sampler * boxing_areasampler_create(int width, int height);
void boxing_areasampler_set_radius(boxing_areasampler * sampler, int radius);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
