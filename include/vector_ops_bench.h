#ifndef _VECTOR_OPS_BENCH_H
#define _VECTOR_OPS_BENCH_H

#include <blas_types.h>

void axpy_bench(benchmark_info *info);
void dot_bench(benchmark_info *info);
void swap_bench(benchmark_info *info);
void assum_bench(benchmark_info *info);
void iamax_bench(benchmark_info *info);

#endif
