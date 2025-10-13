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
        out += (a[i] * a[i]);
    }

    return out;
}

double nrm2(double *a, ll n) {
    if (n <= 0)
        return 0.0f;

    return sqrt(dot(a, a, n));
}

double *scale(double *a, double x, ll n) {
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

    for (ll i = 0; i < n; i++) {
        a[i] = (long long)a[i] ^ (long long)b[i];
        b[i] = (long long)a[i] ^ (long long)b[i];
        a[i] = (long long)a[i] ^ (long long)b[i];
    }
}

// double assum(double *a, ll n);
// double *iamax(double *a, ll n);
