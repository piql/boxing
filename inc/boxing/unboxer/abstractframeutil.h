#ifndef BOXING_ABSTRACTFRAMEUTIL_H
#define BOXING_ABSTRACTFRAMEUTIL_H

/*****************************************************************************
**
**  Definition of the abstract frame util interface
**
**  Creation date:  2014/12/01
**  Created by:     Hakon Larsson
**
**
**  Copyright (c) 2014 PIQL AS. All rights reserved.
**
**  This file is part of the boxing library
**
*****************************************************************************/

//  PROJECT INCLUDES
//
#include "boxing/image8.h"
#include "boxing/matrix.h"

//  BASE INCLUDES
//
#include "ghash.h"

//  SYSTEM INCLUDES
//
#include "boxing/bool.h"

typedef GHashTable boxing_frame_properties; // of <char *, char *>


//============================================================================
//  CLASS:  boxing_abstract_frame_util
typedef struct boxing_abstract_frame_util_s
{
    DBOOL (*initialize)(struct boxing_abstract_frame_util_s * util, const boxing_frame_properties * properties);

    boxing_matrixf * (*correct_frame_geometry)(struct boxing_abstract_frame_util_s * util,
                                                    const boxing_image8 * frame,
                                                    boxing_matrixf * symbol_location_matrix, 
                                                    boxing_matrixi * sync_point_location_index);


    char * (*serialize)(const struct boxing_abstract_frame_util_s * util);

    void (*deserialize)(struct boxing_abstract_frame_util_s * util, const char * string);

    DBOOL (*learn_from_source_data)(struct boxing_abstract_frame_util_s * util, const boxing_image8 * source_data, const boxing_image8 * sampled_frame, DBOOL clear_old_learning/* = true*/);

} boxing_abstract_frame_util;

//============================================================================



//
//===================================EOF======================================

#endif
