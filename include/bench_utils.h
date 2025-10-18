#ifndef _BENCH_UTILS_H
#define _BENCH_UTILS_H

#include "blas_types.h"

double seconds();
double time_function(benchmark_info *info, BENCHMARK_FUNC f);
ll calculate_flops(ll n, enum BLAS_FUNCTIONS f);

#endif
