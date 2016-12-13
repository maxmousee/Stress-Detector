/*
 * find.h
 *
 * Code generation for function 'find'
 *
 */

#ifndef FIND_H
#define FIND_H

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
extern void eml_find(const emlrtStack *sp, const boolean_T x_data[], const
                     int32_T x_size[2], int32_T i_data[], int32_T i_size[2]);

#endif

/* End of code generation (find.h) */
