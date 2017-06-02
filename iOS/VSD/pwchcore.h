/*
 * File: pwchcore.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 06-Jun-2014 20:32:45
 */

#ifndef __PWCHCORE_H__
#define __PWCHCORE_H__

/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "processAudio_types.h"

/* Function Declarations */
extern void pwchcore(const emxArray_real_T *x, const emxArray_real_T *y, const
                     double s[2], emxArray_real_T *pp_breaks, double pp_coefs[4]);

#endif

/*
 * File trailer for pwchcore.h
 *
 * [EOF]
 */
