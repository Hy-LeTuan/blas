#ifndef _VECTOR_MATRIX_OPS_H
#define _VECTOR_MATRIX_OPS_H

#include <blas_types.h>

double *simplified_gemv_row(double **a, double *x, double *y, ll m, ll n);
double *simplified_gemv_col(double **a, double *x, double *y, ll m, ll n);

#endif
