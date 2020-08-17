/*
 * myRANSAC.c
 *
 * Code generation for function 'myRANSAC'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "myRANSAC.h"
#include "sum.h"
#include "randi.h"
#include "abs.h"
#include "myRANSAC_emxutil.h"
#include "sqrt.h"
#include "myRANSAC_data.h"

/* Variable Definitions */
static emlrtRSInfo g_emlrtRSI = { 59,  /* lineNo */
  "myRANSAC",                          /* fcnName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 59,  /* lineNo */
  13,                                  /* colNo */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 59,/* lineNo */
  19,                                  /* colNo */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 59,/* lineNo */
  25,                                  /* colNo */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 59,/* lineNo */
  9,                                   /* colNo */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 1, /* lineNo */
  31,                                  /* colNo */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 5, /* lineNo */
  11,                                  /* colNo */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 13,    /* lineNo */
  19,                                  /* colNo */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  19,                                  /* colNo */
  "x",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  34,                                  /* colNo */
  "y",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  49,                                  /* colNo */
  "z",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 17,  /* lineNo */
  19,                                  /* colNo */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  19,                                  /* colNo */
  "x",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  34,                                  /* colNo */
  "y",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  17,                                  /* lineNo */
  49,                                  /* colNo */
  "z",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 21,  /* lineNo */
  19,                                  /* colNo */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  19,                                  /* colNo */
  "x",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  34,                                  /* colNo */
  "y",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  21,                                  /* lineNo */
  49,                                  /* colNo */
  "z",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  27,                                  /* lineNo */
  12,                                  /* colNo */
  "x",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  28,                                  /* lineNo */
  12,                                  /* colNo */
  "y",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  29,                                  /* lineNo */
  12,                                  /* colNo */
  "z",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  32,                                  /* lineNo */
  12,                                  /* colNo */
  "x",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  33,                                  /* lineNo */
  12,                                  /* colNo */
  "y",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  34,                                  /* lineNo */
  12,                                  /* colNo */
  "z",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  37,                                  /* lineNo */
  12,                                  /* colNo */
  "x",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  12,                                  /* colNo */
  "y",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  12,                                  /* colNo */
  "z",                                 /* aName */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  59,                                  /* lineNo */
  13,                                  /* colNo */
  "myRANSAC",                          /* fName */
  "C:\\Users\\IanAlferez\\Documents\\MATLAB\\Examples\\R2019a\\driving\\GroundPlaneAndObstacleDetectionUsingLidarExample\\myRANSAC.m"/* pName */
};

