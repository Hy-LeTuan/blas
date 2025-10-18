#include "blas_types.h"

#include <bench_utils.h>
#include <bits/time.h>
#include <time.h>

double seconds()
{
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_sec + t.tv_nsec * 1e-9;
}

double time_function(benchmark_info *info, BENCHMARK_FUNC f)
{
    double start = seconds();

    f(info);

    double stop = seconds();

    return stop - start;
}
