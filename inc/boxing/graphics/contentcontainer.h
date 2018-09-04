#ifndef BOXING_CONTENTCONTAINER_H
#define BOXING_CONTENTCONTAINER_H

/*****************************************************************************
**
**  Definition of the content container interface
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
//  STRUCT:  DContentContainer
typedef struct boxing_content_container_s
{
    boxing_component base;

    int          data_capasity;
    int          data_size; 
    const char * data;
    int          symbol_size;
} boxing_content_container;

void boxing_content_container_init(boxing_content_container *container);
void boxing_content_container_set_data(boxing_content_container *container, const char * data, int data_size);
void boxing_content_container_set_symbol_size(boxing_content_container *container, int size);

//============================================================================

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
