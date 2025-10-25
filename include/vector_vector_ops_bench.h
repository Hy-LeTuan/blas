#ifndef _VECTOR_VECTOR_OPS_BENCH_H
#define _VECTOR_VECTOR_OPS_BENCH_H

#include <blas_types.h>

void axpy_bench(BenchmarkInfo *info);
void dot_bench(BenchmarkInfo *info);
void swap_bench(BenchmarkInfo *info);
void copy_bench(BenchmarkInfo *info);
void scal_bench(BenchmarkInfo *info);
void nrm2_bench(BenchmarkInfo *info);

#endif
