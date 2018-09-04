#ifndef _GALOIS_FIELD_REEDSOLOMONLIBC_H
#define _GALOIS_FIELD_REEDSOLOMONLIBC_H

/***********************************************************************
* Copyright Henry Minsky (hqm@alum.mit.edu) 1991-2009
*
* This software library is licensed under terms of the GNU GENERAL
* PUBLIC LICENSE
*
*
* RSCODE is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* RSCODE is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with Rscode.  If not, see <http://www.gnu.org/licenses/>.
*
* Commercial licensing is available under a separate license, please
* contact author for details.
*
* Source code is available at http://rscode.sourceforge.net
* Berlekamp-Peterson and Berlekamp-Massey Algorithms for error-location
*
* From Cain, Clark, "Error-Correction Coding For Digital Communications", pp. 205.
*
* This finds the coefficients of the error locator polynomial.
*
* The roots are then found by looking for the values of a^n
* where evaluating the polynomial yields zero.
*
* Error correction is done using the error-evaluator equation  on pp 207.
*
*/

#ifdef __cplusplus
extern "C" {
#endif

#include "boxing/platform/types.h"

typedef struct galois_field_s {
    uint32_t *exp;
    uint32_t *log;
    uint32_t  mask;
    uint32_t  prim_polynom;
    uint32_t  alphabet_size;
} galois_field;

galois_field * gf_create(uint32_t prime_plonomial);
void           gf_free(galois_field *);
uint32_t       gf_multiply(galois_field * gf, uint32_t a, uint32_t b);
uint32_t       gf_roots_summ(galois_field * gf, uint32_t a, uint32_t b);
uint32_t       gf_inverse(galois_field * gf, uint32_t a);
void           gf_multiply_polynomial(galois_field *gf, uint32_t *dst, uint32_t *p1, uint32_t p1_size, uint32_t *p2, uint32_t p2_size);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _GALOIS_FIELD_REEDSOLOMONC_H */
