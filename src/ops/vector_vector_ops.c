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
double *axpy_no_alpha(double *x, double *y, ll n)
{
    if (n <= 0)
        return NULL;

    double *out = malloc(sizeof(x[0]) * n);

    for (ll i = 0; i < n; i++) {
        out[i] = x[i] + y[i];
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
 */
double *axpy(double a, double *x, double *y, ll n)
{
    if (n <= 0)
        return NULL;

    double *out = malloc(sizeof(x[0]) * n);

    for (ll i = 0; i < n; i++) {
        out[i] = a * x[i] + y[i];
    }

    return out;
}

double *copy(double *a, ll n)
{
    if (n <= 0)
        return NULL;

    double *out = malloc(sizeof(a[0]) * n);

    for (ll i = 0; i < n; i++) {
        out[i] = a[i];
    }

    return out;
};

double dot(double *x, double *y, ll n)
{
    if (n <= 0)
        return 0.0f;

    double out = x[0] * y[0];

    for (ll i = 1; i < n; i++) {
        out += (x[i] * y[i]);
    }

    return out;
}

double nrm2(double *x, ll n)
{
    if (n <= 0)
        return 0.0f;

    return sqrt(dot(x, x, n));
}

double *scal(double *x, double a, ll n)
{
    if (n <= 0)
        return NULL;

    double *out = malloc(sizeof(x[0]) * n);

    for (ll i = 0; i < n; i++) {
        out[i] = x[i] * a;
    }

    return out;
}

void swap(double *a, double *b, ll n)
{
    if (n <= 0)
        return;

    double temp;

    for (ll i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

double assum(double *a, ll n)
{
    if (n <= 0)
        return 0.0f;

    double sum = a[0];

    for (int i = 1; i < n; i++) {
        sum += fabs(a[i]);
    }

    return sum;
}

/*
 * Find the index of the maximal element of the vector. If there are multiple
 * maximal elements, return the index of the first occurence.
 */
double iamax(double *a, ll n)
{
    if (n <= 0)
        return -1.0f;

    ll index = 0;

    for (ll i = 1; i < n; i++) {
        if (a[i] > a[index]) {
            index = i;
        }
    }

    return index;
}
