#ifndef BOXING_TRACKERGPF_1CB_H
#define BOXING_TRACKERGPF_1CB_H

/*****************************************************************************
**
**  Definition of the frame tracker Gpf_1 call back interface
**
**  Creation date:  2017/06/28
**  Created by:     Haakon Larsson
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
#include "boxing/image8.h"
#include "boxing/matrix.h"
#include "boxing/unboxer/cornermark.h"


typedef struct correct_frame_geometry_properties_s
{
    boxing_float sync_point_search_radius;
    DBOOL        sync_point_center_is_bright;
    boxing_float sync_point_max_allowed_variation;
} correct_frame_geometry_properties;


typedef boxing_matrixf* (*boxing_correct_frame_geometry_cb)(
    void* user, const boxing_image8 * image, boxing_matrixf *symbol_location_matrix,
    const boxing_matrixi *sync_point_location_index,
    const correct_frame_geometry_properties * properties);

struct boxing_tracker_gpf_1_s; //Forward declaration

typedef DBOOL( *boxing_calculate_sampling_locations_cb )(
    void* user, struct boxing_tracker_gpf_1_s * tracker,
    const boxing_pointf * left_bar_points, const int left_bar_points_size,
    const boxing_pointf * right_bar_points, const int right_bar_points_size,
    const boxing_pointf * top_bar_points, const int top_bar_points_size,
    const boxing_pointf * bottom_bar_points, const int bottom_bar_points_size,
    const boxing_float * left_offset_xs, const boxing_float * right_offset_xs, int offsets_size,
    int width, int vertical_barwidth,
    const frame_corner_marks* corner_marks);

typedef DBOOL( *boxing_track_vertical_shift_cb )(
    void* user, struct boxing_tracker_gpf_1_s* tracker,
    const boxing_image8* input_image);

//============================================================================

#ifdef __cplusplus
} /* extern "C" */
#endif


#endif
