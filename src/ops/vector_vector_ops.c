#include <math.h>
#include <stdlib.h>
#include <vector_vector_ops.h>

/*
 * Performs the equation x + y where x and y is a vector of shape (n). This
 * function returns a vector.
 * @param a: The vector a of size (n)
 * @param y: The constant y
 * @param n: The length n
 * @returns: Returns a pointer to a vector fo size n
 */
double *daxpy_no_alpha(double *x, double *y, ll n, ll stride_x, ll stride_y, ll start_x,
                       ll start_y)
{
    if (n <= 0)
        return NULL;

    double *out = malloc(sizeof(x[0]) * n);

    ll ix = start_x;
    ll iy = start_y;
    ll i = 0;

    while (i < n) {
        out[i] = x[ix] + y[iy];

        i++;
        ix += stride_x;
        iy += stride_y;
    }

    return out;
}

/*
 * Performs the equation ax + y where x and y are vectors of shape (n) and a is
 * a scalar. This function returns a vector.
 * @param a: The vector a of size (n)
 * @param x: The vector x of size (n)
 * @param y: The constant y
 * @param n: The length n
 * @returns: Returns a pointer to a vector fo size n
 * @flops: 2n
 */
double *daxpy(double a, double *x, double *y, ll n, ll stride_x, ll stride_y,
              ll start_x, ll start_y)
{
    if (n <= 0)
        return NULL;

    double *out = malloc(sizeof(x[0]) * n);

    ll ix = start_x;
    ll iy = start_y;
    ll i = 0;

    while (i < n) {
        out[i] = a * x[ix] + y[iy];

        i++;
        ix += stride_x;
        iy += stride_y;
    }

    return out;
}

/*
 * Performs the copy of vector x to another separate buffer through malloc. Returns the
 * new vector. If x is access with a stride > 1, the copied vector would also be
 * strided, but every elements between strides are uninitialized.
 * @param x: The vector x
 * @param n: The length n
 * @param stride: The stride for x
 * @param start: The index of the starting element
 */
double *dcopy(double *x, ll n, ll stride, ll start)
{
    if (n <= 0)
        return NULL;

    double *out = malloc(sizeof(double) * n);

    for (ll i = start; i < start + n * stride; i += stride) {
        out[i] = x[i];
    }

    return out;
};

/*
 * Performs the dot product between 2 vecotrs x and y with the length n
 * @flops: 2n - 1
 */
double ddot(double *x, double *y, ll n, ll stride_x, ll stride_y, ll start_x,
            ll start_y)
{
    if (n <= 0)
        return 0.0f;

    double out = x[start_x] * y[start_y];

    ll ix = start_x + stride_x;
    ll iy = start_y + stride_y;

    for (ll i = 1; i < n; i++) {
        out += (x[ix] * y[iy]);

        ix += stride_x;
        iy += stride_y;
    }

    return out;
}

double dapdots(double alpha, double *x, double *y, ll n, ll stride_x, ll stride_y,
               ll start_x, ll start_y)
{
    return alpha + ddot(x, y, n, stride_x, stride_y, start_x, start_y);
}

/*
 * Compute the L2 norm of a vctor
 * @flops: 2n - 1
 */
double dnrm2(double *x, ll n, ll stride, ll start)
{
    if (n <= 0)
        return 0.0f;

    return sqrt(ddot(x, x, n, stride, stride, start, start));
}

/*
 * Performs the scaling of a vector x with a factor a
 */
double *dscal(double *x, double a, ll n, ll stride, ll start)
{
    if (n <= 0)
        return NULL;

    double *out = malloc(sizeof(double) * n);

    for (ll i = start; i < start + stride * n; i += stride) {
        out[i] = x[i] * a;
    }

    return out;
}

void dswap(double *x, double *y, ll n, ll stride_x, ll stride_y, ll start_x, ll start_y)
{
    if (n <= 0)
        return;

    double temp;

    ll ix = start_x;
    ll iy = start_y;

    for (ll i = 0; i < n; i++) {
        temp = x[ix];
        x[ix] = y[iy];
        y[iy] = temp;

        ix += stride_x;
        iy += stride_y;
    }
}
