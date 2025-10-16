#include "blas_types.h"
#include "vector_vector_ops_bench.h"
#include <bench.h>
#include <time_utils.h>

/*
 * The actuator function to run the specificed function from `info` with all the
 * specified arguments.
 */
void run_function(benchmark_info *info) {
    switch (info->f) {
    case AXPY:
        time_function(info, &axpy_bench);
        break;
    case COPY:
        break;
    case DOT:
        break;
    case NRM2:
        break;
    case SCAL:
        break;
    case SWAP:
        time_function(info, &swap_bench);
        break;
    case ASSUM:
        time_function(info, &assum_bench);
        break;
    case IAMAX:
        time_function(info, &iamax_bench);
        break;
    case INVALID_FUNC:
        return;
    }
}

/*
 * The main function to run the benchmark. From this function, other functions
 * that could actually handle the function running is called.
 */
void bench(benchmark_info *info) { run_function(info); }
