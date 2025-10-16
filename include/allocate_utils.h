#ifndef _ALLOCATE_UTILS_H_
#define _ALLOCATE_UTILS_H_

#include <blas_types.h>

double *vec_double_init_linspace(ll n);
double *vec_double_init_rand(ll n);

double **mat_double_init_linspace(ll m, ll n);
double **mat_double_init_rand(ll m, ll n);

#endif
