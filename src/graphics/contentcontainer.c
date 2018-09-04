/*****************************************************************************
**
**  Implementation of the contentcontainer interface
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
#include "boxing/graphics/contentcontainer.h"

//  DEFINES
//

#define SMEMBER(member) (((boxing_content_container*)container)->member)

//  PRIVATE INTERFACE
//

static void set_size(boxing_component *container, int width, int height);
static void render(boxing_component *container, boxing_painter * painter);


/*! 
  * \addtogroup graphics
  * \{
  */


//----------------------------------------------------------------------------
/*!
 *  \struct     boxing_content_container_s  contentcontainer.h
 *  \brief      Structure for storing boxing content conteiner data.
 *  
 *  \param base           Boxing component base instance.
 *  \param data_capasity  Data capacity.
 *  \param data_size      Data size.
 *  \param data           Data string.
 *  \param symbol_size    Symbol size.
 *
 *  Structure for storing boxing content conteiner data.
 */


// PUBLIC CONTENT CONTAINER FUNCTIONS
//

//----------------------------------------------------------------------------
/*!
 *  \brief Initializes all structure pointers and variables with default values.
 *
 *  Initializes all structure pointers and variables with default values.
 *
 *  \param[in]  container  Pointer to the boxing_content_container structure.
 */

void boxing_content_container_init(boxing_content_container * container)
{
    boxing_component_init((boxing_component*)container, NULL);

    container->base.set_size = set_size;
    container->base.render = render;
    container->data_size = 0;
    container->data = NULL;
    container->symbol_size = 1;
}


//----------------------------------------------------------------------------
/*!
 *  \brief Sets the new data to the content conteiner.
 *
 *  Sets the new data to the content conteiner.
 *
 *  \param[in]  container  Pointer to the boxing_content_container structure.
 *  \param[in]  data       Data string.
 *  \param[in]  data_size  Data size.
 */

void boxing_content_container_set_data(boxing_content_container * container, const char * data, int data_size)
{
    container->data = data;
    container->data_size = data_size;
}


//----------------------------------------------------------------------------
/*!
 *  \brief Sets the new symbol size in the content conteiner.
 *
 *  Sets the new symbol size in the content conteiner.
 *
 *  \param[in]  container  Pointer to the boxing_content_container structure. 
 *  \param[in]  size       New symbol size.
 */

void boxing_content_container_set_symbol_size(boxing_content_container *container, int size)
{
    if(size < 1)
        SMEMBER(symbol_size) = 1;
    else
        SMEMBER(symbol_size) = size;
    SMEMBER(data_capasity) = (container->base.size.x/SMEMBER(symbol_size))*(container->base.size.y/SMEMBER(symbol_size));
}


//----------------------------------------------------------------------------
/*!
  * \} end of graphics group
  */


// PRIVATE CONTENT CONTAINER FUNCTIONS
//

static void set_size(boxing_component *container, int width, int height)
{
    boxing_component_set_size(container, width, height);
    SMEMBER(data_capasity) = (width/SMEMBER(symbol_size))*(height/SMEMBER(symbol_size));
}

static void render(boxing_component *container, boxing_painter * painter)
{
    const int width = container->size.x;
    if (SMEMBER(data_size))
    {
        if (SMEMBER(symbol_size) == 1)
        {
            int lines = (SMEMBER(data_size) > SMEMBER(data_capasity) ? SMEMBER(data_capasity) : SMEMBER(data_size)) / width;
            const char * data_ptr = SMEMBER(data);
            painter->draw_image(painter, 0, 0, data_ptr, width, 0, 0, width, lines);
            if (SMEMBER(data_size) % width)
            {
                painter->draw_image(painter, 0, lines, data_ptr, width, 0, lines, SMEMBER(data_size) % width, 1);
            }
        }
        else
        {
            int remaining_symbols = (SMEMBER(data_size) > SMEMBER(data_capasity) ? SMEMBER(data_capasity) : SMEMBER(data_size));
            int x = 0;
            int y = 0;
            const char * data_ptr = SMEMBER(data);
            while (remaining_symbols)
            {
                painter->fill_rect(painter, x, y, SMEMBER(symbol_size), SMEMBER(symbol_size), *data_ptr);
                x += SMEMBER(symbol_size);
                if (x >= width)
                {
                    y += SMEMBER(symbol_size);
                    x = 0;
                }
                data_ptr++;
                remaining_symbols--;
            }
        }
    }
    boxing_component_render(container, painter);
}
