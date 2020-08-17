/*
 * abs.h
 *
 * Code generation for function 'abs'
 *
 */

#ifndef ABS_H
#define ABS_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "myRANSAC_types.h"

/* Function Declarations */
extern void b_abs(const emlrtStack *sp, const emxArray_real32_T *x,
                  emxArray_real32_T *y);

#endif

/* End of code generation (abs.h) */
