/*****************************************************************************
**
**  Implementation of the sample utility interface
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
#include    "boxing/unboxer/sampleutil.h"

//  SYSTEM INCLUDES
//


//---------------------------------------------------------------------------- 
/*! 
 *  \file     sampleutil.h
 *  \defgroup sampleutil Image sampling utility functions
 *  \ingroup  unbox
 *  \brief    Utility functions for samping an image
 *
 *  Functions for sampling pixels and lines.
 */


/*! 
  * \addtogroup sampleutil
  * \{
  */


// PUBLIC SAMPLE UTIL FUNCTIONS
//

//---------------------------------------------------------------------------- 
/*! 
 *  \brief    Get interpolated pixel value, influenced by neighbors. 
 *  \return   Interpolated pixel.
 *
 *  The interpolated value is created from a 2nd order parabolic function, using
 *  a 3x3 matrix where the matrix center is the nearest neighbour to the sampling 
 *  position.
 */ 

boxing_float boxing_sampleutil_pixel( const boxing_image8 * image, boxing_float x, boxing_float y )
{
    //function z = sample(m, x, y)
    //  A = [ 0 0 1; 1 1 1; 4 2 1]
    //  Ai = inv(A)

    boxing_float m[3][3];

    m[0][0] = IMAGE8_PIXEL(image, (int)x-1,   (int)y-1);
    m[0][1] = IMAGE8_PIXEL(image, (int)x,     (int)y-1);
    m[0][2] = IMAGE8_PIXEL(image, (int)x+1,   (int)y-1);

    m[1][0] = IMAGE8_PIXEL(image, (int)x-1,   (int)y);
    m[1][1] = IMAGE8_PIXEL(image, (int)x,     (int)y);
    m[1][2] = IMAGE8_PIXEL(image, (int)x+1,   (int)y);

    m[2][0] = IMAGE8_PIXEL(image, (int)x-1,   (int)y+1);
    m[2][1] = IMAGE8_PIXEL(image, (int)x,     (int)y+1);
    m[2][2] = IMAGE8_PIXEL(image, (int)x+1,   (int)y+1);

    static boxing_float Ai[3][3] = {
        {  0.50000f,  -1.00000f,   0.50000f },
        { -1.50000f,   2.00000f,  -0.50000f },
        {  1.00000f,   0.00000f,   0.00000f },
    };
    boxing_float x_ = (boxing_float)x - (int)x + 1;
    boxing_float y_ = (boxing_float)y - (int)y + 1;
    boxing_float Z[3];
    boxing_float B[3];
    boxing_float Y[3] = {y_*y_, y_, 1};
    boxing_float X[3] = {x_*x_, x_, 1};

    B[0] = m[0][0] * Ai[0][0] + m[1][0] * Ai[0][1] + m[2][0] * Ai[0][2];
    B[1] = m[0][0] * Ai[1][0] + m[1][0] * Ai[1][1] + m[2][0] * Ai[1][2];
    B[2] = m[0][0] * Ai[2][0];// + m[1][0] * Ai[2][1] + m[2][0] * Ai[2][2];

    Z[0] = Y[0]*B[0] + Y[1]*B[1] + Y[2]*B[2];

    B[0] = m[0][1] * Ai[0][0] + m[1][1] * Ai[0][1] + m[2][1] * Ai[0][2];
    B[1] = m[0][1] * Ai[1][0] + m[1][1] * Ai[1][1] + m[2][1] * Ai[1][2];
    B[2] = m[0][1] * Ai[2][0];// + m[1][1] * Ai[2][1] + m[2][1] * Ai[2][2];

    Z[1] = Y[0]*B[0] + Y[1]*B[1] + Y[2]*B[2];

    B[0] = m[0][2] * Ai[0][0] + m[1][2] * Ai[0][1] + m[2][2] * Ai[0][2];
    B[1] = m[0][2] * Ai[1][0] + m[1][2] * Ai[1][1] + m[2][2] * Ai[1][2];
    B[2] = m[0][2] * Ai[2][0];// + m[1][2] * Ai[2][1] + m[2][2] * Ai[2][2];

    Z[2] = Y[0]*B[0] + Y[1]*B[1] + Y[2]*B[2];

    B[0] = Z[0] * Ai[0][0] + Z[1] * Ai[0][1] + Z[2] * Ai[0][2];
    B[1] = Z[0] * Ai[1][0] + Z[1] * Ai[1][1] + Z[2] * Ai[1][2];
    B[2] = Z[0] * Ai[2][0] + Z[1] * Ai[2][1] + Z[2] * Ai[2][2];


    boxing_float res = (X[0]*B[0] + X[1]*B[1] + X[2]*B[2]);
    if(res < BOXING_PIXEL_MIN)
        res = BOXING_PIXEL_MIN;
    else if(res > BOXING_PIXEL_MAX)
        res = BOXING_PIXEL_MAX;

    return res;
}


//---------------------------------------------------------------------------- 
/*! 
 *  \brief    Get average pixel value for line.
 *  \param    pos         Line start position
 *  \param    direction   Line direction and sampling frequency. Must be normalized.
 *  \param    image       Image to be sampled.
 *  \param    start       Start position on perpendicular line 
 *  \param    end         End position on perpendicular line 
 *  \return   Interpolated pixels.
 *
 *  The function samples pixels along a line and averages pixels perpendicular to the 
 *  line for each sampling point. The direction parameter defines the line and sampling 
 *  frequency.
 */ 

boxing_float boxing_sampleutil_line( const boxing_pointf * pos, const boxing_pointf * direction, const boxing_image8 * image, int start, int end )
{
    boxing_float sample = 0.0f;
    boxing_float samples = 0.0f;
    boxing_float p = (boxing_float)start;
    for (int n = start; n < end; n++, p++)
    {
        boxing_float x = pos->x + direction->x * p;
        boxing_float y = pos->y + direction->y * p;
    
        sample += boxing_sampleutil_pixel( image, x, y );
        samples++;
    }

    return sample / samples;
}


//---------------------------------------------------------------------------- 
/*! 
 *  \brief    Get average pixel values, sampled perpendicular to line.
 *  \param    samples     Interpolated pixel values
 *  \param    pos         Line start position
 *  \param    direction   Line direction and sampling frequency.
 *  \param    image       Image to be sampled.
 *  \param    start       Start position on perpendicular line to directon, in units of direction length. 
 *  \param    end         End position on perpendicular line, in units of direction length.
 *  \return   Interpolated pixels.
 *
 *  The function samples pixels along a line and averages pixels perpendicular to the 
 *  line for each sampling point. The direction parameter defines the line and sampling 
 *  frequency.
 *
 *  \todo Samples should be vector of boxing_floats
 *  \todo Replace start/end with count.
 */ 

void boxing_sampleutil_perpendicular_lines( gvector * samples, boxing_pointf * pos, const boxing_pointf * direction, const boxing_image8 * image, int start, int end )
{
    boxing_pointf normal = boxing_math_pointf_normal( direction );

    for (unsigned int i = 0; i < samples->size; i++, pos->x += direction->x, pos->y += direction->y )
    {
        GVECTORN(samples, int, i) = (int)boxing_sampleutil_line( pos, &normal, image, start, end );
    }
}


//----------------------------------------------------------------------------
/*!
  * \} end of sampleutil group
  */
