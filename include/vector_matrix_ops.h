#ifndef _VECTOR_MATRIX_OPS_H
#define _VECTOR_MATRIX_OPS_H

#include <blas_types.h>

double **copy_mat(double **a, ll m, ll n);

double *simplified_dgemv_row(double **a, double *x, double *y, ll m, ll n);
double *simplified_dgemv_col(double **a, double *x, double *y, ll m, ll n);

void simplified_dger_row(double **a, double *x, double *y, ll m, ll n);
void simplified_dger_col(double **a, double *x, double *y, ll m, ll n);

#endif
