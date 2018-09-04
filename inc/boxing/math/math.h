#ifndef BOXING_MATH_H
#define BOXING_MATH_H

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

#ifdef __cplusplus
extern "C" {
#endif

//  PROJECT INCLUDES
//
#include "boxing/platform/types.h"
#include "boxing/bool.h"

//  TYPES
//

typedef struct boxing_pointi_s
{
    int x;
    int y;
} boxing_pointi;

typedef struct boxing_pointf_s
{
    boxing_float x;
    boxing_float y;
} boxing_pointf;

typedef struct boxing_recti_s
{
    int x;
    int y;
    int width;
    int height;
} boxing_recti;

typedef struct boxing_linef_s
{
    boxing_pointf p1;
    boxing_pointf p2;
} boxing_linef;

//  MACROS
//

#define BOXING_MATH_DOT_PRODUCT(a,b)                         ((a).x * (b).x + (a).y * (b).y)
#define BOXING_MATH_MAX(a,b)                                 (((a) > (b)) ? (a) : (b))
#define BOXING_MATH_MIN(a,b)                                 (((a) < (b)) ? (a) : (b))
#define BOXING_MATH_CLAMP(min, max, value)              ((value) < (min) ? (min) : ((value) > (max) ? (max) : (value)))
#define BOXING_MATH_IS_WITHIN_LIMIT(min, max, value)    ((value) >= (min) && (value) <= (max))
#define BOXING_MATH_SIGN(value)                         ((value) >= 0 ? 1 : -1)


//  FUNCTIONS
//

DBOOL           boxing_math_matrix3x3_invariant(boxing_double m[][3] , boxing_double minv[][3]);
boxing_pointf   boxing_math_pointf_normalize(const boxing_pointf * point);
boxing_pointf   boxing_math_pointf_normal(const boxing_pointf * point);
boxing_pointf   boxing_math_pointf_subtract(const boxing_pointf * point_a, const boxing_pointf * point_b);
void            boxing_math_pointf_add(boxing_pointf* point_a, const boxing_pointi * point_b);
boxing_pointi   boxing_math_pointf_round_to_int(const boxing_pointf * point);
boxing_pointi   boxing_math_pointf_to_int(const boxing_pointf * point);
boxing_float    boxing_math_pointf_length(const boxing_pointf * point);
void            boxing_math_pointi_set(boxing_pointi * point, int x, int y);
DBOOL           boxing_math_pointi_equal(const boxing_pointi * point_a, const boxing_pointi * point_b);
boxing_pointf   boxing_math_pointi_to_float(const boxing_pointi * point);
void            boxing_math_recti_intersect(boxing_recti * rect1, const boxing_recti * rect2);


//  SYSTEM FUNCTIONS
//

#if !defined (BOXING_USE_C99_LIBRARIES) && !defined (BOXING_USE_C89_LIBRARIES)

float    roundf(float x);
long int lround(double x);
double   fabs(double x);
double   sin(double x);
double   cos(double x);
double   atan(double x);
double   floor(double x);
double   sqrt(double x);
float    ceilf(float x);
float    sqrtf(float x);
float    fabsf(float x);
float    powf(float x, float y);
float    atanf(float x);
float    sinf(float x);
float    cosf(float x);
float    floorf(float x);
#define  isfinite(x) /* implement me */

#else

#include <math.h>

#endif

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
