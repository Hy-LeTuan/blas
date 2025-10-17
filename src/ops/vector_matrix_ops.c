#include <matrix_utils.h>
#include <stdlib.h>
#include <vector_matrix_ops.h>
#include <vector_vector_ops.h>

double **copy_mat(double **a, ll m, ll n)
{
    double **out = malloc(sizeof(double *) * m);

    for (int i = 0; i < m; i++) {
        out[i] = dcopy(a[i], n);
    }

    return out;
}

/*
 * The simplified version of the General Matrix Vector Multiplication (GEMV)
 * "aAx
 * + By" where a and B = 1. The multiplication is carried out row by row of A
 * with x.
 * @param a: The matrix A of shape (m x n)
 * @param x: The vector x of shape (n)
 * @param y: The vector y of shape (m)
 * @param n: The length n
 * @param m: The length m
 * @returns: A vector of length m
 */
double *simplified_dgemv_row(double **a, double *x, double *y, ll m, ll n)
{
    if (n <= 0 || m <= 0)
        return NULL;

    double *out = malloc(sizeof(double) * m);

    for (int i = 0; i < m; i++) {
        out[i] = ddot(a[i], x, n) + y[i];
    }

    return out;
}

/*
 * The simplified version of the General Matrix Vector Multiplication (GEMV)
 * "aAx
 * + By" where a and B = 1. The multiplication is carried out as a linear
 * combination of the columns of A and x. with x.
 * @param a: The matrix A of shape (m x n)
 * @param x: The vector x of shape (n)
 * @param y: The vector y of shape m
 * @param n: The length n
 * @param m: The length m
 * @returns: A vector of length m
 */
double *simplified_dgemv_col(double **a, double *x, double *y, ll m, ll n)
{
    if (n <= 0 || m <= 0)
        return NULL;

    double *out = malloc(sizeof(double) * m);

    for (ll i = 0; i < m; i++) {
        out[i] = 0.0;
    }

    for (ll i = 0; i < n; i++) {
        out = daxpy(x[i], get_col(a, m, i), out, m);
    }

    out = daxpy_no_alpha(out, y, m);

    return out;
}

/*
 * The simplified form of the General Rank 1 Update (GER) A := A + alpha * y * x^T where
 * alpha = 1. The matrix will be updated row by row, where a_i := a_i + x * y_i where
 * y_i is a scalar.
 * @param a: The matrix A with shape (m, n)
 * @param x: The vector x of shape (n)
 * @param y: The vector y of shape (m)
 * @param m: The length m
 * @param n: The length n
 * @flops: 2mn
 */
void simplified_dger_row(double **a, double *x, double *y, ll m, ll n)
{
    for (ll i = 0; i < m; i++) {
        a[i] = daxpy(y[i], x, a[i], n);
    }
}

/*
 * The simplified form of the General Rank 1 Update (GER) A := A + alpha * y * x^T where
 * alpha = 1. The matrix will be updated column by column, where a_j := a_j + y * x_j
 * where x_j is a scalar.
 * @param a: The matrix A with shape (m, n)
 * @param x: The vector x of shape (n)
 * @param y: The vector y of shape (m)
 * @param m: The length m
 * @param n: The length n
 * @flops: 2nm
 */
void simplified_dger_col(double **a, double *x, double *y, ll m, ll n)
{
    for (ll i = 0; i < n; i++) {
        update_col(a, daxpy(x[i], y, get_col(a, m, i), m), m, i);
    }
}
