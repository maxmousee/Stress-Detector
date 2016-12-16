/*
 * File: _coder_vsd_api.h
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 13-Dec-2016 23:51:29
 */

#ifndef _CODER_VSD_API_H
#define _CODER_VSD_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_vsd_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real_T vsd(real_T input[8000]);
extern void vsd_api(const mxArray *prhs[1], const mxArray *plhs[1]);
extern void vsd_atexit(void);
extern void vsd_initialize(void);
extern void vsd_terminate(void);
extern void vsd_xil_terminate(void);

#endif

/*
 * File trailer for _coder_vsd_api.h
 *
 * [EOF]
 */
