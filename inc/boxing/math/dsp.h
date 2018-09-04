#ifndef BOXING_DSP_H
#define BOXING_DSP_H

/*****************************************************************************
**
**  Definition of the digital signal processing interface
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

#include "boxing/bool.h"
#include "boxing/platform/types.h"

void boxing_dsp_low_pass_filter(const boxing_float cutoff_freq, const boxing_float sampling_rate, boxing_float * coeffs, int length);
void boxing_dsp_high_pass_filter(const boxing_float cutoff_freq, const boxing_float sampling_rate, boxing_float * coeffs, int length);
void boxing_dsp_band_pass_filter(const boxing_float center_freq, const boxing_float bandwidth, const boxing_float sampling_rate, boxing_float * coeffs, int length);
void boxing_dsp_filter(const boxing_float * in, unsigned int in_size, boxing_float * out, const boxing_float * filter_coefficients, int msize, DBOOL preload /*  = false */);
void boxing_dsp_filter_int(const int * in, unsigned int in_size, int * out, const boxing_float * filter_coefficients, int size, DBOOL preload /*  = DFALSE */);
void boxing_dsp_filtfilt(const boxing_float * in, unsigned int in_size, boxing_float * out, unsigned int out_size, const boxing_float * filter_coefficients, unsigned int msize);
void boxing_dsp_filtfilt_int(const int * in, unsigned int in_size, boxing_float * out, unsigned int out_size, const boxing_float * filter_coefficients, unsigned int msize);
void boxing_dsp_blackman_window(boxing_float * window, int size);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
