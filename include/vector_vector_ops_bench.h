#ifndef _VECTOR_VECTOR_OPS_BENCH_H
#define _VECTOR_VECTOR_OPS_BENCH_H

#include <blas_types.h>

void axpy_bench(benchmark_info *info);
void dot_bench(benchmark_info *info);
void swap_bench(benchmark_info *info);
void copy_bench(benchmark_info *info);
void scal_bench(benchmark_info *info);
void nrm2_bench(benchmark_info *info);

#endif
