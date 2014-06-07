/*
 * File: emd.h
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 06-Jun-2014 20:32:45
 */

#ifndef __EMD_H__
#define __EMD_H__

/* Include files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "processAudio_types.h"

/* Function Declarations */
extern void emd(const double x[8192], emxArray_real_T *imf);
double simplp (double *x, double *y, int M, double xm1);

#endif

/*
 * File trailer for emd.h
 *
 * [EOF]
 */
