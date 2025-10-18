#include "vector_matrix_ops.h"

#include <allocate_utils.h>
#include <assert.h>
#include <math.h>
#include <vector_matrix_ops_test.h>
#include <vector_vector_ops.h>

void simplified_gemv_row_array_test(ll m, ll n)
{
    double **a = mat_double_init_rand(m, n);
    double *x = vec_double_init_rand(n);
    double *y = vec_double_init_rand(m);

    double *out = simplified_dgemv_row_array(a, x, y, m, n);

    for (ll i = 0; i < m; i++) {
        assert(fabs(out[i] - (ddot(a[i], x, n, 1, 1, 0, 0) + y[i])) <= 1e-6);
    }
}

void simplified_gemv_col_array_test(ll m, ll n)
{
    double **a = mat_double_init_linspace(m, n);
    double *x = vec_double_init_linspace(n);
    double *y = vec_double_init_linspace(m);

    double *out = simplified_dgemv_col_array(a, x, y, m, n);

    for (ll i = 0; i < m; i++) {
        assert(fabs(out[i] - (ddot(a[i], x, n, 1, 1, 0, 0) + y[i])) <= 1e-6);
    }
}

void simplified_gemv_col_test(ll m, ll n)
{
    double *a = mat_double_init_linspace_flat(m, n);
    double **a_mat = mat_double_init_linspace(m, n);

    double *x = vec_double_init_linspace(n);
    double *y = vec_double_init_linspace(m);

    double *out_mat = simplified_dgemv_col_array(a_mat, x, y, m, n);
    double *out_flat = simplified_dgemv_col(a, x, y, m, n);

    for (ll i = 0; i < m; i++) {
        assert(out_mat[i] == out_flat[i]);
    }
}

void simplified_gemv_row_test(ll m, ll n)
{
    double *a = mat_double_init_linspace_flat(m, n);
    double **a_mat = mat_double_init_linspace(m, n);

    double *x = vec_double_init_linspace(n);
    double *y = vec_double_init_linspace(m);

    double *out_mat = simplified_dgemv_row_array(a_mat, x, y, m, n);
    double *out_flat = simplified_dgemv_row(a, x, y, m, n);

    for (ll i = 0; i < m; i++) {
        assert(out_mat[i] == out_flat[i]);
    }
}

void simplified_dger_row_array_test(ll m, ll n)
{
    double **a = mat_double_init_rand(m, n);
    double **a_original = copy_mat(a, m, n);

    double *x = vec_double_init_rand(n);
    double *y = vec_double_init_rand(m);

    simplified_dger_row_array(a, x, y, m, n);

    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
            assert(a[i][j] == a_original[i][j] + y[i] * x[j]);
        }
    }
}

void simplified_dger_col_array_test(ll m, ll n)
{
    double **a = mat_double_init_rand(m, n);
    double **a_original = copy_mat(a, m, n);

    double *x = vec_double_init_rand(n);
    double *y = vec_double_init_rand(m);

    simplified_dger_col_array(a, x, y, m, n);

    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
            assert(a[i][j] == a_original[i][j] + y[i] * x[j]);
        }
    }
}

void simplified_dger_row_test(ll m, ll n)
{
    double **a = mat_double_init_linspace(m, n);

    double *x = vec_double_init_linspace(n);
    double *y = vec_double_init_linspace(m);

    double *a_flat = mat_double_init_linspace_flat(m, n);

    simplified_dger_row_array(a, x, y, m, n);
    simplified_dger_row(a_flat, x, y, m, n);

    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
            assert(a[i][j] == a_flat[i * n + j]);
        }
    }
}

void simplified_dger_col_test(ll m, ll n)
{
    double **a = mat_double_init_linspace(m, n);

    double *x = vec_double_init_linspace(n);
    double *y = vec_double_init_linspace(m);

    double *a_flat = mat_double_init_linspace_flat(m, n);

    simplified_dger_row_array(a, x, y, m, n);
    simplified_dger_col(a_flat, x, y, m, n);

    for (ll i = 0; i < m; i++) {
        for (ll j = 0; j < n; j++) {
            assert(a[i][j] == a_flat[i * n + j]);
        }
    }
}

int main()
{
    ll m, n;
    m = 3000;
    n = 2000;

    simplified_gemv_row_array_test(m, n);
    simplified_gemv_col_array_test(m, n);
    simplified_dger_row_array_test(m, n);
    simplified_dger_col_array_test(m, n);

    simplified_gemv_col_test(m, n);
    simplified_gemv_row_test(m, n);

    simplified_dger_row_test(m, n);
    simplified_dger_col_test(m, n);

    return 0;
}
