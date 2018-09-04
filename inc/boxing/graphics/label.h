#ifndef BOXING_LABEL_H
#define BOXING_LABEL_H

/*****************************************************************************
**
**  Definition of the label interface
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
//  STRUCT:  DLabel
typedef struct boxing_label_s
{
    boxing_component base;

    char * label;
    enum boxing_align alignment;
} boxing_label;

void boxing_label_init(boxing_label * label, const char * text, enum boxing_align alignement);
void boxing_label_set_label(boxing_label * label, const char * text);

//============================================================================

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
