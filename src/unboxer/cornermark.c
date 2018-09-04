/*****************************************************************************
**
**  Implementation of the corner mark interface
**
**  Creation date:  2016/09/13
**  Created by:     Ole Liabo
**
**
**  Copyright (c) 2016 Piql AS. All rights reserved.
**
**  This file is part of the boxing library
**
*****************************************************************************/

//  PROJECT INCLUDES
//
#include "boxing/unboxer/cornermark.h"


//----------------------------------------------------------------------------
/*! 
  * \addtogroup unboxer
  * \{
  */


//----------------------------------------------------------------------------
/*!
 *  \enum       boxing_corner_mark_result cornermark.h
 *  \brief      The enumeration for specifying the corner mark result.
 *  
 *  \param BOXING_CORNER_MARK_OK              (0) Corner mark result is OK.
 *  \param BOXING_CORNER_MARK_TRACKING_ERROR  (1) Corner mark result is tracking error.
 *  \param BOXING_CORNER_MARK_CALLBACK_ABORT  (2) Corner mark result is callback abort.
 *
 *  The enumeration for specifying the corner mark result.
 */


/*! 
 *  \typedef int (*boxing_corner_mark_callback)(void * user, const struct boxing_image8_s * image, boxing_corner_mark_definition * def,
 *           boxing_float sampling_rate_x, boxing_float sampling_rate_y, frame_corner_marks * corners)
 *  \brief   Corner mark callback function.
 *
 *  \param user             Pointer to the user data.
 *  \param image            Pointer to the boxing_image8 structure.
 *  \param def              Pointer to the boxing_corner_mark_definition structure.
 *  \param sampling_rate_x  Sampling rate along the x axis.
 *  \param sampling_rate_y  Sampling rate along the y axis.
 *  \param corners          Pointer to the frame_corner_marks structure.
 *   
 *  Corner mark callback function.
 */


/*! 
 *  \typedef int (*boxing_corner_mark_complete_cb)(void * user, int * res, frame_corner_marks * corner_marks)
 *  \brief   Corner mark complete callback function.
 *
 *  \param user          Pointer to the user data.
 *  \param res           Corner mark result.
 *  \param corner_marks  Pointer to the frame_corner_marks structure.
 *   
 *  Corner mark complete callback function.
 */


//----------------------------------------------------------------------------
/*!
 *  \struct  frame_corner_marks_s  cornermark.h
 *  \brief   Corner points of the rectangular area.
 *  
 *  \param top_left      Top left corner point.
 *  \param top_right     Top right corner point.
 *  \param bottom_left   Bottom left corner point.
 *  \param bottom_right  Bottom right corner point.
 *
 *  The structure for storing the corner points of the rectangular area.
 */


//----------------------------------------------------------------------------
/*!
 *  \struct  boxing_corner_mark_definition_s  cornermark.h
 *  \brief   Corner marks definition.
 *
 *  \param symbol               Full size of 2x2 mosaic in pixels.
 *  \param quiet_zone           Number of black pixels around corner mark.
 *  \param vertical_distance    Distance between the center of the top_left and bottom_left corner marks (calculated by PIQL from frame height).
 *  \param horizontal_distance  Distance between the center of the top_left and top_right corner marks (calculated by PIQL from frame width).
 *  \param gap_between_frames   Distance between the center of bottom corner marks of nth frame and center of top corner marks of the n+1th frame.
 *
 *  Corner marks definition. All coordinates are given in printed coordinate space.
 */


// PUBLIC CORNER MARK FUNCTIONS
//

//---------------------------------------------------------------------------- 
/*! \brief Calculate dimensions
 *
 *  Calculate dimensions of the rectangular area.
 *
 *  \param[in]  corner_marks  Corner points of the rectangular area.
 *  \return dimensions of the rectangular area.
 */

boxing_pointi boxing_corner_mark_dimension( frame_corner_marks* corner_marks )
{
    boxing_pointi rectangle =
    {
        // assuming the sampling rate is the same at top and bottom 
        corner_marks->top_right.x - corner_marks->top_left.x,

        // assuming the sampling rate is the same at both sides 
        corner_marks->bottom_left.y - corner_marks->top_left.y
    };

    return rectangle;
}


//----------------------------------------------------------------------------
/*!
  * \} end of unboxer group
  */
