#ifndef BOXING_SAMPLER_H
#define BOXING_SAMPLER_H

/*****************************************************************************
**
**  Definition of the sampler interface
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
#include "boxing/image8.h"
#include "boxing/matrix.h"

extern const char * BOXING_SAMPLE_CONTAINER_CONTENT  ;
extern const char * BOXING_SAMPLE_CONTAINER_METADATA ;
extern const char * BOXING_SAMPLE_CORNERMARKS        ;
extern const char * BOXING_SAMPLE_BAR_REFERENCE      ;
extern const char * BOXING_SAMPLE_BAR_CALIBRATION    ;
extern const char * BOXING_SAMPLE_HORIZONTALSHIFTS   ;

//============================================================================
//  STRUCT:  boxing_sampler

typedef struct boxing_sampler_s
{
    boxing_image8 * (*sample)(struct boxing_sampler_s * sampler, const boxing_image8 * frame);
    void            (*free)(struct boxing_sampler_s * sampler);

    boxing_matrixf     location_matrix;
    DBOOL              state;
} boxing_sampler;

void boxing_sampler_init(boxing_sampler * sampler, int width, int height);
void boxing_sampler_free(boxing_sampler * sampler);
void boxing_sampler_destroy(boxing_sampler * sampler);

//============================================================================

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
