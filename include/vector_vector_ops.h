#ifndef _VECTOR_VECTOR_OPS_H
#define _VECTOR_VECTOR_OPS_H

#include <blas_types.h>

extern double *daxpy_no_alpha(double *x, double *y, ll n, ll stride_x, ll stride_y,
                              ll start_x, ll start_y);
extern double *daxpy(double a, double *x, double *y, ll n, ll stride_x, ll stride_y,
                     ll start_x, ll start_y);
extern double *dcopy(double *x, ll n, ll stride, ll start);
extern double ddot(double *x, double *y, ll n, ll stride_x, ll stride_y, ll start_x,
                   ll start_y);
extern double dapdots(double alpha, double *x, double *y, ll n, ll stride_x,
                      ll stride_y, ll start_x, ll start_y);
extern double dnrm2(double *x, ll n, ll stride, ll start);
extern double *dscal(double *x, double a, ll n, ll stride, ll start);
extern void dswap(double *x, double *y, ll n, ll stride_x, ll stride_y, ll start_x,
                  ll start_y);

#endif
