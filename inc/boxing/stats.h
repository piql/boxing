#ifndef BOXING_UNBOXER_STATS_H
#define BOXING_UNBOXER_STATS_H

/*****************************************************************************
**
**  Declaration of the unboxer statistics C interface
**
**  Creation date:  2015/09/02
**  Created by:     Morgun Dmytro
**
**
**  Copyright (c) 2015 Piql AS. All rights reserved.
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


typedef struct boxing_stats_decode_s
{
    unsigned int resolved_errors;
    unsigned int unresolved_errors;
    boxing_float fec_accumulated_amount;
    boxing_float fec_accumulated_weight;
} boxing_stats_decode;

typedef struct boxing_stats_mtf_s
{
    boxing_float top_horizontal_mtf;
    boxing_float bottom_horizontal_mtf;
    boxing_float left_vertical_mtf;
    boxing_float right_vertical_mtf;
} boxing_stats_mtf;

typedef struct boxing_reference_bar_stats_s
{
    boxing_float top_mtf;
    boxing_float bottom_mtf;
    boxing_float left_mtf;
    boxing_float right_mtf;
} boxing_reference_bar_stats;

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
