/*
 * fft.h
 *
 * Code generation for function 'fft'
 *
 */

#ifndef FFT_H
#define FFT_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "vsd_types.h"

/* Function Declarations */
extern void fft(const emlrtStack *sp, const real_T x_data[], const int32_T
                x_size[2], real_T varargin_1, emxArray_creal_T *y);

#endif

/* End of code generation (fft.h) */
