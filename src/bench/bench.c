#include "blas_types.h"
#include "vector_vector_ops_bench.h"

#include <bench.h>
#include <bench_utils.h>

volatile double sink = 0.0;

void display_result(benchmark_result *res);
void run_function(benchmark_info *info);
void display_result(benchmark_result *res);

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
    benchmark_result res;
    double time;

    switch (info->f) {
    case AXPY:
        time = time_function(info, &axpy_bench);
        break;
    case COPY:
        time = time_function(info, &copy_bench);
        break;
    case DOT:
        time = time_function(info, &dot_bench);
        break;
    case NRM2:
        time = time_function(info, &nrm2_bench);
        break;
    case SCAL:
        time = time_function(info, &scal_bench);
        break;
    case SWAP:
        time = time_function(info, &swap_bench);
        break;
    case INVALID_FUNC:
        return;
    }

    res.time = time;
    display_result(&res);
}

void display_result(benchmark_result *res) {}
