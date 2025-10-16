#include <math.h>
#include <stdlib.h>
#include <vector_ops.h>

double *axpy(double *a, double x, double y, ll n) {
    if (n <= 0)
        return NULL;

    double *out = malloc(sizeof(a[0]) * n);

    for (ll i = 0; i < n; i++) {
        out[i] = a[i] * x + y;
    }

    return out;
}

double *copy(double *a, ll n) {
    if (n <= 0)
        return NULL;

    double *out = malloc(sizeof(a[0]) * n);

    for (ll i = 0; i < n; i++) {
        out[i] = a[i];
    }

    return out;
};

double dot(double *a, double *b, ll n) {
    if (n <= 0)
        return 0.0f;

    double out = a[0] * b[0];

    for (ll i = 1; i < n; i++) {
        out += (a[i] * b[i]);
    }

    return out;
}

double nrm2(double *a, ll n) {
    if (n <= 0)
        return 0.0f;

    return sqrt(dot(a, a, n));
}

double *scal(double *a, double x, ll n) {
    if (n <= 0)
        return NULL;

    double *out = malloc(sizeof(a[0]) * n);

    for (ll i = 0; i < n; i++) {
        out[i] = a[i] * x;
    }

    return out;
}

void swap(double *a, double *b, ll n) {
    if (n <= 0)
        return;

    double temp;

    for (ll i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

double assum(double *a, ll n) {
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
double iamax(double *a, ll n) {
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
