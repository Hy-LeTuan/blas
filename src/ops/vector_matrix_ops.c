#include <stdlib.h>
#include <vector_matrix_ops.h>
#include <vector_vector_ops.h>

/*
 * The simplified version of the General Matrix Vector Multiplication (GEMV)
 * "aAx
 * + By" where a and B = 1. The multiplication is carried out row by row of A
 * with x.
 * @param a: The matrix A of shape (m x n)
 * @param x: The vector x of shape (n)
 * @param y: The vector y of shape m
 * @param n: The length n
 * @param m: The length m
 * @returns: A vector of length m
 */
double *simplified_gemv_row(double **a, double *x, double *y, ll m, ll n)
{
    double *out = malloc(sizeof(double) * m);

    for (int i = 0; i < m; i++) {
        out[i] = dot(a[i], x, n) + y[i];
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
 */
double *simplified_gemv_col(double **a, double *x, double *y, ll m, ll n);
