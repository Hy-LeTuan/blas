#ifndef _VECTOR_MATRIX_OPS_TEST_H_
#define _VECTOR_MATRIX_OPS_TEST_H_

#include <blas_types.h>

void simplified_gemv_row_array_test(ll m, ll n);
void simplified_gemv_col_array_test(ll m, ll n);

void simplified_gemv_col_test(ll m, ll n);
void simplified_gemv_row_test(ll m, ll n);

void simplified_dger_row_array_test(ll m, ll n);
void simplified_dger_col_array_test(ll m, ll n);

void simplified_dger_row_test(ll m, ll n);
void simplified_dger_col_test(ll m, ll n);

#endif
