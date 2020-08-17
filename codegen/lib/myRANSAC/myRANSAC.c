/*
 * File: myRANSAC.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 25-Aug-2019 11:14:33
 */

/* Include Files */
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "myRANSAC.h"
#include "myRANSAC_emxutil.h"
#include "rand.h"
#include "sum.h"
#include "abs.h"
#include "sqrt.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real32_T *x
 *                const emxArray_real32_T *y
 *                const emxArray_real32_T *z
 *                double MaxIterations
 *                double distanceTol
 *                bool idx_inliers_saved_data[]
 *                int idx_inliers_saved_size[2]
 * Return Type  : void
 */
void myRANSAC(const emxArray_real32_T *x, const emxArray_real32_T *y, const
              emxArray_real32_T *z, double MaxIterations, double distanceTol,
              bool idx_inliers_saved_data[], int idx_inliers_saved_size[2])
{
  double sizeOfliners;
  int loop_ub;
  int i0;
  emxArray_real32_T *r0;
  emxArray_real32_T *A;
  int cnt;
  double pt1;
  double pt2;
  double pt3;
  int exitg1;
  int i1;
  int i2;
  float v1_1;
  float v1_2;
  float v1_3;
  float v2_1;
  float C;
  float b_A;
  float B;
  int idx_inliers_size[2];
  bool idx_inliers_data[34816];
  sizeOfliners = 0.0;
  idx_inliers_saved_size[0] = 1;
  idx_inliers_saved_size[1] = x->size[1];
  loop_ub = x->size[1];
  if (0 <= loop_ub - 1) {
    memset(&idx_inliers_saved_data[0], 0, (unsigned int)(loop_ub * (int)sizeof
            (bool)));
  }

  i0 = (int)MaxIterations;
  emxInit_real32_T(&r0, 2);
  emxInit_real32_T(&A, 2);
  for (cnt = 0; cnt < i0; cnt++) {
    pt1 = b_rand();
    pt1 = 1.0 + floor(pt1 * (double)x->size[1]);
    pt2 = b_rand();
    pt2 = 1.0 + floor(pt2 * (double)x->size[1]);
    pt3 = b_rand();
    pt3 = 1.0 + floor(pt3 * (double)x->size[1]);

    /* Some of the data are NaN, if it is so i will generate another random */
    /* value to pick for that specific point. I would assume that in real */
    /* world scenario this has been already filtered out. */
    do {
      exitg1 = 0;
      i1 = (int)pt1 - 1;
      if (rtIsNaNF(x->data[i1]) || rtIsNaNF(y->data[i1]) || rtIsNaNF(z->data[i1]))
      {
        pt1 = b_rand();
        pt1 = 1.0 + floor(pt1 * (double)x->size[1]);

        /* display([x(pt1) y(pt1) z(pt1)]); */
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    do {
      exitg1 = 0;
      loop_ub = (int)pt2 - 1;
      if (rtIsNaNF(x->data[loop_ub]) || rtIsNaNF(y->data[loop_ub]) || rtIsNaNF
          (z->data[loop_ub])) {
        pt2 = b_rand();
        pt2 = 1.0 + floor(pt2 * (double)x->size[1]);

        /* display([x(pt2) y(pt2) z(pt2)]); */
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    do {
      exitg1 = 0;
      i2 = (int)pt3 - 1;
      if (rtIsNaNF(x->data[i2]) || rtIsNaNF(y->data[i2]) || rtIsNaNF(z->data[i2]))
      {
        pt3 = b_rand();
        pt3 = 1.0 + floor(pt3 * (double)x->size[1]);

        /* display([x(pt3) y(pt3) z(pt3)]); */
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    /*  assign point 1 */
    /*  assign point 2 */
    /*  assign point 3 */
    /* display([x1 y1 z1]) */
    /* display([x2 y2 z2]) */
    /* display([x3 y3 z3]) */
    v1_1 = x->data[loop_ub] - x->data[i1];
    v1_2 = y->data[loop_ub] - y->data[i1];
    v1_3 = z->data[loop_ub] - z->data[i1];
    v2_1 = x->data[i2] - x->data[i1];
    C = v1_2 * v1_3;
    b_A = C - C;
    B = v1_1 * (z->data[i2] - z->data[i1]) - v1_3 * v2_1;
    C = v1_1 * (y->data[i2] - y->data[i1]) - v1_2 * v2_1;
    v1_3 = (b_A * x->data[i1] + B * y->data[i1]) + C * z->data[i1];
    v1_1 = (b_A * b_A + B * B) + C * C;
    b_sqrt(&v1_1);

    /*  Easy vector operation by MATLAB */
    i1 = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = x->size[1];
    emxEnsureCapacity_real32_T(A, i1);
    loop_ub = x->size[0] * x->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      A->data[i1] = ((b_A * x->data[i1] + B * y->data[i1]) + C * z->data[i1]) +
        -v1_3;
    }

    b_abs(A, r0);
    idx_inliers_size[0] = 1;
    idx_inliers_size[1] = r0->size[1];
    loop_ub = r0->size[0] * r0->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      idx_inliers_data[i1] = (r0->data[i1] / v1_1 <= distanceTol);
    }

    /*  This will try to record the who among the MaxIterations holds the */
    /*  most number of inliers. */
    pt1 = sum(idx_inliers_data, idx_inliers_size);
    if (sizeOfliners < pt1) {
      sizeOfliners = pt1;
      idx_inliers_saved_size[0] = 1;
      idx_inliers_saved_size[1] = idx_inliers_size[1];
      if (0 <= idx_inliers_size[1] - 1) {
        memcpy(&idx_inliers_saved_data[0], &idx_inliers_data[0], (unsigned int)
               (idx_inliers_size[1] * (int)sizeof(bool)));
      }

      /* display(sizeOfliners) */
    }
  }

  emxFree_real32_T(&A);
  emxFree_real32_T(&r0);
}

/*
 * File trailer for myRANSAC.c
 *
 * [EOF]
 */
