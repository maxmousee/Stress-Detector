/*
 * emd.h
 *
 * Code generation for function 'emd'
 *
 */

#ifndef EMD_H
#define EMD_H

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
extern void emd(vsdStackData *SD, const emlrtStack *sp, const real_T x[8000],
                real_T imf_data[], int32_T imf_size[2]);

#endif

/* End of code generation (emd.h) */
