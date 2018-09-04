#ifndef BOXING_METADATABAR_H
#define BOXING_METADATABAR_H

/*****************************************************************************
**
**  Definition of the metadata bar interface
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
//  STRUCT:  DMetadataBar

typedef struct boxing_metadata_bar_s
{
    boxing_component    base;
    int                 tiles_per_column;
    int                 tiles_per_row;
    int                 data_capasity;
    int                 tile_size;
    int                 data_size; 
    const char *        data;
} boxing_metadata_bar;

void boxing_metadata_bar_init(boxing_metadata_bar * bar, int tile_size);
void boxing_metadata_bar_set_data(boxing_metadata_bar * bar, const char * data, int data_size);
void boxing_metadata_bar_set_tile_size(boxing_metadata_bar * bar, int tile_size);

//============================================================================

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
