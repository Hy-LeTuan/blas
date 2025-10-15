#include "vector_ops_bench.h"
#include <bench.h>

/*
 * The actuator function to run the specificed function from `info` with all the
 * specified arguments.
 */
void run_function(benchmark_info *info) {
    switch (info->f) {
    case AXPY:
        axpy_bench(info);
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
        swap_bench(info);
        break;
    case ASSUM:
        assum_bench(info);
        break;
    case IAMAX:
        iamax_bench(info);
        break;
    case INVALID_FUNC:
        return;
    }
}

/*
 * The main function to run the benchmark. From this function, other functions
 * that could actually handle the function running is called.
 */
void bench(benchmark_info *info) {}
