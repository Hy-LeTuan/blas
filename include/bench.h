#ifndef _BENCH_H_
#define _BENCH_H_

#include "blas_types.h"

extern volatile double sink;

void run_function(benchmark_info *info);
void bench(benchmark_info *info);
void display_result(benchmark_info *info, benchmark_result *res);
Benchmark_Func get_bench_function(enum Blas_Functions f);

#endif
