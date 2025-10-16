#include "vector_matrix_ops.h"
#include <allocate_utils.h>
#include <assert.h>
#include <vector_matrix_ops_test.h>
#include <vector_vector_ops.h>

void simplified_gemv_row_test(ll m, ll n) {
    double **a = mat_double_init_rand(m, n);
    double *x = vec_double_init_rand(m);
    double *y = vec_double_init_rand(m);

    double *out = simplified_gemv_row(a, x, y, m, n);

    for (ll i = 0; i < m; i++) {
        assert(out[i] == dot(a[i], x, n) + y[i]);
    }
}

int main() {
    ll m, n;
    m = 100;
    n = 80;

    simplified_gemv_row_test(m, n);

    return 0;
}
