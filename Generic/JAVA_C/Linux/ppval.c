/*
 * File: ppval.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 24-Jul-2018 00:37:24
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "ppval.h"

/* Function Definitions */

/*
 * Arguments    : const struct_T *pp
 *                double v_data[]
 *                int v_size[2]
 * Return Type  : void
 */
void ppval(const struct_T *pp, double v_data[], int v_size[2])
{
  int numTerms;
  int coefStride;
  int ix;
  int low_i;
  int low_ip1;
  int high_i;
  double xloc;
  int mid_i;
  double v;
  numTerms = pp->coefs->size[2];
  coefStride = pp->breaks.size[1] - 1;
  v_size[0] = 1;
  v_size[1] = 8000;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(low_i,low_ip1,high_i,xloc,mid_i,v)

  for (ix = 1; ix < 8001; ix++) {
    low_i = 1;
    low_ip1 = 2;
    high_i = pp->breaks.size[1];
    while (high_i > low_ip1) {
      mid_i = (low_i >> 1) + (high_i >> 1);
      if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
        mid_i++;
      }

      if (1.0 + ((double)ix - 1.0) >= pp->breaks.data[mid_i - 1]) {
        low_i = mid_i;
        low_ip1 = mid_i + 1;
      } else {
        high_i = mid_i;
      }
    }

    xloc = (1.0 + ((double)ix - 1.0)) - pp->breaks.data[low_i - 1];
    v = pp->coefs->data[low_i - 1];
    for (low_ip1 = 2; low_ip1 <= numTerms; low_ip1++) {
      v = xloc * v + pp->coefs->data[(low_i + (low_ip1 - 1) * coefStride) - 1];
    }

    v_data[ix - 1] = v;
  }
}

/*
 * File trailer for ppval.c
 *
 * [EOF]
 */
