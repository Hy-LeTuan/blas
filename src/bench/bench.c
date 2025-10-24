#include "blas_types.h"
#include "vector_vector_ops_bench.h"

#include <bench.h>
#include <bench_utils.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

volatile double sink = 0.0;

/*
 * Getting the address of all benching functions
 */
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

    free(res.time_records);
}

void display_result(benchmark_info *info, benchmark_result *res)
{
    double total_warmup_time = 0.0;
    double total_execution_time = 0.0;

    for (ll i = 0; i < info->cache_warmup; i++) {
        total_warmup_time += res->time_records[i];
    }

    for (ll i = info->cache_warmup; i < info->iteration; i++) {
        total_execution_time += res->time_records[i];
    }

    double mean_execution_time =
            total_execution_time / (info->iteration - info->cache_warmup);

    double runtime_deviation = 0.0;
    for (ll i = info->cache_warmup; i < info->iteration; i++) {
        runtime_deviation += pow((res->time_records[i] - mean_execution_time), 2.0);
    }

    runtime_deviation /= (info->iteration - info->cache_warmup);

    printf("-------------------------------------------------------\n");

    printf("Running benchmark for function: %s\n", convert_blas_func_to_str(info->f));

    printf("-------------------------------------------------------\n");

    printf("I. Benchmark Metadata:\n");
    printf("\t1. Function name: %s\n", convert_blas_func_to_str(info->f));
    printf("\t2. Input size: %lld\n", info->n);
    printf("\t3. Number of cache warm-up iteration: %lld\n", info->cache_warmup);
    printf("\t4. Number of benchmark iteration: %lld\n",
           info->iteration - info->cache_warmup);
    printf("\t5. Number of total iteration: %lld\n", info->iteration);

    printf("-------------------------------------------------------\n");

    printf("II. Total Runtime Summary:\n");
    printf("\t1. Total cache warm-up runtime: %f " TIME_UNIT "\n", total_warmup_time);
    printf("\t2. Total benchmark runtime: %f " TIME_UNIT "\n", total_execution_time);
    printf("\t3. Total runtime: %f " TIME_UNIT "\n",
           total_warmup_time + total_execution_time);

    printf("-------------------------------------------------------\n");

    printf("III. Average Runtime Summary:\n");
    printf("\t1. Average warm-up runtime: %f " AVERAGE_UNIT "\n",
           total_warmup_time / info->cache_warmup);
    printf("\t2. Average benchmark runtime: %f " AVERAGE_UNIT "\n",
           mean_execution_time);
    printf("\t3. Average total runtime: %f " AVERAGE_UNIT "\n",
           (total_execution_time + total_warmup_time) / info->iteration);

    printf("IV. Statistical Summary\n");
    printf("\t1. Total Runtime: %f" TIME_UNIT "\n", total_execution_time);
    printf("\t2. Average Runtime: %f" AVERAGE_UNIT "\n", mean_execution_time);
    printf("\t3. Standard Deviation: %f\n", runtime_deviation);
    printf("\t4. Theoretical FLOPS: %lld\n", res->flops);
    printf("\t5. FLOP/s: %f\n", (res->flops * (info->iteration - info->cache_warmup)) /
                                        (double)total_execution_time);

    printf("-------------------------------------------------------\n");
}
