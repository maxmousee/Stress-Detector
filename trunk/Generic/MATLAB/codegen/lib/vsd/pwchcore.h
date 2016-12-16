/*
 * File: pwchcore.h
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 16-Dec-2016 20:24:22
 */

#ifndef PWCHCORE_H
#define PWCHCORE_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "vsd_types.h"

/* Function Declarations */
extern void b_pwchcore(const emxArray_real_T *x, const emxArray_real_T *y, int
  yoffset, const emxArray_real_T *s, const double dx_data[], const double
  divdif_data[], emxArray_real_T *pp_breaks, emxArray_real_T *pp_coefs);
extern void pwchcore(const emxArray_real_T *x, const emxArray_real_T *y, const
                     double s[2], emxArray_real_T *pp_breaks, double pp_coefs[4]);

#endif

/*
 * File trailer for pwchcore.h
 *
 * [EOF]
 */
