/*
 * _coder_myRANSAC_api.c
 *
 * Code generation for function '_coder_myRANSAC_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myRANSAC.h"
#include "_coder_myRANSAC_api.h"
#include "myRANSAC_emxutil.h"
#include "myRANSAC_data.h"

/* Variable Definitions */
static emlrtRTEInfo g_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_myRANSAC_api",               /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real32_T *y);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *MaxIterations, const char_T *identifier);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real32_T *ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *x, const
  char_T *identifier, emxArray_real32_T *y);
static const mxArray *emlrt_marshallOut(const boolean_T u_data[], const int32_T
  u_size[2]);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real32_T *y)
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *MaxIterations, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(MaxIterations), &thisId);
  emlrtDestroyArray(&MaxIterations);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real32_T *ret)
{
  static const int32_T dims[2] = { 1, 34816 };

  const boolean_T bv0[2] = { false, true };

  int32_T iv3[2];
  int32_T i7;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "single", false, 2U, dims, &bv0[0],
    iv3);
  ret->allocatedSize = iv3[0] * iv3[1];
  i7 = ret->size[0] * ret->size[1];
  ret->size[0] = iv3[0];
  ret->size[1] = iv3[1];
  emxEnsureCapacity_real32_T(sp, ret, i7, (emlrtRTEInfo *)NULL);
  ret->data = (real32_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *x, const
  char_T *identifier, emxArray_real32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(x), &thisId, y);
  emlrtDestroyArray(&x);
}

static const mxArray *emlrt_marshallOut(const boolean_T u_data[], const int32_T
  u_size[2])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv2[2] = { 0, 0 };

  y = NULL;
  m0 = emlrtCreateLogicalArray(2, iv2);
  emlrtMxSetData((mxArray *)m0, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m0, u_size, 2);
  emlrtAssign(&y, m0);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void myRANSAC_api(const mxArray * const prhs[5], int32_T nlhs, const mxArray
                  *plhs[1])
{
  boolean_T (*idx_inliers_saved_data)[34816];
  emxArray_real32_T *x;
  emxArray_real32_T *y;
  emxArray_real32_T *z;
  real_T MaxIterations;
  real_T distanceTol;
  int32_T idx_inliers_saved_size[2];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  idx_inliers_saved_data = (boolean_T (*)[34816])mxMalloc(sizeof(boolean_T
    [34816]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real32_T(&st, &x, 2, &g_emlrtRTEI, true);
  emxInit_real32_T(&st, &y, 2, &g_emlrtRTEI, true);
  emxInit_real32_T(&st, &z, 2, &g_emlrtRTEI, true);

  /* Marshall function inputs */
  x->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "x", x);
  y->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "y", y);
  z->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "z", z);
  MaxIterations = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "MaxIterations");
  distanceTol = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "distanceTol");

  /* Invoke the target function */
  myRANSAC(&st, x, y, z, MaxIterations, distanceTol, *idx_inliers_saved_data,
           idx_inliers_saved_size);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*idx_inliers_saved_data, idx_inliers_saved_size);
  emxFree_real32_T(&z);
  emxFree_real32_T(&y);
  emxFree_real32_T(&x);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_myRANSAC_api.c) */
