#ifndef _VECTOR_VECTOR_OPS_H
#define _VECTOR_VECTOR_OPS_H

#include <blas_types.h>

extern double *axpy_no_alpha(double *x, double *y, ll n);
extern double *axpy(double a, double *x, double *y, ll n);
extern double *copy(double *a, ll n);
extern double dot(double *a, double *b, ll n);
extern double nrm2(double *a, ll n);
extern double *scal(double *x, double a, ll n);
extern void swap(double *a, double *b, ll n);
extern double assum(double *a, ll n);
extern double iamax(double *a, ll n);

#endif
