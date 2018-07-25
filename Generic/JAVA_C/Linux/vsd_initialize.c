/*
 * File: vsd_initialize.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 24-Jul-2018 00:37:24
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "vsd_initialize.h"
#include "vsd_rtwutil.h"
#include "vsd_data.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void vsd_initialize(void)
{
  rt_InitInfAndNaN(8U);
  omp_init_nest_lock(&emlrtNestLockGlobal);
  emlrtInitThreadStackData();
}

/*
 * File trailer for vsd_initialize.c
 *
 * [EOF]
 */
