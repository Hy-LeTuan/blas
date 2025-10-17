#include "vector_matrix_ops.h"

#include <allocate_utils.h>
#include <assert.h>
#include <math.h>
#include <vector_matrix_ops_test.h>
#include <vector_vector_ops.h>

void simplified_gemv_row_test(ll m, ll n)
{
    double **a = mat_double_init_rand(m, n);
    double *x = vec_double_init_rand(m);
    double *y = vec_double_init_rand(m);

    double *out = simplified_gemv_row(a, x, y, m, n);

    for (ll i = 0; i < m; i++) {
        assert(fabs(out[i] - (dot(a[i], x, n) + y[i])) <= 1e-6);
    }
}

void simplified_gemv_col_test(ll m, ll n)
{
    double **a = mat_double_init_linspace(m, n);
    double *x = vec_double_init_linspace(m);
    double *y = vec_double_init_linspace(m);

    double *out = simplified_gemv_col(a, x, y, m, n);

    for (ll i = 0; i < m; i++) {
        assert(fabs(out[i] - (dot(a[i], x, n) + y[i])) <= 1e-6);
    }
}

int main()
{
    ll m, n;
    m = 2;
    n = 2;

    simplified_gemv_row_test(m, n);
    simplified_gemv_col_test(m, n);

    return 0;
}
