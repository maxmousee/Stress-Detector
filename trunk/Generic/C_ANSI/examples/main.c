/*
 * File: main.c
 *
 * MATLAB Coder version            : 3.2
 * C/C++ source code generated on  : 16-Dec-2016 08:11:00
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include Files */
#include "rt_nonfinite.h"
#include "vsd.h"
#include "main.h"
#include "vsd_terminate.h"
#include "vsd_initialize.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
static void argInit_8000x1_real_T(double result[8000]);
static double argInit_real_T(void);
static void main_vsd(void);

/* Function Definitions */

/*
 * Arguments    : double result[8000]
 * Return Type  : void
 */
static void argInit_8000x1_real_T(double result[8000])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 8000; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_vsd(void)
{
  static double dv6[8000];
  double stressFreq;

  /* Initialize function 'vsd' input arguments. */
  /* Initialize function input argument 'input'. */
  /* Call the entry-point 'vsd'. */
  argInit_8000x1_real_T(dv6);
  stressFreq = vsd(dv6);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  vsd_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_vsd();

  /* Terminate the application.
     You do not need to do this more than one time. */
  vsd_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
