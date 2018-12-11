/*
 * File: bluesteinSetup.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jul-2018 23:11:40
 */

/* Include Files */
#include <math.h>
#include "rt_nonfinite.h"
#include "vsd.h"
#include "bluesteinSetup.h"

/* Function Definitions */

/*
 * Arguments    : creal_T wwc[15999]
 * Return Type  : void
 */
void bluesteinSetup(creal_T wwc[15999])
{
  int idx;
  int rt;
  int k;
  int y;
  double nt_im;
  double nt_re;
  idx = 7998;
  rt = 0;
  wwc[7999].re = 1.0;
  wwc[7999].im = 0.0;
  for (k = 0; k < 7999; k++) {
    y = ((k + 1) << 1) - 1;
    if (16000 - rt <= y) {
      rt = (y + rt) - 16000;
    } else {
      rt += y;
    }

    nt_im = -3.1415926535897931 * (double)rt / 8000.0;
    if (nt_im == 0.0) {
      nt_re = 1.0;
      nt_im = 0.0;
    } else {
      nt_re = cos(nt_im);
      nt_im = sin(nt_im);
    }

    wwc[idx].re = nt_re;
    wwc[idx].im = -nt_im;
    idx--;
  }

  idx = 0;
  for (k = 7998; k >= 0; k--) {
    wwc[k + 8000] = wwc[idx];
    idx++;
  }
}

/*
 * File trailer for bluesteinSetup.c
 *
 * [EOF]
 */
