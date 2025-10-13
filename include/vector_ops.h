#ifndef _VECTOR_OPS_H
#define _VECTOR_OPS_H

typedef long long ll;

extern double *axpy(double *a, double x, double y, ll n);
extern double *copy(double *a, ll n);
extern double dot(double *a, double *b, ll n);
extern double nrm2(double *a, ll n);
extern double *scale(double *a, double x, ll n);
extern void swap(double *a, double *b, ll n);
extern double assum(double *a, ll n);
extern double *iamax(double *a, ll n);

#endif
