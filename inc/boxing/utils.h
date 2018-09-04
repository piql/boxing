#ifndef BOXING_UTILS_H
#define BOXING_UTILS_H

/*****************************************************************************
**
**  Definition of the utilities interface
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
#include "gvector.h"

#define BOXING_VIRTUAL( p, method ) ((p)->method(p))
#define BOXING_VIRTUALP( p, method, param ) (p)->method((p), param))
#define BOXING_VIRTUALP2( p, method, param1, param2 ) (p)->method((p), param1, param2))
#define BOXING_VIRTUAL2( p, method1, method2 ) ((p)->method1(p)->method2((p)->method1(p)))
#define BOXING_VIRTUAL2p( p, method1, method2, param ) ((p)->method1(p)->method2((p)->method1(p), param))
#define BOXING_VIRTUAL2p2( p, method1, method2, param1, param2 ) ((p)->method1(p)->method2((p)->method1(p), param1, param2))

#define BOXING_UNUSED_PARAMETER(parameter) do { (void)(parameter); } while (0)

void      boxing_utils_g_hash_table_destroy_item_string(void * data);
void      boxing_utils_g_hash_table_destroy_item_ghash(void * data);
void      boxing_utils_g_hash_table_destroy_item_g_variant(void * data);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
