#include <assert.h>
#include <stdlib.h>
#include <vector_ops.h>

void axpy_test() {
    ll n = 1000;
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

int main(void) { axpy_test(); }
