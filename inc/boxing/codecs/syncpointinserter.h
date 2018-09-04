#ifndef BOXING_SYNCPOINTINSERTER_H
#define BOXING_SYNCPOINTINSERTER_H

/*****************************************************************************
**
**  Definition of the synchronization points functions
**
**  Creation date:  2014/12/16
**  Created by:     Piql AS
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

#include "boxing/codecs/codecbase.h"

typedef struct boxing_codec_syncpointinserter_s
{
    boxing_codec    base;
    int             property_sync_point_radius_m;
    boxing_pointi   property_image_size_m;
    int             property_sync_point_h_distance_m;
    int             property_sync_point_v_distance_m;
    int             property_sync_point_h_offset_m;
    int             property_sync_point_v_offset_m;
    gvector         property_sync_point_areas_m; // of boxing_recti
    gvector         property_sync_point_centers_m; // of boxing_pointi
    int             property_data_orientation_m; // horizontal = 1, vertical = 2
    int             property_value_sync_point_background_m;
    int             property_value_sync_point_foreground_m;
    int             sync_point_pixel_count_m;
    int             num_bits_per_pixel_m;
    DBOOL           is_valid;
    char *          bitarray_sync_point_background;
    char *          bitarray_sync_point_foreground;
} boxing_codec_syncpointinserter;

boxing_codec * boxing_codec_syncpointinserter_create(GHashTable * properties, const boxing_config * config);
void           boxing_codec_syncpointinserter_free(boxing_codec *codec);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
