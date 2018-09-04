#ifndef BOXING_GENERICFRAMEFACTORY_H
#define BOXING_GENERICFRAMEFACTORY_H

/*****************************************************************************
**
**  Definition of the GenericFrameFactory interface
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

#include "boxing/config.h"

//  SYSTEM INCLUDES
//

struct boxing_frame_s;


//============================================================================
//  Frame factory.


struct boxing_frame_s * boxing_generic_frame_factory_create(const boxing_config * config);
void                    boxing_generic_frame_factory_free(struct boxing_frame_s * frame);

//============================================================================

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
