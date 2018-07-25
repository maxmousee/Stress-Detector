/*
 * File: vsd_rtwutil.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 24-Jul-2018 00:37:24
 */

#ifndef VSD_RTWUTIL_H
#define VSD_RTWUTIL_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "omp.h"
#include "vsd_types.h"

/* Function Declarations */
extern void emlrtFreeThreadStackData(void);
extern vsdTLS *emlrtGetThreadStackData(void);
extern void emlrtInitThreadStackData(void);

#endif

/*
 * File trailer for vsd_rtwutil.h
 *
 * [EOF]
 */
