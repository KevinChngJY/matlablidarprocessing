/*
 * File: main.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 25-Aug-2019 11:14:33
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
#include "myRANSAC.h"
#include "main.h"
#include "myRANSAC_terminate.h"
#include "myRANSAC_emxAPI.h"
#include "myRANSAC_initialize.h"

/* Function Declarations */
static emxArray_real32_T *argInit_1xd34816_real32_T(void);
static float argInit_real32_T(void);
static double argInit_real_T(void);
static void main_myRANSAC(void);

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : emxArray_real32_T *
 */
static emxArray_real32_T *argInit_1xd34816_real32_T(void)
{
  emxArray_real32_T *result;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_real32_T(1, 2);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx1] = argInit_real32_T();
  }

  return result;
}

/*
 * Arguments    : void
 * Return Type  : float
 */
static float argInit_real32_T(void)
{
  return 0.0F;
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
static void main_myRANSAC(void)
{
  emxArray_real32_T *x;
  emxArray_real32_T *y;
  emxArray_real32_T *z;
  bool idx_inliers_saved_data[34816];
  int idx_inliers_saved_size[2];

  /* Initialize function 'myRANSAC' input arguments. */
  /* Initialize function input argument 'x'. */
  x = argInit_1xd34816_real32_T();

  /* Initialize function input argument 'y'. */
  y = argInit_1xd34816_real32_T();

  /* Initialize function input argument 'z'. */
  z = argInit_1xd34816_real32_T();

  /* Call the entry-point 'myRANSAC'. */
  myRANSAC(x, y, z, argInit_real_T(), argInit_real_T(), idx_inliers_saved_data,
           idx_inliers_saved_size);
  emxDestroyArray_real32_T(z);
  emxDestroyArray_real32_T(y);
  emxDestroyArray_real32_T(x);
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
  myRANSAC_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_myRANSAC();

  /* Terminate the application.
     You do not need to do this more than one time. */
  myRANSAC_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
