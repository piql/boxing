#ifndef BOXING_PAINTDEVICE_H
#define BOXING_PAINTDEVICE_H

/*****************************************************************************
**
**  Definition of the PaintDevice interface
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


//============================================================================
//  STRUCT:  boxing_paintdevice

typedef struct boxing_paintdevice_s
{
        void (*draw_line)(struct boxing_paintdevice_s *device, const boxing_recti * clip_region, int x1, int y1, int x2, int y2, const int color);
        void (*draw_rect)(struct boxing_paintdevice_s *device, const boxing_recti * clip_region, int x, int y, int width, int height, const int color);
        void (*fill_rect)(struct boxing_paintdevice_s *device, const boxing_recti * clip_region, int x, int y, int width, int height, const int color);
        void (*draw_image)(struct boxing_paintdevice_s *device, const boxing_recti * clip_region, int x, int y, const char * image, int scanLineWidth, 
                       int sx, int sy, int sw, int sh);
        int  (*width)(struct boxing_paintdevice_s *device);
        int  (*height)(struct boxing_paintdevice_s *device);
        void (*free)(struct boxing_paintdevice_s *device);
} boxing_paintdevice;


//============================================================================


#endif
