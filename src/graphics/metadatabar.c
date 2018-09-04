/*****************************************************************************
**
**  Implementation of the metadata_bar interface
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
#include    "boxing/graphics/metadatabar.h"

//  DEFINES
//

#define SMEMBER(member) (((boxing_metadata_bar*)bar)->member)

//  PRIVATE INTERFACE
//

static void set_size(boxing_component * bar, int width, int height);
static void update_data_capasity(boxing_metadata_bar * bar);
static void render(boxing_component * bar, boxing_painter * painter);


/*! 
  * \addtogroup graphics
  * \{
  */


//----------------------------------------------------------------------------
/*!
 *  \struct  boxing_metadata_bar_s  metadatabar.h
 *  \brief   Metadata bar data storage structure.
 *  
 *  \param base              Base boxing_component instance.
 *  \param tiles_per_column  Tiles per column.
 *  \param tiles_per_row     Tiles per row.
 *  \param data_capasity     Data capacity.
 *  \param tile_size         Tile size.
 *  \param data_size         Data size.
 *  \param data              Data string.
 *
 *  Structure for storing metadata bar data.
 */


// PUBLIC METADATA BAR FUNCTIONS
//

//----------------------------------------------------------------------------
/*!
 *  \brief Initializes all structure data.
 *
 *  Initializes tile size value with the input value and other data with default values.
 *
 *  \param[in] bar        Pointer to the boxing_metadata_bar structure.
 *  \param[in] tile_size  Tile size.
 */

void boxing_metadata_bar_init(boxing_metadata_bar * bar, int tile_size)
{
    boxing_component_init((boxing_component *)bar, NULL);
    boxing_component_set_size((boxing_component *)bar, 0, 0); // not needed?
    
    bar->tile_size = tile_size;
    bar->data_size = 0;
    bar->data = NULL;

    bar->base.set_size = set_size;
    bar->base.render = render;
}


//----------------------------------------------------------------------------
/*!
 *  \brief Set new data.
 *
 *  Set new data according to the input data string and data size value.
 *
 *  \param[out]  bar        Pointer to the boxing_metadata_bar structure.
 *  \param[in]   data       Data string.
 *  \param[in]   data_size  Data size.
 */

void boxing_metadata_bar_set_data(boxing_metadata_bar * bar, const char * data, int data_size)
{
    bar->data = data;
    bar->data_size = data_size;
}


//----------------------------------------------------------------------------
/*!
 *  \brief Set new tile size.
 *
 *  Set new tile size function description.
 *
 *  \param[out]  bar   Pointer to the boxing_metadata_bar structure.
 *  \param[in]   size  Data size.
 */

void boxing_metadata_bar_set_tile_size(boxing_metadata_bar * bar, int size)
{
    SMEMBER(tile_size) = size;
    update_data_capasity(bar);
}


//----------------------------------------------------------------------------
/*!
  * \} end of graphics group
  */


// PRIVATE METADATA BAR FUNCTIONS
//

static void render(boxing_component * bar, boxing_painter * painter)
{
    int data_size = (SMEMBER(data_size) < SMEMBER(data_capasity)) ? SMEMBER(data_size) : SMEMBER(data_capasity);
    int col = 0;
    int row = 0;
    const char * data_pointer = SMEMBER(data);
    int foreground_color = boxing_component_get_foreground_color(bar);
    while (data_size)
    {
        if (*data_pointer)
            painter->fill_rect(painter, col*SMEMBER(tile_size), row*SMEMBER(tile_size), SMEMBER(tile_size), SMEMBER(tile_size), foreground_color);
        row = (row + 1) % SMEMBER(tiles_per_column);
        if (row == 0)
        {
            col++;
        }
        data_pointer++;
        data_size--;
    }
    boxing_component_render(bar, painter);
}

static void set_size(boxing_component * bar, int width, int height)
{
    boxing_component_set_size((boxing_component *)bar, width, height);
    update_data_capasity((boxing_metadata_bar*)bar);
}

static void update_data_capasity(boxing_metadata_bar * bar)
{
    bar->tiles_per_column = bar->base.size.y/bar->tile_size;
    bar->tiles_per_row = bar->base.size.x/bar->tile_size;
    bar->data_capasity = bar->tiles_per_column*bar->tiles_per_row;
}
