#ifndef BOXING_CALIBRATIONBAR_H
#define BOXING_CALIBRATIONBAR_H

/*****************************************************************************
**
**  Definition of the calibration bar interface
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
//  STRUCT:  DCalibrationBar

typedef struct boxing_calibration_bar_s
{
    boxing_component base;
    int              levels_per_symbol; 
} boxing_calibration_bar;

void boxing_calibration_bar_init(boxing_calibration_bar * bar, int levels_per_symbol);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
