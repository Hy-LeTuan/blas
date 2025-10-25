#ifndef _BENCH_UTILS_H
#define _BENCH_UTILS_H

#include "blas_types.h"

double seconds();
double time_function(BenchmarkInfo *info, Benchmark_Func f);
ll calculate_flops(BenchmarkInfo *info, enum Blas_Functions f);

#endif
