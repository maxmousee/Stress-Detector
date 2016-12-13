/*
 * ppval.c
 *
 * Code generation for function 'ppval'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "ppval.h"
#include "bsearch.h"

/* Function Definitions */
void ppval(const real_T pp_breaks_data[], const int32_T pp_breaks_size[2], const
           emxArray_real_T *pp_coefs, real_T v_data[], int32_T v_size[2])
{
  int32_T numTerms;
  int32_T ix;
  int32_T ip;
  real_T xloc;
  real_T v;
  int32_T ic;
  numTerms = pp_coefs->size[2];
  for (ix = 0; ix < 2; ix++) {
    v_size[ix] = 1 + 7999 * ix;
  }

  for (ix = 0; ix < 8000; ix++) {
    ip = b_bsearch(pp_breaks_data, pp_breaks_size, 1.0 + (((real_T)ix + 1.0) -
      1.0)) - 1;
    xloc = (1.0 + (((real_T)ix + 1.0) - 1.0)) - pp_breaks_data[ip];
    v = pp_coefs->data[ip];
    for (ic = 2; ic <= numTerms; ic++) {
      v = xloc * v + pp_coefs->data[ip + (ic - 1) * (pp_breaks_size[1] - 1)];
    }

    v_data[ix] = v;
  }
}

/* End of code generation (ppval.c) */
