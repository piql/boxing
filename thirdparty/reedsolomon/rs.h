#ifndef _REEDSOLOMONLIBC_H
#define _REEDSOLOMONLIBC_H

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

#include "boxing/codecs/codecbase.h"
#include "boxing/platform/types.h"

#define RS_PRIM_POLY_285  0x0000011D
#define RS_PRIM_POLY_529  0x00000211
#define RS_PRIM_POLY_1033 0x00000409

typedef struct rs_codec_s rs_codec;

rs_codec* rs_create(int message_size, int parity_size, uint32_t prime_plonomial);
void rs_free(rs_codec *codec);
void rs_encode(rs_codec *rs, gvector * data, gvector * data_encode);
void rs_decode(rs_codec *rs, gvector * data, gvector * data_decode, unsigned int *resolved_errors, unsigned int *fatal_errors, int *max_errors_per_block);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* _REEDSOLOMONC_H */
