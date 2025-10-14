#include <argp.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector_ops_bench.h>

typedef struct {
    ll n;
    const char *f;
} benchmark_info;

static int parse_opt(int key, char *arg, struct argp_state *state) {
    benchmark_info *info_ref = state->input;

    switch (key) {
    case 'n':
    case 's':;
        info_ref->n = atoi(arg);
        break;
    case 'f':
        info_ref->f = arg;
        break;
    case ARGP_KEY_ARG:
        info_ref->f = arg;
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    benchmark_info info = {.n = 10000, .f = NULL};

    struct argp_option options[] = {
        {"number", 'n', "NUM", OPTION_ARG_OPTIONAL,
         "The input size to allocate for testing."},
        {"size", 's', "NUM", OPTION_ALIAS, ""},
        {"function", 'f', "NAME", 0,
         "The name of the testing function. Available functions include: "
         "axpy, copy, scal"},
        {0}};

    struct argp argp = {options, parse_opt, "FUNCTION"};

    if (argp_parse(&argp, argc, argv, 0, 0, &info) != 0) {
        return 1;
    } else if (info.f == NULL) {
        printf(
            "No function name found, a function name must be passed in "
            "either through the -f flag or through a standalone argument.\n");

        return 1;
    }

    printf("info: input is %lld, and function name is %s\n", info.n, info.f);

    return 0;

    // const char *filename = argv[0];
    // printf("name is: %s\n", filename);
    // axpy_test(1000000);
}
