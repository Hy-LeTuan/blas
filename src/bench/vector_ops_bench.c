#include <allocate_utils.h>
#include <assert.h>
#include <stdlib.h>
#include <vector_ops.h>
#include <vector_ops_bench.h>

void axpy_bench(ll n) {
    double x = 2.0f;
    double y = 3.0f;

    double *a = vec_double_init_linspace(n);

    double *res = axpy(a, x, y, n);

    for (ll i = 0; i < n; i++) {
        assert(res[i] == a[i] * x + y);
    }
}

void swap_bench(ll n) {
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

    swap(a, b, n);

    for (int i = 0; i < n; i++) {
        assert(a[i] == old_b[i]);
        assert(b[i] == old_a[i]);
    }
}

void iamax_bench(ll n) {
    double *a = vec_double_init_linspace(n);

    ll index = iamax(a, n);

    assert(index == n - 1);
}
