#include "vector_matrix_ops.h"

#include <allocate_utils.h>
#include <assert.h>
#include <math.h>
#include <vector_matrix_ops_test.h>
#include <vector_vector_ops.h>

void simplified_gemv_row_test(ll m, ll n)
{
    double **a = mat_double_init_rand(m, n);
    double *x = vec_double_init_rand(n);
    double *y = vec_double_init_rand(m);

    double *out = simplified_dgemv_row(a, x, y, m, n);

    for (ll i = 0; i < m; i++) {
        assert(fabs(out[i] - (ddot(a[i], x, n) + y[i])) <= 1e-6);
    }
}

void simplified_gemv_col_test(ll m, ll n)
{
    double **a = mat_double_init_linspace(m, n);
    double *x = vec_double_init_linspace(n);
    double *y = vec_double_init_linspace(m);

    double *out = simplified_dgemv_col(a, x, y, m, n);

    for (ll i = 0; i < m; i++) {
        assert(fabs(out[i] - (ddot(a[i], x, n) + y[i])) <= 1e-6);
    }
}

void simplified_ger_row_test(ll m, ll n)
{
    double **a = mat_double_init_rand(m, n);
    double **a_original = copy_mat(a, m, n);

    double *x = vec_double_init_rand(n);
    double *y = vec_double_init_rand(m);

    simplified_dger_row(a, x, y, m, n);

    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
            assert(a[i][j] == a_original[i][j] + y[i] * x[j]);
        }
    }
}

void simplified_ger_col_test(ll m, ll n)
{
    double **a = mat_double_init_rand(m, n);
    double **a_original = copy_mat(a, m, n);

    double *x = vec_double_init_rand(n);
    double *y = vec_double_init_rand(m);

    simplified_dger_col(a, x, y, m, n);

    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
            assert(a[i][j] == a_original[i][j] + y[i] * x[j]);
        }
    }
}

int main()
{
    ll m, n;
    m = 1000;
    n = 800;

    simplified_gemv_row_test(m, n);
    simplified_gemv_col_test(m, n);
    simplified_ger_row_test(m, n);
    simplified_ger_col_test(m, n);

    return 0;
}
