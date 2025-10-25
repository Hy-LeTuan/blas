#ifndef _VECTOR_MATRIX_OPS_BENCH_H
#define _VECTOR_MATRIX_OPS_BENCH_H

#include <blas_types.h>

void simplified_dgemv_col_bench(BenchmarkInfo *info);
void simplified_dgemv_row_bench(BenchmarkInfo *info);
void simplified_dger_row_bench(BenchmarkInfo *info);
void simplified_dger_col_bench(BenchmarkInfo *info);

#endif
