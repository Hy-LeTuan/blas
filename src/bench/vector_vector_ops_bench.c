#include <allocate_utils.h>
#include <assert.h>
#include <bench.h>
#include <blas_types.h>
#include <stdlib.h>
#include <vector_vector_ops.h>
#include <vector_vector_ops_bench.h>

void axpy_bench(BenchmarkInfo *info)
{
    ll n = info->n;

    double a = 2.0f;

    double *x = vec_double_init_rand(n);
    double *y = vec_double_init_rand(n);

    double *res = daxpy(a, x, y, n, 1, 1, 0, 0);

    sink += res[0];

    free(x);
    free(y);
    free(res);
}

void dot_bench(BenchmarkInfo *info)
{
    ll n = info->n;

    double *a = vec_double_init_rand(n);
    double *b = vec_double_init_rand(n);

    double c = ddot(a, b, n, 1, 1, 0, 0);

    sink += c;
    sink = 0.0;

    free(a);
    free(b);
}

void swap_bench(BenchmarkInfo *info)
{
    ll n = info->n;

    double *a = vec_double_init_rand(n);
    double *b = vec_double_init_rand(n);

    double *old_a = malloc(sizeof(double) * n);
    double *old_b = malloc(sizeof(double) * n);

    for (int i = 0; i < n; i++) {
        a[i] += 3.0f;
        old_a[i] = a[i];

        b[i] *= 2.0f;
        old_b[i] = b[i];
    }

    dswap(a, b, n, 1, 1, 0, 0);

    free(a);
    free(b);
    free(old_a);
    free(old_b);
}

void copy_bench(BenchmarkInfo *info)
{
    ll n = info->n;

    double *a = vec_double_init_rand(n);
    double *b = dcopy(a, n, 1, 0);

    sink += b[0];
    sink = 0.0;

    free(a);
    free(b);
}

void scal_bench(BenchmarkInfo *info)
{
    ll n = info->n;

    double *a = vec_double_init_rand(n);
    double *b = dscal(a, 2.0, n, 1, 0);

    sink += b[0];
    sink = 0.0;

    free(a);
    free(b);
}

void nrm2_bench(BenchmarkInfo *info)
{
    ll n = info->n;

    double *a = vec_double_init_rand(n);
    double l = dnrm2(a, n, 1, 0);

    sink += l;
    sink = 0.0;

    free(a);
}
