#ifndef BOXING_TRACKER_H
#define BOXING_TRACKER_H

/*****************************************************************************
**
**  Definition of the frame tracker C interface
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
#include "boxing/unboxer/sampler.h"
#include "boxing/unboxer/cornermark.h"
#include "ghash.h"

struct boxing_tracker_s;

typedef GHashTable* boxing_container_sampler_list;

typedef enum 
{
    BOXING_TRACK_SIMULATED             = 0x0001,
    BOXING_TRACK_REFERENCE_MARKS       = 0x0002,
    BOXING_TRACK_HORIZONTAL_SHIFT      = 0x0004,
    BOXING_TRACK_VERTICAL_SHIFT        = 0x0008,
    BOXING_TRACK_CONTENT_CONTAINER     = 0x0010,
    BOXING_TRACK_METADATA_CONTAINER    = 0x0020,
    BOXING_TRACK_CALIBRATION_BAR       = 0x0040,
    BOXING_TRACK_SYSTEM_HUMAN_READABLE = 0x0080,
    BOXING_TRACK_USER_HUMAN_READABLE   = 0x0100,
    BOXING_TRACK_SYNC_POINTS           = 0x0200,
} Mode;

typedef int  (*boxing_tracker_frame_callback)(struct boxing_tracker_s * tracker, const boxing_image8 * frame);
typedef void (*boxing_tracker_free_callback)(struct boxing_tracker_s * tracker);

//============================================================================
//  STRUCT:  boxing_tracker

typedef struct boxing_tracker_s
{
    boxing_tracker_frame_callback   track_frame;
    boxing_tracker_free_callback    free;
    boxing_corner_mark_callback     track_corner_mark;
    int                             mode;
    boxing_container_sampler_list   container_sampler_list; // Output from track_frame
    boxing_float                    x_sampling_rate; // Output from track_frame
    boxing_float                    y_sampling_rate; // Output from track_frame
    const char*                     type;
#ifdef BOXINGLIB_CALLBACK
    boxing_corner_mark_complete_cb  on_corner_mark_complete;
    void *                          user_data;
#endif
} boxing_tracker;

void             boxing_tracker_init(boxing_tracker * tracker);
void             boxing_tracker_destroy(boxing_tracker * tracker);
boxing_sampler * boxing_tracker_get_container_sampler(struct boxing_tracker_s * tracker, const char * key);
DBOOL            boxing_tracker_is_type(boxing_tracker * tracker, const char* type);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
