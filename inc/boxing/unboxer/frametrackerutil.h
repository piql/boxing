#ifndef BOXING_FRAMETRACKERUTIL_H
#define BOXING_FRAMETRACKERUTIL_H

/*****************************************************************************
**
**  Definition of frame tracker utility functions
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
#include "boxing/utils.h"
#include "boxing/unboxer/cornermark.h"

enum BOXING_TRACKERUTIL_SCAN_DIRECTION 
{
    BOXING_TRACKERUTIL_SCAN_DIRECTION_LEFT_TO_RIGHT = 0,
    BOXING_TRACKERUTIL_SCAN_DIRECTION_RIGHT_TO_LEFT
};

boxing_pointf boxing_frame_tracker_util_find_h_reference_bar_edge(const boxing_image8 * image, const boxing_pointi start, const boxing_pointi stop, boxing_float x_sampling_rate, boxing_float y_sampling_rate);
void          boxing_frame_tracker_util_track_vertical_border(const boxing_image8 * image, const boxing_pointi * from, const boxing_pointi * to, boxing_float * border_location, int scan_direction, boxing_float x_sampling_rate);
void          boxing_frame_tracker_util_calculate_average_maxmin(const boxing_image8 * image, const boxing_pointi *const * corner_marks, int corner_marks_size, boxing_float x_sampling_rate, boxing_float y_sampling_rate, boxing_float * avg_max, boxing_float * avg_min);
DBOOL         boxing_frame_tracker_util_track_reference_bar(const boxing_image8 * image, boxing_pointf *sample_start, boxing_pointf *sample_end,
                                boxing_pointf * bar_points, int bar_points_size, boxing_pointf * reference_point, int perpendicular_samples);
DBOOL         boxing_frame_tracker_util_find_vertical_border(const boxing_image8 * image, const boxing_pointi *from, int lenght, boxing_pointi *border);
DBOOL         boxing_frame_tracker_util_find_horizontal_border(const boxing_image8 * image, const boxing_pointi *from, int lenght, boxing_pointi *border);
boxing_pointi boxing_frame_tracker_util_find_corner_mark(const boxing_image8 * image, boxing_pointi location, boxing_pointi dimension, boxing_float x_sampling_rate, boxing_float y_sampling_rate);
DBOOL         boxing_frame_tracker_util_validate_corner_mark(boxing_pointi * location, boxing_pointi * dimension, const boxing_image8 * image);
void          boxing_frame_tracker_util_add_displacement(const boxing_matrixf * displacement_matrix, boxing_matrixf * point_model);
DBOOL         boxing_frame_tracker_util_find_frame(const boxing_image8 * image, frame_corner_marks * corner_marks, boxing_float x_sampling_rate, boxing_float y_sampling_rate);

#ifdef __cplusplus
} /* extern "C" */
#endif

//============================================================================


#endif
