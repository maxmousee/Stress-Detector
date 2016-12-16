/*
 * File: diff.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 16-Dec-2016 20:24:22
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "diff.h"

/* Function Definitions */

/*
 * Arguments    : const boolean_T x[8191]
 *                double y[8190]
 * Return Type  : void
 */
void b_diff(const boolean_T x[8191], double y[8190])
{
  int ixLead;
  int iyLead;
  int work;
  int m;
  int tmp2;
  ixLead = 1;
  iyLead = 0;
  work = x[0];
  for (m = 0; m < 8190; m++) {
    tmp2 = work;
    work = x[ixLead];
    tmp2 = x[ixLead] - tmp2;
    ixLead++;
    y[iyLead] = tmp2;
    iyLead++;
  }
}

/*
 * Arguments    : const double x[8192]
 *                double y[8191]
 * Return Type  : void
 */
void diff(const double x[8192], double y[8191])
{
  int ixLead;
  int iyLead;
  double work;
  int m;
  double tmp2;
  ixLead = 1;
  iyLead = 0;
  work = x[0];
  for (m = 0; m < 8191; m++) {
    tmp2 = work;
    work = x[ixLead];
    tmp2 = x[ixLead] - tmp2;
    ixLead++;
    y[iyLead] = tmp2;
    iyLead++;
  }
}

/*
 * File trailer for diff.c
 *
 * [EOF]
 */
