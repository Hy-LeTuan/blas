#include "blas_types.h"
#include <stdio.h>
#include <time.h>
#include <time_utils.h>

void time_function(benchmark_info *info, BENCHMARK_FUNC f) {
    clock_t start = clock();

    f(info);

    clock_t stop = clock();

    printf("Time taken for function is: %lf seconds\n",
           ((double)stop - (double)start) / (double)CLOCKS_PER_SEC);
}
