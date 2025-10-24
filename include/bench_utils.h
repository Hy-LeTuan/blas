#ifndef _BENCH_UTILS_H
#define _BENCH_UTILS_H

#include "blas_types.h"

double seconds();
double time_function(benchmark_info *info, Benchmark_Func f);
ll calculate_flops(benchmark_info *info, enum Blas_Functions f);

#endif
