#ifndef BOXING_BICUBICSAMPLER_H
#define BOXING_BICUBICSAMPLER_H

/*****************************************************************************
**
**  Definition of bicubic interpolation interface
**
**  Creation date:  2017/03/31
**  Created by:     Alexander Silokhin
**
**
**  Copyright (c) 2017 Piql AS. All rights reserved.
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

boxing_sampler * boxing_bicubicsampler_create(int width, int height);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
