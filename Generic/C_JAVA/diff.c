/*
 * File: diff.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jul-2018 23:11:40
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "diff.h"

/* Function Definitions */

/*
 * Arguments    : const boolean_T x[7999]
 *                double y[7998]
 * Return Type  : void
 */
void b_diff(const boolean_T x[7999], double y[7998])
{
  int ixLead;
  int iyLead;
  int work;
  int m;
  int tmp1;
  ixLead = 1;
  iyLead = 0;
  work = x[0];
  for (m = 0; m < 7998; m++) {
    tmp1 = work;
    work = x[ixLead];
    tmp1 = x[ixLead] - tmp1;
    ixLead++;
    y[iyLead] = tmp1;
    iyLead++;
  }
}

/*
 * Arguments    : const double x[8000]
 *                double y[7999]
 * Return Type  : void
 */
void diff(const double x[8000], double y[7999])
{
  int ixLead;
  int iyLead;
  double work;
  int m;
  double tmp1;
  ixLead = 1;
  iyLead = 0;
  work = x[0];
  for (m = 0; m < 7999; m++) {
    tmp1 = work;
    work = x[ixLead];
    tmp1 = x[ixLead] - tmp1;
    ixLead++;
    y[iyLead] = tmp1;
    iyLead++;
  }
}

/*
 * File trailer for diff.c
 *
 * [EOF]
 */
