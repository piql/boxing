#ifndef BOXING_CORNERMARK_H
#define BOXING_CORNERMARK_H

/*****************************************************************************
**
**  Definition of the corner mark C interface
**
**  Creation date:  2016/08/24
**  Created by:     Ole Liabo
**
**
**  Copyright (c) 2016 Piql AS. All rights reserved.
**
**  This file is part of the boxing library
**
*****************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

//  PROJECT INCLUDES
//
#include    "boxing/math/math.h"

struct boxing_image8_s;

enum boxing_corner_mark_result
{
   BOXING_CORNER_MARK_OK = 0,
   BOXING_CORNER_MARK_TRACKING_ERROR,
   BOXING_CORNER_MARK_CALLBACK_ABORT
};

//============================================================================
//  STRUCT:  frame_corner_marks

typedef struct frame_corner_marks_s
{
    struct boxing_pointi_s top_left;
    struct boxing_pointi_s top_right;
    struct boxing_pointi_s bottom_left;
    struct boxing_pointi_s bottom_right;
} frame_corner_marks;


//============================================================================
//  STRUCT:  boxing_corner_mark_definition

typedef struct boxing_corner_mark_definition_s 
{
    float printable_area_width;
    float printable_area_height;
    float border;
    float border_gap;
    float corner_mark_symbol;
    float corner_mark_gap;
} boxing_corner_mark_definition;


typedef int (*boxing_corner_mark_callback)(void * user, const struct boxing_image8_s * image, boxing_corner_mark_definition * def, boxing_float sampling_rate_x,
    boxing_float sampling_rate_y, frame_corner_marks* corners);

boxing_pointi boxing_corner_mark_dimension(frame_corner_marks* corner_marks);

#define BOXINGLIB_CALLBACK
#ifdef BOXINGLIB_CALLBACK
typedef int (*boxing_corner_mark_complete_cb)(void * user, int * res, frame_corner_marks * corner_marks);
#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
