#ifndef _VECTOR_VECTOR_OPS_H
#define _VECTOR_VECTOR_OPS_H

#include <blas_types.h>

extern double *daxpy_no_alpha(double *x, double *y, ll n);
extern double *daxpy(double a, double *x, double *y, ll n);
extern double *dcopy(double *a, ll n);
extern double ddot(double *a, double *b, ll n);
extern double dapdots(double alpha, double *x, double *y, ll n);
extern double dnrm2(double *a, ll n);
extern double *dscal(double *x, double a, ll n);
extern void dswap(double *a, double *b, ll n);
extern double dassum(double *a, ll n);
extern double diamax(double *a, ll n);

#endif
