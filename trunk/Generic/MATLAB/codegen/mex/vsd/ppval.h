/*
 * ppval.h
 *
 * Code generation for function 'ppval'
 *
 */

#ifndef PPVAL_H
#define PPVAL_H

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
extern void ppval(const real_T pp_breaks_data[], const int32_T pp_breaks_size[2],
                  const emxArray_real_T *pp_coefs, real_T v_data[], int32_T
                  v_size[2]);

#endif

/* End of code generation (ppval.h) */
