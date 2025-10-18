#include "blas_types.h"
#include "vector_vector_ops_bench.h"

#include <bench.h>
#include <bench_utils.h>
#include <stdio.h>
#include <stdlib.h>

volatile double sink = 0.0;

void run_function(benchmark_info *info);
void display_result(benchmark_info *info, benchmark_result *res);
BENCHMARK_FUNC get_bench_function(enum BLAS_FUNCTIONS f);

/*
 * The main function to run the benchmark. From this function, other functions
 * that could actually handle the function running is called.
 */
void bench(benchmark_info *info) { run_function(info); }

/*
 * The actuator function to run the specificed function from `info` with all the
 * specified arguments.
 */
void run_function(benchmark_info *info)
{
    double time;
    BENCHMARK_FUNC f = get_bench_function(info->f);
    benchmark_result res = {.run_time = 0.0,
                            .warmup_time = 0.0,
                            .array_length = info->iteration,
                            .flops = calculate_flops(info->n, info->f),
                            .time_records = malloc(sizeof(double) * info->iteration)};

    for (ll i = 0; i < info->cache_warmup; i++) {
        time = time_function(info, f);
        res.warmup_time += time;
        res.time_records[i] = time;
    }

    for (ll i = info->cache_warmup; i < info->iteration; i++) {
        time = time_function(info, f);
        res.run_time += time;
        res.time_records[i] = time;
    }

    display_result(info, &res);
}

BENCHMARK_FUNC get_bench_function(enum BLAS_FUNCTIONS f)
{
    switch (f) {
    case AXPY:
        return &axpy_bench;
    case COPY:
        return &copy_bench;
    case DOT:
        return &dot_bench;
    case NRM2:
        return &nrm2_bench;
    case SCAL:
        return &scal_bench;
    case SWAP:
        return &swap_bench;
    case INVALID_FUNC:
        return NULL;
    }

    return NULL;
}

void display_result(benchmark_info *info, benchmark_result *res)
{
    for (ll i = 0; i < info->cache_warmup; i++) {
        printf("time for warmup iteration %lld is %f\n", i, res->time_records[i]);
    }

    for (ll i = info->cache_warmup; i < info->iteration; i++) {
        printf("time for iteration %lld is %f\n", i - info->cache_warmup,
               res->time_records[i]);
    }
}
