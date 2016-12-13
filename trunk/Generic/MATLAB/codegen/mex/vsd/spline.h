/*
 * spline.h
 *
 * Code generation for function 'spline'
 *
 */

#ifndef SPLINE_H
#define SPLINE_H

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
extern void spline(vsdStackData *SD, const emlrtStack *sp, const real_T x_data[],
                   const int32_T x_size[2], const real_T y_data[], const int32_T
                   y_size[2], real_T output_data[], int32_T output_size[2]);

#endif

/* End of code generation (spline.h) */
