#include "allocate_utils.h"

#include <bench.h>
#include <stdlib.h>
#include <vector_matrix_ops.h>
#include <vector_matrix_ops_bench.h>

void simplified_dgemv_col_bench(benchmark_info *info)
{
    ll m = info->m;
    ll n = info->n;

    double *a = mat_double_init_rand(m, n);

    double *x = vec_double_init_rand(n);
    double *y = vec_double_init_rand(m);

    double *out = simplified_dgemv_col(a, x, y, m, n);

    sink += out[0];

    free(a);
    free(x);
    free(y);
    free(out);
}

void simplified_dgemv_row_bench(benchmark_info *info)
{
    ll m = info->m;
    ll n = info->n;

    double *a = mat_double_init_rand(m, n);
    double *x = vec_double_init_rand(n);
    double *y = vec_double_init_rand(m);

    double *out = simplified_dgemv_row(a, x, y, m, n);

    sink += out[0];

    free(a);
    free(x);
    free(y);
    free(out);
}

void simplified_dger_row_bench(benchmark_info *info)
{
    ll m = info->m;
    ll n = info->n;

    double *a = mat_double_init_rand(m, n);
    double *x = vec_double_init_rand(n);
    double *y = vec_double_init_rand(m);

    simplified_dger_row(a, x, y, m, n);

    sink += a[0];

    free(a);
    free(x);
    free(y);
}

void simplified_dger_col_bench(benchmark_info *info)
{
    ll m = info->m;
    ll n = info->n;

    double *a = mat_double_init_rand(m, n);
    double *x = vec_double_init_rand(n);
    double *y = vec_double_init_rand(m);

    simplified_dgemv_col(a, x, y, m, n);

    sink += a[0];

    free(a);
    free(x);
    free(y);
}
