#ifndef BOXING_GENERICFRAME_H
#define BOXING_GENERICFRAME_H

/*****************************************************************************
**
**  Definition of the generic frame
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

#include "boxing/graphics/component.h"

#include "boxing/bool.h"

enum boxing_content_type 
{
    BOXING_CONTENT_TYPE_DIGITAL = 0,
    BOXING_CONTENT_TYPE_ANALOG  = 1,
};


//============================================================================
//  STRUCT:  boxing_generic_container

typedef struct boxing_generic_container_s
{
    int           (*capasity)(struct boxing_generic_container_s * container);
    boxing_pointi (*dimension)(struct boxing_generic_container_s * container);
    boxing_pointi (*location)(struct boxing_generic_container_s * container);
    void          (*set_data)(struct boxing_generic_container_s * container, const char * data, int size);
    void          (*set_tile_size)(struct boxing_generic_container_s * container, const boxing_pointi size);
    boxing_pointi (*get_tile_size)(struct boxing_generic_container_s * container);
    boxing_pointi (*get_tile_size_enum)(struct boxing_generic_container_s * container, enum boxing_content_type /* type */);

    boxing_pointi tile_size;
} boxing_generic_container;



void boxing_generic_frame_container_init(boxing_generic_container * container);
void boxing_generic_frame_container_set_tile_size(boxing_generic_container * container, const boxing_pointi size);

struct boxing_tracker_s;


//============================================================================
//  STRUCT:  boxing_frame

typedef struct boxing_frame_s
{
    void                        (*free)(struct boxing_frame_s * frame); // Does not free the actual pointer
    void                        (*render)(struct boxing_frame_s * frame, boxing_painter * painter);
    boxing_pointi               (*size)(const struct boxing_frame_s * frame);
    boxing_generic_container   *(*container)(struct boxing_frame_s * frame);
    boxing_generic_container   *(*metadata_container)(struct boxing_frame_s * frame);
    int                         (*max_levels_per_symbol)(struct boxing_frame_s * frame);
    int                         (*levels_per_symbol)(struct boxing_frame_s * frame);
    void                        (*set_levels_per_symbol)(struct boxing_frame_s * frame, int levels, DBOOL force/* = false*/);
    void                        (*set_system_human_readable)(struct boxing_frame_s * frame, const char * str);
    void                        (*set_user_human_readable)(struct boxing_frame_s * frame, const char * str);
    struct boxing_tracker_s *   (*create_frame_tracker)(struct boxing_frame_s * frame);

    char *                      format;
    char *                      name;
    char *                      short_description;
    char *                      description;
} boxing_frame;

void         boxing_generic_frame_init(boxing_frame * frame);
void         boxing_generic_frame_free(boxing_frame * frame);
const char * boxing_generic_frame_get_format(const boxing_frame * frame);
const char * boxing_generic_frame_get_name(const boxing_frame * frame);
const char * boxing_generic_frame_get_short_description(const boxing_frame * frame);
const char * boxing_generic_frame_get_description(const boxing_frame * frame);
void         boxing_generic_frame_set_format(boxing_frame * frame, const char * format);
void         boxing_generic_frame_set_name(boxing_frame * frame, const char * name);
void         boxing_generic_frame_set_short_description(boxing_frame * frame, const char * name);
void         boxing_generic_frame_set_description(boxing_frame * frame, const char * name);


//============================================================================

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
