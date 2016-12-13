/*
 * pwchcore.h
 *
 * Code generation for function 'pwchcore'
 *
 */

#ifndef PWCHCORE_H
#define PWCHCORE_H

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
extern void b_pwchcore(const emlrtStack *sp, const real_T x_data[], const
  int32_T x_size[2], const real_T y_data[], int32_T yoffset, const real_T
  s_data[], const real_T dx_data[], const real_T divdif_data[], real_T
  pp_breaks_data[], int32_T pp_breaks_size[2], emxArray_real_T *pp_coefs);
extern void pwchcore(const real_T x_data[], const int32_T x_size[2], const
                     real_T y_data[], const real_T s[2], real_T pp_breaks_data[],
                     int32_T pp_breaks_size[2], real_T pp_coefs[4]);

#endif

/* End of code generation (pwchcore.h) */