/* Function Definitions */
void myRANSAC(const emlrtStack *sp, const emxArray_real32_T *x, const
              emxArray_real32_T *y, const emxArray_real32_T *z, real_T
              MaxIterations, real_T distanceTol, boolean_T
              idx_inliers_saved_data[], int32_T idx_inliers_saved_size[2])
{
  real_T sizeOfliners;
  int32_T loop_ub;
  int32_T i0;
  emxArray_real32_T *r0;
  emxArray_real32_T *r1;
  emxArray_real32_T *r2;
  emxArray_real32_T *r3;
  int32_T cnt;
  real_T pt1;
  real_T pt2;
  real_T pt3;
  int32_T exitg1;
  int32_T i1;
  boolean_T guard1 = false;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  real32_T v1_1;
  real32_T v1_2;
  real32_T v1_3;
  real32_T v2_1;
  real32_T C;
  real32_T A;
  real32_T B;
  int32_T iv0[2];
  int32_T iv1[2];
  int32_T idx_inliers_size[2];
  boolean_T idx_inliers_data[34816];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  sizeOfliners = 0.0;
  idx_inliers_saved_size[0] = 1;
  idx_inliers_saved_size[1] = x->size[1];
  loop_ub = x->size[1];
  if (0 <= loop_ub - 1) {
    memset(&idx_inliers_saved_data[0], 0, (uint32_T)(loop_ub * (int32_T)sizeof
            (boolean_T)));
  }

  i0 = (int32_T)MaxIterations;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, MaxIterations, mxDOUBLE_CLASS,
    (int32_T)MaxIterations, &h_emlrtRTEI, sp);
  emxInit_real32_T(sp, &r0, 2, &d_emlrtRTEI, true);
  emxInit_real32_T(sp, &r1, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &r2, 2, &e_emlrtRTEI, true);
  emxInit_real32_T(sp, &r3, 2, &emlrtRTEI, true);
  for (cnt = 0; cnt < i0; cnt++) {
    pt1 = randi(x->size[1]);
    pt2 = randi(x->size[1]);
    pt3 = randi(x->size[1]);

    /* Some of the data are NaN, if it is so i will generate another random */
    /* value to pick for that specific point. I would assume that in real */
    /* world scenario this has been already filtered out. */
    do {
      exitg1 = 0;
      if (pt1 != (int32_T)muDoubleScalarFloor(pt1)) {
        emlrtIntegerCheckR2012b(pt1, &emlrtDCI, sp);
      }

      i1 = x->size[1];
      loop_ub = (int32_T)pt1;
      if ((loop_ub < 1) || (loop_ub > i1)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, &emlrtBCI, sp);
      }

      i1 = loop_ub - 1;
      guard1 = false;
      if (muSingleScalarIsNaN(x->data[i1])) {
        guard1 = true;
      } else {
        i2 = y->size[1];
        if ((loop_ub < 1) || (loop_ub > i2)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, &b_emlrtBCI, sp);
        }

        if (muSingleScalarIsNaN(y->data[i1])) {
          guard1 = true;
        } else {
          i2 = z->size[1];
          if ((loop_ub < 1) || (loop_ub > i2)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i2, &c_emlrtBCI, sp);
          }

          if (muSingleScalarIsNaN(z->data[i1])) {
            guard1 = true;
          } else {
            exitg1 = 1;
          }
        }
      }

      if (guard1) {
        pt1 = randi(x->size[1]);

        /* display([x(pt1) y(pt1) z(pt1)]); */
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    } while (exitg1 == 0);

    do {
      exitg1 = 0;
      if (pt2 != (int32_T)muDoubleScalarFloor(pt2)) {
        emlrtIntegerCheckR2012b(pt2, &b_emlrtDCI, sp);
      }

      i2 = x->size[1];
      i3 = (int32_T)pt2;
      if ((i3 < 1) || (i3 > i2)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &d_emlrtBCI, sp);
      }

      i2 = i3 - 1;
      guard1 = false;
      if (muSingleScalarIsNaN(x->data[i2])) {
        guard1 = true;
      } else {
        i4 = y->size[1];
        if ((i3 < 1) || (i3 > i4)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, i4, &e_emlrtBCI, sp);
        }

        if (muSingleScalarIsNaN(y->data[i2])) {
          guard1 = true;
        } else {
          i4 = z->size[1];
          if ((i3 < 1) || (i3 > i4)) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, i4, &f_emlrtBCI, sp);
          }

          if (muSingleScalarIsNaN(z->data[i2])) {
            guard1 = true;
          } else {
            exitg1 = 1;
          }
        }
      }

      if (guard1) {
        pt2 = randi(x->size[1]);

        /* display([x(pt2) y(pt2) z(pt2)]); */
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    } while (exitg1 == 0);

    do {
      exitg1 = 0;
      if (pt3 != (int32_T)muDoubleScalarFloor(pt3)) {
        emlrtIntegerCheckR2012b(pt3, &c_emlrtDCI, sp);
      }

      i4 = x->size[1];
      i5 = (int32_T)pt3;
      if ((i5 < 1) || (i5 > i4)) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, i4, &g_emlrtBCI, sp);
      }

      i4 = i5 - 1;
      guard1 = false;
      if (muSingleScalarIsNaN(x->data[i4])) {
        guard1 = true;
      } else {
        i6 = y->size[1];
        if ((i5 < 1) || (i5 > i6)) {
          emlrtDynamicBoundsCheckR2012b(i5, 1, i6, &h_emlrtBCI, sp);
        }

        if (muSingleScalarIsNaN(y->data[i4])) {
          guard1 = true;
        } else {
          i6 = z->size[1];
          if ((i5 < 1) || (i5 > i6)) {
            emlrtDynamicBoundsCheckR2012b(i5, 1, i6, &i_emlrtBCI, sp);
          }

          if (muSingleScalarIsNaN(z->data[i4])) {
            guard1 = true;
          } else {
            exitg1 = 1;
          }
        }
      }

      if (guard1) {
        pt3 = randi(x->size[1]);

        /* display([x(pt3) y(pt3) z(pt3)]); */
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }
    } while (exitg1 == 0);

    /*  assign point 1 */
    i6 = x->size[1];
    if ((loop_ub < 1) || (loop_ub > i6)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i6, &j_emlrtBCI, sp);
    }

    i6 = y->size[1];
    if ((loop_ub < 1) || (loop_ub > i6)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i6, &k_emlrtBCI, sp);
    }

    i6 = z->size[1];
    if ((loop_ub < 1) || (loop_ub > i6)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i6, &l_emlrtBCI, sp);
    }

    /*  assign point 2 */
    loop_ub = x->size[1];
    if ((i3 < 1) || (i3 > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, loop_ub, &m_emlrtBCI, sp);
    }

    loop_ub = y->size[1];
    if ((i3 < 1) || (i3 > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, loop_ub, &n_emlrtBCI, sp);
    }

    loop_ub = z->size[1];
    if ((i3 < 1) || (i3 > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(i3, 1, loop_ub, &o_emlrtBCI, sp);
    }

    /*  assign point 3 */
    loop_ub = x->size[1];
    if ((i5 < 1) || (i5 > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, loop_ub, &p_emlrtBCI, sp);
    }

    loop_ub = y->size[1];
    if ((i5 < 1) || (i5 > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, loop_ub, &q_emlrtBCI, sp);
    }

    loop_ub = z->size[1];
    if ((i5 < 1) || (i5 > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(i5, 1, loop_ub, &r_emlrtBCI, sp);
    }

    /* display([x1 y1 z1]) */
    /* display([x2 y2 z2]) */
    /* display([x3 y3 z3]) */
    v1_1 = x->data[i2] - x->data[i1];
    v1_2 = y->data[i2] - y->data[i1];
    v1_3 = z->data[i2] - z->data[i1];
    v2_1 = x->data[i4] - x->data[i1];
    C = v1_2 * v1_3;
    A = C - C;
    B = v1_1 * (z->data[i4] - z->data[i1]) - v1_3 * v2_1;
    C = v1_1 * (y->data[i4] - y->data[i1]) - v1_2 * v2_1;
    v1_3 = (A * x->data[i1] + B * y->data[i1]) + C * z->data[i1];
    i1 = r0->size[0] * r0->size[1];
    r0->size[0] = 1;
    r0->size[1] = x->size[1];
    emxEnsureCapacity_real32_T(sp, r0, i1, &emlrtRTEI);
    loop_ub = x->size[0] * x->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      r0->data[i1] = A * x->data[i1];
    }

    i1 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = y->size[1];
    emxEnsureCapacity_real32_T(sp, r1, i1, &b_emlrtRTEI);
    loop_ub = y->size[0] * y->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1->data[i1] = B * y->data[i1];
    }

    iv0[0] = r0->size[0];
    iv0[1] = r0->size[1];
    iv1[0] = r1->size[0];
    iv1[1] = r1->size[1];
    if ((iv0[0] != iv1[0]) || (iv0[1] != iv1[1])) {
      emlrtSizeEqCheckNDR2012b(&iv0[0], &iv1[0], &emlrtECI, sp);
    }

    i1 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = z->size[1];
    emxEnsureCapacity_real32_T(sp, r2, i1, &c_emlrtRTEI);
    loop_ub = z->size[0] * z->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      r2->data[i1] = C * z->data[i1];
    }

    iv0[0] = r0->size[0];
    iv0[1] = r0->size[1];
    iv1[0] = r2->size[0];
    iv1[1] = r2->size[1];
    if ((iv0[0] != iv1[0]) || (iv0[1] != iv1[1])) {
      emlrtSizeEqCheckNDR2012b(&iv0[0], &iv1[0], &emlrtECI, sp);
    }

    C = (A * A + B * B) + C * C;
    st.site = &g_emlrtRSI;
    b_sqrt(&st, &C);

    /*  Easy vector operation by MATLAB */
    i1 = r3->size[0] * r3->size[1];
    r3->size[0] = 1;
    r3->size[1] = r0->size[1];
    emxEnsureCapacity_real32_T(sp, r3, i1, &emlrtRTEI);
    loop_ub = r0->size[0] * r0->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      r3->data[i1] = ((r0->data[i1] + r1->data[i1]) + r2->data[i1]) + -v1_3;
    }

    b_abs(sp, r3, r0);
    idx_inliers_size[0] = 1;
    idx_inliers_size[1] = r0->size[1];
    loop_ub = r0->size[0] * r0->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      idx_inliers_data[i1] = (r0->data[i1] / C <= distanceTol);
    }

    /*  This will try to record the who among the MaxIterations holds the */
    /*  most number of inliers. */
    if (sizeOfliners < sum(idx_inliers_data, idx_inliers_size)) {
      sizeOfliners = sum(idx_inliers_data, idx_inliers_size);
      idx_inliers_saved_size[0] = 1;
      idx_inliers_saved_size[1] = idx_inliers_size[1];
      if (0 <= idx_inliers_size[1] - 1) {
        memcpy(&idx_inliers_saved_data[0], &idx_inliers_data[0], (uint32_T)
               (idx_inliers_size[1] * (int32_T)sizeof(boolean_T)));
      }

      /* display(sizeOfliners) */
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real32_T(&r3);
  emxFree_real32_T(&r2);
  emxFree_real32_T(&r1);
  emxFree_real32_T(&r0);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (myRANSAC.c) */
