/*
 * File: vsd_types.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 24-Jul-2018 00:37:24
 */

#ifndef VSD_TYPES_H
#define VSD_TYPES_H

/* Include Files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T

typedef struct {
  creal_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;

#endif                                 /*typedef_emxArray_creal_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef struct_emxArray_real_T_1x8000
#define struct_emxArray_real_T_1x8000

struct emxArray_real_T_1x8000
{
  double data[8000];
  int size[2];
};

#endif                                 /*struct_emxArray_real_T_1x8000*/

#ifndef typedef_emxArray_real_T_1x8000
#define typedef_emxArray_real_T_1x8000

typedef struct emxArray_real_T_1x8000 emxArray_real_T_1x8000;

#endif                                 /*typedef_emxArray_real_T_1x8000*/

#ifndef struct_sE5k0Bq4rnfLTx4XGqYSBmC_tag
#define struct_sE5k0Bq4rnfLTx4XGqYSBmC_tag

struct sE5k0Bq4rnfLTx4XGqYSBmC_tag
{
  emxArray_real_T_1x8000 breaks;
  emxArray_real_T *coefs;
};

#endif                                 /*struct_sE5k0Bq4rnfLTx4XGqYSBmC_tag*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct sE5k0Bq4rnfLTx4XGqYSBmC_tag struct_T;

#endif                                 /*typedef_struct_T*/

#ifndef typedef_vsdTLS
#define typedef_vsdTLS

typedef struct {
  struct {
    creal_T fv[16384];
    creal_T dcv0[16384];
    creal_T b_fv[16384];
  } f0;

  struct {
    creal_T rwork[8000];
  } f1;
} vsdTLS;

#endif                                 /*typedef_vsdTLS*/
#endif

/*
 * File trailer for vsd_types.h
 *
 * [EOF]
 */
