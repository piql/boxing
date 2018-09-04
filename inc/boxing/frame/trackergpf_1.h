#ifndef BOXING_TRACKERGPF_1_H
#define BOXING_TRACKERGPF_1_H

/*****************************************************************************
**
**  Definition of the frame tracker Gpf_1 interface
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
#include "boxing/string.h"
#include "trackergpf.h"
#include "boxing/graphics/genericframegpf_1.h"
#include "boxing/image8.h"
#include "boxing/unboxer/sampler.h"
#include "boxing/frame/trackercbgpf_1.h"

#define BOXING_TRACKER_GPF1_NAME ("GPF1")

//============================================================================
//  STRUCT:  boxing_coordmapper

typedef struct boxing_coordmapper_s
{
    boxing_pointf vector_top;
    boxing_pointf vector_bottom;
    boxing_pointf vector_left;
    boxing_pointf top_left;
    boxing_pointf top_left_offset;
    boxing_float  horizontal_distance;
    boxing_float  vertical_distance;
} boxing_coordmapper;

//============================================================================
//  STRUCT:  boxing_tracker_gpf_1

typedef struct boxing_tracker_gpf_1_s
{
    boxing_tracker_gpf     base;
    boxing_pointi          frame_dimension;
    boxing_pointi          corner_mark_dimension;
    int                    corner_mark_gap_size;
    boxing_float           avg_max;
    boxing_float           avg_min;
    boxing_sampler *       left_reference_bar_sampler;
    boxing_sampler *       right_reference_bar_sampler; 
    boxing_sampler *       top_reference_bar_sampler;
    boxing_sampler *       bottom_reference_bar_sampler;
    boxing_sampler *       top_left_corner_mark_sampler;
    boxing_sampler *       top_right_corner_mark_sampler;
    boxing_sampler *       bottom_left_corner_mark_sampler;
    boxing_sampler *       bottom_right_corner_mark_sampler;
    boxing_matrixi         syncpoint_index;
    int                    tile_size;
    boxing_frame_gpf_1 *   frame;

    // variables needed to map coordinates
    int                    horizontal_distance;
    int                    vertical_distance;
    int                    x_offset;
    int                    y_offset;
    boxing_coordmapper     coordinate_mapper;
    boxing_calculate_sampling_locations_cb calculate_sampling_location;
    boxing_track_vertical_shift_cb         track_vertical_shift;
    boxing_correct_frame_geometry_cb       correct_frame_geometry;
} boxing_tracker_gpf_1;


boxing_tracker_gpf_1 * boxing_tracker_gpf_1_create(boxing_frame_gpf_1 * generic_frame);

DBOOL boxing_calculate_sampling_location(
    void* user, boxing_tracker_gpf_1 * tracker,
    const boxing_pointf * left_bar_points, const int left_bar_points_size,
    const boxing_pointf * right_bar_points, const int right_bar_points_size,
    const boxing_pointf * top_bar_points, const int top_bar_points_size,
    const boxing_pointf * bottom_bar_points, const int bottom_bar_points_size,
    const boxing_float * left_offset_xs, const boxing_float * right_offset_xs, int offsets_size,
    int width, int vertical_barwidth, const frame_corner_marks* corner_marks );

DBOOL boxing_track_vertical_shift(
    void* user, boxing_tracker_gpf_1* tracker, const boxing_image8* input_image );

//============================================================================

#ifdef __cplusplus
} /* extern "C" */
#endif


#endif
