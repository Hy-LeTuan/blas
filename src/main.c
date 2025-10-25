#include <argp.h>
#include <bench.h>
#include <blas_types.h>
#include <error_messages.h>
#include <stdlib.h>
#include <time.h>
#include <vector_vector_ops_bench.h>

static int parse_opt(int key, char *arg, struct argp_state *state)
{
    BenchmarkInfo *info_ref = state->input;

    switch (key) {
    case 'n':
    case 's':;
        info_ref->n = atoll(arg);
        break;
    case 'm':
        info_ref->m = atoll(arg);
        break;
    case 'f':
        info_ref->f = convert(arg);
        break;
    case 'i':
        info_ref->iteration = atoll(arg);
        break;
    case 'w':
        info_ref->cache_warmup = atoll(arg);
        break;
    case ARGP_KEY_ARG:
        info_ref->f = convert(arg);
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    BenchmarkInfo info = {
            .n = 1000, .m = 1000, .iteration = 500, .cache_warmup = 100, .f = AXPY};

    struct argp_option options[] = {
            {"first", 'n', "NUM", OPTION_ARG_OPTIONAL,
             "The input size `n` to allocate for vector of size (n)."},
            {"size", 's', "NUM", OPTION_ALIAS, ""},
            {"second", 'm', "NUM", OPTION_ARG_OPTIONAL,
             "The additional input size `m` to allocate for matrix of size (m x n)."},
            {"iteration", 'i', "NUM", OPTION_ARG_OPTIONAL,
             "The number of iterations to run the provided function."},
            {"warmup", 'w', "NUM", OPTION_ARG_OPTIONAL,
             "The number of iterations for cache warmup."},
            {"function", 'f', "STRING", 0,
             "The name of the testing function. Available functions include: "
             "Vector - Vector: axpy, dot, copy, scal, swap, nrm2 | Vector - Matrix: "
             "sdgemv_c, sdgemv_r, sdger_c, sdger_r. The default function is axpy"},
            {0}};

    struct argp argp = {options, parse_opt, "FUNCTION"};

    if (argp_parse(&argp, argc, argv, 0, 0, &info) != 0) {
        return EXIT_FAILURE;
    }

    bench(&info);

    return 0;
}
