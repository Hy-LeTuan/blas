#include <assert.h>
#include <stdlib.h>
#include <vector_ops.h>

void axpy_test(void) {
    ll n = 10000;
    double x = 2.0f;
    double y = 3.0f;

    double *a = malloc(sizeof(double) * n);

    for (ll i = 0; i < n; i++) {
        a[i] = (double)i;
    }

    double *res = axpy(a, x, y, n);

    for (ll i = 0; i < n; i++) {
        assert(res[i] == a[i] * x + y);
    }
}

void swap_test(void) {
    ll n = 10000;

    double *a = malloc(sizeof(double) * n);
    double *b = malloc(sizeof(double) * n);

    double *old_a = malloc(sizeof(double) * n);
    double *old_b = malloc(sizeof(double) * n);

    for (int i = 0; i < n; i++) {
        a[i] = (double)i + 3.0f;
        old_a[i] = a[i];

        b[i] = (double)i * 2.0f;
        old_b[i] = b[i];
    }

    swap(a, b, n);

    for (int i = 0; i < n; i++) {
        assert(a[i] == old_b[i]);
        assert(b[i] == old_a[i]);
    }
}

void assum_test(void) {
    ll n = 10;

    double *a = malloc(sizeof(double) * n);

    for (ll i = 0; i < n; i++) {
        a[i] = (double)i;
    }

    double res = assum(a, n);

    assert(res == (double)45.0f);
}

void iamax_test() {
    ll n = 10000;

    double *a = malloc(sizeof(double) * n);

    for (ll i = 0; i < n; i++) {
        a[i] = (double)i;
    }

    ll index = iamax(a, n);

    assert(index == n - 1);
}

int main(void) {
    axpy_test();
    swap_test();
}
