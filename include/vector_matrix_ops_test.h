#ifndef _VECTOR_MATRIX_OPS_TEST_H_
#define _VECTOR_MATRIX_OPS_TEST_H_

#include <blas_types.h>

void simplified_gemv_row_test(ll m, ll n);
void simplified_gemv_col_test(ll m, ll n);

void simplified_ger_row_test(ll m, ll n);
void simplified_ger_col_test(ll m, ll n);

#endif
