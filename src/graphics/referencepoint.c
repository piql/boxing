/*****************************************************************************
**
**  Implementation of the referencepoint class
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

//  PROJECT INCLUDES
//
#include    "boxing/graphics/referencepoint.h"

//  DEFINES
//

#define SMEMBER(member) (((boxing_reference_point*)point)->member)

//  PRIVATE INTERFACE
//

static void render(boxing_component * point, boxing_painter * painter);


/*! 
  * \addtogroup graphics
  * \{
  */


//----------------------------------------------------------------------------
/*!
 *  \struct     boxing_reference_point_s  referencepoint.h
 *  \brief      Reference point data storage.
 *  
 *  \param base      Base boxing_component structure instance.
 *  \param gap_size  Gap size.
 *
 *  Reference point data storage structure description.
 */


// PUBLIC REFERENCE POINT FUNCTIONS
//

//----------------------------------------------------------------------------
/*!
 *  \brief Initializes all structure data.
 *
 *  Initializes base structure data with default values and gap size with input value.
 *
 *  \param[in] point     Pointer to the boxing_reference_point structure.
 *  \param[in] gap_size  Gap size.
 */

void boxing_reference_point_init(boxing_reference_point * point, int gap_size)
{
    boxing_component_init((boxing_component*)point, NULL);
    point->base.render = render;
    point->gap_size = gap_size;
}


//----------------------------------------------------------------------------
/*!
  * \} end of graphics group
  */


// PRIVATE REFERENCE POINT FUNCTIONS
//

static void render(boxing_component * point, boxing_painter * painter)
{
    int tile_size = ((point->size.x > point->size.y) ? point->size.x: point->size.y - (SMEMBER(gap_size) * 2)) / 2;
    painter->fill_rect(painter, SMEMBER(gap_size) + tile_size, SMEMBER(gap_size), tile_size, tile_size, boxing_component_get_foreground_color(point));
    painter->fill_rect(painter, SMEMBER(gap_size), SMEMBER(gap_size) + tile_size, tile_size, tile_size, boxing_component_get_foreground_color(point));
    boxing_component_render(point, painter);
}
