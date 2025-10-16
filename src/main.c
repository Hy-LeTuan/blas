#include <argp.h>
#include <bench.h>
#include <blas_types.h>
#include <error_messages.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector_vector_ops_bench.h>

static int parse_opt(int key, char *arg, struct argp_state *state) {
    benchmark_info *info_ref = state->input;

    switch (key) {
    case 'n':
    case 's':;
        info_ref->n = atoll(arg);
        break;
    case 'f':
        info_ref->f = convert(arg);
        break;
    case ARGP_KEY_ARG:
        info_ref->f = convert(arg);
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));

    benchmark_info info = {.n = 10000, .f = INVALID_FUNC};

    struct argp_option options[] = {
        {"number", 'n', "NUM", OPTION_ARG_OPTIONAL,
         "The input size to allocate for testing."},
        {"size", 's', "NUM", OPTION_ALIAS, ""},
        {"function", 'f', "STRING", 0,
         "The name of the testing function. Available functions include: "
         "axpy, copy, scal"},
        {0}};

    struct argp argp = {options, parse_opt, "FUNCTION"};

    if (argp_parse(&argp, argc, argv, 0, 0, &info) != 0) {
        return 1;
    } else if (info.f == INVALID_FUNC) {
        printf(ERROR_NO_FUNCTION_FOUND);
        return 1;
    }

    bench(&info);

    return 0;
}
