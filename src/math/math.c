/*****************************************************************************
**
**  Definition of the math interface
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
#include "boxing/math/math.h"


/*! 
  * \addtogroup math
  * \{
  */


//----------------------------------------------------------------------------
/*!
 *  \def BOXING_MATH_DOT_PRODUCT(a,b) math.h
 *  \brief Calculate dot product.
 *
 *  Calculate dot product from two points.
 *
 *  \param[in]  a  Point a.
 *  \param[in]  b  Point b.
 */


//----------------------------------------------------------------------------
/*!
 *  \def BOXING_MATH_MAX(a,b) math.h
 *  \brief Find the maximum value.
 *
 *  Find the maximum value.
 *
 *  \param[in]  a  Value a.
 *  \param[in]  b  Value b.
 */


//----------------------------------------------------------------------------
/*!
 *  \def BOXING_MATH_MIN(a,b) math.h
 *  \brief Find the minimum value.
 *
 *  Find the minimum value.
 *
 *  \param[in]  a  Value a.
 *  \param[in]  b  Value b.
 */


//----------------------------------------------------------------------------
/*!
 *  \def BOXING_MATH_CLAMP(min, max, value) math.h
 *  \brief Limits the value to the minimum and maximum values.
 *
 *  Limits the value to the minimum and maximum values.
 *
 *  \param[in]  min    The minimum allowed value.
 *  \param[in]  max    The maximum allowed value.
 *  \param[in]  value  Value.
 */


//----------------------------------------------------------------------------
/*!
 *  \def BOXING_MATH_IS_WITHIN_LIMIT(min, max, value) math.h
 *  \brief Determine whether the value is within the specified limits.
 *
 *  Determine whether the value is within the specified limits.
 *
 *  \param[in]  min    The minimum value.
 *  \param[in]  max    The maximum value.
 *  \param[in]  value  Value.
 */


//----------------------------------------------------------------------------
/*!
 *  \def BOXING_MATH_SIGN(value) math.h
 *  \brief Determine the sign of a variable.
 *
 *  Determine the sign of a variable.
 *
 *  \param[in]  value  Value.
 */


//----------------------------------------------------------------------------
/*!
 *  \struct     boxing_pointi_s  math.h
 *  \brief      Integer point.
 *  
 *  \param x  X coordinate.
 *  \param y  Y coordinate.
 *
 *  Structure for storing integer point data.
 */


//----------------------------------------------------------------------------
/*!
 *  \struct     boxing_pointf_s  math.h
 *  \brief      Float point.
 *  
 *  \param x  X coordinate.
 *  \param y  Y coordinate.
 *
 *  Structure for storing float point data.
 */


//----------------------------------------------------------------------------
/*!
 *  \struct     boxing_pointf_s  math.h
 *  \brief      Integer rectangular area.
 *  
 *  \param x       X coordinate.
 *  \param y       Y coordinate.
 *  \param width   Area width.
 *  \param height  Area height.
 *
 *  Structure for storing integer rectangular area data.
 */


//----------------------------------------------------------------------------
/*!
 *  \struct     boxing_linef_s  math.h
 *  \brief      Line with float coordinates.
 *  
 *  \param p1  First float line point.
 *  \param p2  Second float line point.
 *
 *  Structure for storing float line data.
 */


// PUBLIC MATH FUNCTIONS
//

//----------------------------------------------------------------------------
/*!
 *  \brief Calculate matrix 3x3 invariant.
 *
 *  Calculate matrix 3x3 invariant.
 *
 *  \param[in]   m     Input matrix.
 *  \param[out]  minv  Output invariant matrix.
 *  \return DTRUE if success.
 */

