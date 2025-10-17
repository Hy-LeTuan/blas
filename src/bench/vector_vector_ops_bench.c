#include <allocate_utils.h>
#include <assert.h>
#include <blas_types.h>
#include <stdlib.h>
#include <vector_vector_ops.h>
#include <vector_vector_ops_bench.h>

void axpy_bench(benchmark_info *info)
{
    ll n = info->n;

    double a = 2.0f;

    double *x = vec_double_init_linspace(n);
    double *y = vec_double_init_linspace(n);

    double *res = daxpy(a, x, y, n);

    for (ll i = 0; i < n; i++) {
        assert(res[i] == x[i] * y[i] + a);
    }
}

void dot_bench(benchmark_info *info)
{
    ll n = info->n;

    double *a = vec_double_init_linspace(n);
    double *b = vec_double_init_linspace(n);

    double c = ddot(a, b, n);

    assert(c != 0.0);
}

void swap_bench(benchmark_info *info)
{
    ll n = info->n;

    double *a = vec_double_init_linspace(n);
    double *b = vec_double_init_linspace(n);

    double *old_a = malloc(sizeof(double) * n);
    double *old_b = malloc(sizeof(double) * n);

    for (int i = 0; i < n; i++) {
        a[i] += 3.0f;
        old_a[i] = a[i];

        b[i] *= 2.0f;
        old_b[i] = b[i];
    }

    dswap(a, b, n);

    for (int i = 0; i < n; i++) {
        assert(a[i] == old_b[i]);
        assert(b[i] == old_a[i]);
    }
}

void assum_bench(benchmark_info *info)
{
    ll n = info->n;

    double *a = vec_double_init_linspace(n);

    double sum = diamax(a, n);

    assert(sum != 0.0);

    return;
}

void iamax_bench(benchmark_info *info)
{
    ll n = info->n;

    double *a = vec_double_init_linspace(n);

    ll index = diamax(a, n);

    assert(index == n - 1);
}
