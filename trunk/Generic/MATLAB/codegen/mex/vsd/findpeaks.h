/*
 * findpeaks.h
 *
 * Code generation for function 'findpeaks'
 *
 */

#ifndef FINDPEAKS_H
#define FINDPEAKS_H

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
extern void findpeaks(vsdStackData *SD, const emlrtStack *sp, const real_T x
                      [8000], real_T n_data[], int32_T n_size[2]);

#endif

/* End of code generation (findpeaks.h) */
