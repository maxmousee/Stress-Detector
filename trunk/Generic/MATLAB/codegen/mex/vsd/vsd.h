/*
 * vsd.h
 *
 * Code generation for function 'vsd'
 *
 */

#ifndef VSD_H
#define VSD_H

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
extern real_T vsd(vsdStackData *SD, const emlrtStack *sp, const real_T input
                  [8000]);

#ifdef __WATCOMC__

#pragma aux vsd value [8087];

#endif
#endif

/* End of code generation (vsd.h) */
