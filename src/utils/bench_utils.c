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

double time_function(benchmark_info *info, Benchmark_Func f)
{
    double start = seconds();

    f(info);

    double stop = seconds();

    return stop - start;
}

ll calculate_flops(benchmark_info *info, enum Blas_Functions f)
{
    ll n = info->n;
    ll m = info->m;

    switch (f) {
    case AXPY:
        return 2 * n;
    case COPY:
    case SWAP:
        return 0;
    case DOT:
    case NRM2:
        return 2 * n - 1;
    case SCAL:
        return n;
    case INVALID_FUNC:
        return 0;
    case SDGEMV_C:
    case SDGEMV_R:
    case SDGER_C:
    case SDGER_R:
        return 2 * m * n;
    }

    return 0;
}
