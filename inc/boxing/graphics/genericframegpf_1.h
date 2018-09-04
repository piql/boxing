#ifndef BOXING_GENERICFRAME_GPF_1_H
#define BOXING_GENERICFRAME_GPF_1_H

/*****************************************************************************
**
**  Definition of the dgenericframegpf_1 struct 
**  Generic Preservation Format Version 1.0
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
#include "boxing/graphics/border.h"
#include "boxing/graphics/genericframe.h"

struct boxing_reference_point_s;
struct boxing_reference_bar_s;
struct boxing_content_container_s;
struct boxing_metadata_bar_s;
struct boxing_label_s;
struct boxing_frame_gpf_1_s;

typedef struct boxing_container_impl_1_s
{
    boxing_generic_container      base;
    struct boxing_frame_gpf_1_s * frame;
} boxing_container_impl_1;

typedef struct boxing_container_imeta_1_s
{
    boxing_generic_container      base;
    struct boxing_frame_gpf_1_s * frame;
} boxing_container_imeta_1;

void boxing_container_impl_1_init(boxing_container_impl_1 * container, struct boxing_frame_gpf_1_s *frame);
void boxing_container_imeta_1_init(boxing_container_imeta_1 * container, struct boxing_frame_gpf_1_s *frame);


//============================================================================
//  STRUCT:  boxing_frame_gpf_1

typedef struct boxing_frame_gpf_1_s
{
    boxing_frame                      base;

   
    boxing_border                     base_border;
    struct boxing_reference_point_s * top_left_reference_point;
    struct boxing_reference_point_s * top_right_reference_point;
    struct boxing_reference_point_s * bottom_left_reference_point;
    struct boxing_reference_point_s * bottom_right_reference_point;
    struct boxing_reference_bar_s   * top_reference_bar;
    struct boxing_reference_bar_s   * bottom_reference_bar;
    struct boxing_reference_bar_s   * left_reference_bar;
    struct boxing_reference_bar_s   * right_reference_bar;
    struct boxing_calibration_bar_s * calibration_bar;
    struct boxing_content_container_s* content_container;
    struct boxing_metadata_bar_s    * metadata_bar;
    struct boxing_label_s           * label_system_define;
    struct boxing_label_s           * label_user_define;
                                
    int                           max_levels_per_symbol;
    int                           levels_per_symbol;
    int                           corner_mark_size;
    int                           corner_mark_gap;
    int                           tiles_per_column;
    boxing_container_impl_1       generic_container;
    boxing_container_imeta_1      generic_metadata_container;

    int                           sync_point_h_distance;
    int                           sync_point_v_distance;
    int                           sync_point_h_offset;
    int                           sync_point_v_offset;
    int                           sync_point_radius;
    int                           reference_bar_freq_divider;
    int                           analog_content_symbol_size;
    int                           digital_content_symbol_size;
    int                           reference_bar_sync_distance;
    int                           reference_bar_sync_offset;
} boxing_frame_gpf_1;

//============================================================================

void            boxing_generic_frame_gpf_1_init(boxing_frame_gpf_1 * frame, int width, int height, int border, int border_gap,
                    int corner_mark_size, int corner_mark_gap, int tiles_per_column, int max_levels_per_symbol, int reference_bar_freq_divider,
                    int analog_content_symbol_size, int digital_content_symbol_size, int reference_bar_sync_distance, int reference_bar_sync_offset);
void            boxing_generic_frame_gpf_1_set_size(boxing_frame_gpf_1 * frame, int width, int height);
boxing_pointi   boxing_generic_frame_gpf_1_corner_mark_dimension(boxing_frame_gpf_1 * frame);
int             boxing_generic_frame_gpf_1_corner_mark_gap_size(boxing_frame_gpf_1 * frame);
void            boxing_generic_frame_gpf_1_set_tracker_options(boxing_frame_gpf_1 *frame, int sync_point_h_distance, int sync_point_v_distance,
                    int sync_point_h_offset, int sync_point_v_offset, int sync_point_radius);                       

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
