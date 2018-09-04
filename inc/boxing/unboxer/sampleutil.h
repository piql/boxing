#ifndef BOXING_SAMPLEUTIL_H
#define BOXING_SAMPLEUTIL_H

/*****************************************************************************
**
**  Definition of frame tracker utility functions
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
#include "boxing/image8.h"
#include "gvector.h"

boxing_float boxing_sampleutil_pixel( const boxing_image8 * image, boxing_float x, boxing_float y );
boxing_float boxing_sampleutil_line( const boxing_pointf * pos, const boxing_pointf * direction, const boxing_image8 * image, int start, int end );
void         boxing_sampleutil_perpendicular_lines( gvector * samples, boxing_pointf * pos, const boxing_pointf * direction, const boxing_image8 * image, int start, int end );

#ifdef __cplusplus
} /* extern "C" */
#endif

//============================================================================


#endif
