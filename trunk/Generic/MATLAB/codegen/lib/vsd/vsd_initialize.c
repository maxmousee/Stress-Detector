/*
 * File: vsd_initialize.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 16-Dec-2016 08:11:00
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "vsd_initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void vsd_initialize(void)
{
  rt_InitInfAndNaN(8U);
}

/*
 * File trailer for vsd_initialize.c
 *
 * [EOF]
 */
