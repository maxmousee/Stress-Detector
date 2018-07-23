/*
 * File: vsd_terminate.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 24-Jul-2018 00:37:24
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "vsd_terminate.h"
#include "vsd_rtwutil.h"
#include "vsd_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void vsd_terminate(void)
{
  emlrtFreeThreadStackData();
  omp_destroy_nest_lock(&emlrtNestLockGlobal);
}

/*
 * File trailer for vsd_terminate.c
 *
 * [EOF]
 */
