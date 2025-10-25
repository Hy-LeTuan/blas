#ifndef _BENCH_H_
#define _BENCH_H_

#include "blas_types.h"

extern volatile double sink;

void run_function(BenchmarkInfo *info);
void bench(BenchmarkInfo *info);
void display_result(BenchmarkInfo *info, BenchmarkResult *res);
Benchmark_Func get_bench_function(enum Blas_Functions f);

#endif