DBOOL boxing_math_matrix3x3_invariant(boxing_double m[][3] , boxing_double minv[][3])
{
  
  boxing_double invdet = (m[0][0] * (m[1][1] * m[2][2] - m[2][1] * m[1][2]) -
                          m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) +
                          m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]));

  if(invdet == 0)
      return DFALSE;

  invdet = 1.0/invdet;

  minv[0][0] = (m[1][1] * m[2][2] - m[2][1] * m[1][2]) * invdet;
  minv[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) * invdet;
  minv[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * invdet;
  minv[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) * invdet;
  minv[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * invdet;
  minv[1][2] = (m[1][0] * m[0][2] - m[0][0] * m[1][2]) * invdet;
  minv[2][0] = (m[1][0] * m[2][1] - m[2][0] * m[1][1]) * invdet;
  minv[2][1] = (m[2][0] * m[0][1] - m[0][0] * m[2][1]) * invdet;
  minv[2][2] = (m[0][0] * m[1][1] - m[1][0] * m[0][1]) * invdet;
  
  return DTRUE;
}


//----------------------------------------------------------------------------
/*!
 *  \brief Normalize float point.
 *
 *  Normalize float point.
 *
 *  \param[in]  point  Float point.
 *  \return Normalized float point.
 */

boxing_pointf boxing_math_pointf_normalize(const boxing_pointf * point)
{
    boxing_pointf normalized = *point;

    if (point->x == 0 && point->y == 0)
    {
        return normalized;
    }

    boxing_float length = sqrtf(point->x * point->x + point->y * point->y);

    normalized.x /= length;
    normalized.y /= length;
    return normalized;
}


//----------------------------------------------------------------------------
/*!
 *  \brief Normal float point.
 *
 *  Normal float point.
 *
 *  \param[in]  point  Float point.
 *  \return Normal float point.
 */

boxing_pointf boxing_math_pointf_normal(const boxing_pointf * point)
{
    boxing_pointf normal = { point->y, -point->x };
    return normal;
}


//----------------------------------------------------------------------------
/*!
 *  \brief Substract two float points.
 *
 *  Substract two float points.
 *
 *  \param[in]  point_a  First float point.
 *  \param[in]  point_b  Second float point.
 *  \return Substract result.
 */

boxing_pointf boxing_math_pointf_subtract(const boxing_pointf * point_a, const boxing_pointf * point_b)
{
    boxing_pointf delta = { point_a->x - point_b->x, point_a->y - point_b->y };
    return delta;
}


//----------------------------------------------------------------------------
/*!
 *  \brief Add two float points.
 *
 *  Add two float points.
 *
 *  \param[in]  point_a  First float point.
 *  \param[in]  point_b  Second float point.
 *  \return Add result.
 */

void boxing_math_pointf_add(boxing_pointf* point_a, const boxing_pointi* point_b)
{
    point_a->x += point_b->x;
    point_a->y += point_b->y;
}


//----------------------------------------------------------------------------
/*!
 *  \brief Round float point to integer point.
 *
 *  Round float point to integer point.
 *
 *  \param[in]  point  Float point.
 *  \return Rounded integer point.
 */

boxing_pointi boxing_math_pointf_round_to_int(const boxing_pointf * point)
{
    boxing_pointi rounded = { (int)roundf(point->x), (int)roundf(point->y) };
    return rounded;
}


//----------------------------------------------------------------------------
/*!
 *  \brief Reduces float point to integer point.
 *
 *  Reduces float point to integer point.
 *
 *  \param[in]  point  Float point.
 *  \return Reduced integer point.
 */

boxing_pointi boxing_math_pointf_to_int(const boxing_pointf * point)
{
    boxing_pointi pointi = { (int)(point->x), (int)(point->y) };
    return pointi;
}


//----------------------------------------------------------------------------
/*!
 *  \brief Calculate the vector length.
 *
 *  Calculate the vector length.
 *
 *  \param[in]  point  Float point.
 *  \return Vector length.
 */

boxing_float boxing_math_pointf_length(const boxing_pointf * point)
{
    return sqrtf(point->x * point->x + point->y * point->y);
}


//----------------------------------------------------------------------------
/*!
 *  \brief Set new integer point coordinates.
 *
 *  Set new integer point coordinates.
 *
 *  \param[out]  point  Integer point.
 *  \param[in]   x      New X-coordinate.
 *  \param[in]   y      New Y-coordinate.
 */

void boxing_math_pointi_set(boxing_pointi * point, int x, int y)
{
    point->x = x;
    point->y = y;
}


//----------------------------------------------------------------------------
/*!
 *  \brief Checks two integer points on the identity.
 *
 *  Checks two integer points on the identity.
 *
 *  \param[in]  point_a  First integer point.
 *  \param[in]  point_b  Second integer point.
 *  \return sign of identity of the input pouints.
 */

DBOOL boxing_math_pointi_equal( const boxing_pointi * point_a, const boxing_pointi * point_b )
{
    return point_a->x == point_b->x && point_a->y == point_b->y;
}


//----------------------------------------------------------------------------
/*!
 *  \brief Reduces integer point to float point.
 *
 *  Reduces integer point to float point.
 *
 *  \param[in]  point  Integer point.
 *  \return Reduced float point.
 */

boxing_pointf boxing_math_pointi_to_float( const boxing_pointi * point )
{
    return (boxing_pointf){ (boxing_float)point->x, (boxing_float)point->y };
}


//----------------------------------------------------------------------------
/*!
 *  \brief Calculate intersect of the rectangular areas.
 *
 *  Calculate intersect of the rectangular areas.
 *
 *  \param[in]  rect1  First rectangular area.
 *  \param[in]  rect2  Second rectangular area.
 */

void boxing_math_recti_intersect(boxing_recti * rect1, const boxing_recti * rect2)
{
    int x_max1 = rect1->x + rect1->width;
    int x_max2 = rect2->x + rect2->width;
    int x_max = (x_max1 < x_max2) ? x_max1 : x_max2;
    int x_min = (rect1->x > rect2->x) ? rect1->x : rect2->x;
    rect1->x = x_min;
    rect1->width = (x_max - x_min > 0) ? (x_max - x_min) : 0;

    int y_max1 = rect1->y + rect1->height;
    int y_max2 = rect2->y + rect2->height;
    int y_max = (y_max1 < y_max2) ? y_max1 : y_max2;
    int y_min = (rect1->y > rect2->y) ? rect1->y : rect2->y;
    rect1->y = y_min;
    rect1->height = (y_max - y_min > 0) ? (y_max - y_min) : 0;
}


//----------------------------------------------------------------------------
/*!
  * \} end of math group
  */


//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn long int lround(double x)
 *  \brief Round to nearest integer
 *
 *  These functions round their argument to the nearest integer  value, 
 *  rounding away from zero.
 *
 *  \param  x  Floating point number to be rounded
 *  \return Rounded integer value.
 */

//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn double   fabs(double x)
 *  \brief Absolute value of floating-point number
 *
 *  The fabs() functions return the absolute value of the floating-point 
 *  number x.
 *
 *  \param  x  Floating point number.
 *  \return Absolute value of x.
 */

//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn float    fabsf(float x)
 *  \brief Absolute value of floating-point number
 *
 *  The fabs() functions return the absolute value of the floating-point 
 *  number x.
 *
 *  \param  x  Floating point number.
 *  \return Absolute value of x.
 */

//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn double   sin(double x)
 *  \brief Sine function
 *
 *  The sin() function returns the sine of x, where x is given in radians.
 *
 *  \param  x  Angle in radians
 *  \return Sine of x.
 */

//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn float    sinf(float x)
 *  \brief Sine function
 *
 *  The sin() function returns the sine of x, where x is given in radians.
 *
 *  \param  x  Angle in radians
 *  \return Sine of x.
 */

//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn double   cos(double x)
 *  \brief Sine function
 *
 *  The cos() function returns the cosine of x, where x is given in radians.
 *
 *  \param  x  Angle in radians
 *  \return Cosine of x.
 */

//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn float    cosf(float x)
 *  \brief Sine function
 *
 *  The cos() function returns the cosine of x, where x is given in radians.
 *
 *  \param  x  Angle in radians
 *  \return Cosine of x.
 */

//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn double   atan(double x)
 *  \brief Arc tangent function
 *
 *  The atan() function calculates the principal value of the arc tangent of 
 *  x; that is the value whose tangent is x.
 *
 *  \param  x  Tangent
 *  \return The principal value of the arc tangent of x in radians; the return 
 *          value is in the range [-pi/2, pi/2].
 */

//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn float    atanf(float x)
 *  \brief Arc tangent function
 *
 *  The atan() function calculates the principal value of the arc tangent of 
 *  x; that is the value whose tangent is x.
 *
 *  \param  x  Tangent
 *  \return The principal value of the arc tangent of x in radians; the return 
 *          value is in the range [-pi/2, pi/2].
 */

//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn double   floor(double x)
 *  \brief Largest integral value not greater than argument
 *
 *  Return the largest integral value that is not greater than x.
 *  For example, floor(0.5) is 0.0, and floor(-0.5) is -1.0.
 *
 *  \param  x  Value
 *  \return Floor of x.
 */

//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn float    floorf(float x)
 *  \brief Largest integral value not greater than argument
 *
 *  Return the largest integral value that is not greater than x.
 *  For example, floor(0.5) is 0.0, and floor(-0.5) is -1.0.
 *
 *  \param  x  Value
 *  \return Floor of x.
 */

//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn double   sqrt(double x)
 *  \brief Largest integral value not greater than argument
 *
 *  The sqrt() function returns the non-negative square root of x.
 *
 *  \param  x  Value
 *  \return The square root of x.
 */

//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn float    sqrtf(float x)
 *  \brief Largest integral value not greater than argument
 *
 *  The sqrt() function returns the non-negative square root of x.
 *
 *  \param  x  Value
 *  \return The square root of x.
 */

//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn float    ceilf(float x)
 *  \brief Smallest integral value not less than argument
 *
 *  These functions return the smallest integral value that is not less than 
 *  x. For example, ceil(0.5) is 1.0, and ceil(-0.5) is 0.0.
 *
 *  \param  x  Value
 *  \return Ceiling of x.
 */

//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn float    powf(float x, float y)
 *  \brief Power function
 *
 *  The powf() function returns the value of x raised to the power of y.
 *
 *  \param  x  Value
 *  \param  y  Exponent
 *  \return Power of x.
 */

//----------------------------------------------------------------------------
/*! \ingroup platform
 *  \fn isfinite(x)
 *  \brief Check floating point
 *
 *  Return non-zero value if x is a valid floating point number.
 *
 *  \param  x  Value
 *  \return Return non-zero value if x is a valid.
 */
