/*
 * File: _coder_vsd_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jul-2018 23:11:40
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
extern real_T vsd(real_T input_data[], int32_T input_size[1]);
extern void vsd_api(const mxArray * const prhs[1], int32_T nlhs, const mxArray
                    *plhs[1]);
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
