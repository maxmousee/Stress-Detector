/*
 * File: vsd_rtwutil.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 24-Jul-2018 00:37:24
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd_rtwutil.h"

/* Variable Definitions */
static vsdTLS *vsdTLSGlobal;

#pragma omp threadprivate (vsdTLSGlobal)

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void emlrtFreeThreadStackData(void)
{
  int i;

#pragma omp parallel for schedule(static)\
 num_threads(omp_get_max_threads())

  for (i = 1; i <= omp_get_max_threads(); i++) {
    free(vsdTLSGlobal);
  }
}

/*
 * Arguments    : void
 * Return Type  : vsdTLS *
 */
vsdTLS *emlrtGetThreadStackData(void)
{
  return vsdTLSGlobal;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void emlrtInitThreadStackData(void)
{
  int i;

#pragma omp parallel for schedule(static)\
 num_threads(omp_get_max_threads())

  for (i = 1; i <= omp_get_max_threads(); i++) {
    vsdTLSGlobal = (vsdTLS *)malloc(1U * sizeof(vsdTLS));
  }
}

/*
 * File trailer for vsd_rtwutil.c
 *
 * [EOF]
 */
