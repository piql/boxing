#ifndef BOXING_COMPONENT_H
#define BOXING_COMPONENT_H

/*****************************************************************************
**
**  Definition of the component interface
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
#include "boxing/graphics/painter.h"
#include "gvector.h"

enum boxing_align
{
    BOXING_ALIGN_HORIZONTAL = 0,
    BOXING_ALIGN_VERTICAL = 1,
};

//============================================================================
//  STRUCT:  boxing_component

typedef struct boxing_component_s
{
    void (*add)(struct boxing_component_s *component, struct boxing_component_s * child);
    void (*render)(struct boxing_component_s *component, boxing_painter * painter);
    void (*set_size)(struct boxing_component_s *component, int width, int height);
    void (*free)(struct boxing_component_s *component); // destructor, not frees the pointer passed

    gvector children; // of struct boxing_component_*
    boxing_pointi pos;
    boxing_pointi  size;
    int background_color;
    int foreground_color;
    struct boxing_component_s * parent;
    struct boxing_component_s * peer;
} boxing_component;

void          boxing_component_init(boxing_component * component, boxing_component * parent);
boxing_pointi boxing_component_absolute_location(const boxing_component * component);
void          boxing_component_free(boxing_component * component);
int           boxing_component_get_background_color(const struct boxing_component_s * component);
int           boxing_component_get_foreground_color(const struct boxing_component_s * component);
void          boxing_component_set_size(struct boxing_component_s * component, int width, int height);
void          boxing_component_render(struct boxing_component_s * component, boxing_painter * painter);
void          boxing_component_add(struct boxing_component_s * component, struct boxing_component_s * child);

//============================================================================

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
