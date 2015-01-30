/*
 * File: pwchcore.c
 *
 * MATLAB Coder version            : 2.6
 * C/C++ source code generated on  : 06-Jun-2014 20:32:45
 */

/* Include files */
#include "processAudio.h"
#include "pwchcore.h"
#include "processAudio_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                const emxArray_real_T *y
 *                const double s[2]
 *                emxArray_real_T *pp_breaks
 *                double pp_coefs[4]
 * Return Type  : void
 */
void pwchcore(const emxArray_real_T *x, const emxArray_real_T *y, const double
              s[2], emxArray_real_T *pp_breaks, double pp_coefs[4])
{
  int x_idx_0;
  int i1;
  double dxj;
  double divdifij;
  double dzzdx;
  x_idx_0 = x->size[1];
  i1 = pp_breaks->size[0] * pp_breaks->size[1];
  pp_breaks->size[0] = 1;
  pp_breaks->size[1] = x_idx_0;
  emxEnsureCapacity((emxArray__common *)pp_breaks, i1, (int)sizeof(double));
  for (i1 = 0; i1 < x_idx_0; i1++) {
    pp_breaks->data[pp_breaks->size[0] * i1] = x->data[i1];
  }

  for (x_idx_0 = 1; x_idx_0 < x->size[1]; x_idx_0++) {
    dxj = x->data[x_idx_0] - x->data[x_idx_0 - 1];
    divdifij = (y->data[x_idx_0 + 1] - y->data[x_idx_0]) / dxj;
    dzzdx = (divdifij - s[x_idx_0 - 1]) / dxj;
    divdifij = (s[x_idx_0] - divdifij) / dxj;
    pp_coefs[x_idx_0 - 1] = (divdifij - dzzdx) / dxj;
    pp_coefs[x_idx_0] = 2.0 * dzzdx - divdifij;
    pp_coefs[x_idx_0 + 1] = s[x_idx_0 - 1];
    pp_coefs[3] = y->data[x_idx_0];
  }
}

/*
 * File trailer for pwchcore.c
 *
 * [EOF]
 */
