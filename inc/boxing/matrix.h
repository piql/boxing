#ifndef BOXING_MATRIX_H
#define BOXING_MATRIX_H

/*****************************************************************************
**
**  Definition of the matrix interface
**
**  Creation date:  2014/12/16
**  Created by:     Piql AS
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
#include "boxing/bool.h"
#include "boxing/math/math.h"

//  TYPES
//
typedef struct boxing_matrix_float_s
{
    unsigned int cols;
    unsigned int rows;
    unsigned int pages;
    DBOOL is_owning_data;
    boxing_float * data;
} boxing_matrix_float;

typedef struct boxing_matrixf_s
{
    unsigned int width;
    unsigned int height;
    DBOOL is_owning_data;
    boxing_pointf * data;
} boxing_matrixf;

typedef struct boxing_matrixi_s
{
    unsigned int width;
    unsigned int height;
    DBOOL is_owning_data;
    boxing_pointi * data;
} boxing_matrixi;


//  FUNCTIONS
//

boxing_matrix_float * boxing_matrix_float_multipage_create(unsigned int cols, unsigned int rows, unsigned int pages);
void                  boxing_matrix_float_free(boxing_matrix_float * matrix);

boxing_matrixf * boxing_matrixf_create(unsigned int width, unsigned int height);
boxing_matrixi * boxing_matrixi_create(unsigned int width, unsigned int height);
boxing_matrixf * boxing_matrixf_recreate(boxing_matrixf * matrix, unsigned int width, unsigned int height);
boxing_matrixi * boxing_matrixi_recreate(boxing_matrixi * matrix, unsigned int width, unsigned int height);
void             boxing_matrixf_init_in_place(boxing_matrixf * matrix, unsigned int width, unsigned int height);
void             boxing_matrixi_init_in_place(boxing_matrixi * matrix, unsigned int width, unsigned int height);
boxing_matrixf * boxing_matrixf_copy(const boxing_matrixf * matrix);
boxing_matrixi * boxing_matrixi_copy(const boxing_matrixi * matrix);
void             boxing_matrixf_free(boxing_matrixf * matrix);
void             boxing_matrixi_free(boxing_matrixi * matrix);

#define MATRIX_MULTIPAGE_ROW_PTR(matrix, row, page) ( MATRIX_MULTIPAGE_PAGE_PTR(matrix, page) + (matrix)->cols * (row) )
#define MATRIX_MULTIPAGE_PAGE_PTR(matrix, page) ( (matrix)->data + ((matrix)->cols * (matrix)->rows * (page)) )

#define MATRIX_ELEMENT(matrix, x, y) ((matrix)->data[(y) + (x) * (matrix)->width])
#define MATRIX_PELEMENT(matrix, x, y) ((matrix)->data + (y) + (x) * (matrix)->width)

#define MATRIX_ROW(matrix, y) ((matrix)->data + (y) * (matrix)->width)

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
