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

    for (ll i = 0; i < n; i++) {
        a[i] = (double)((long long)a[i] ^ (long long)b[i]);
        b[i] = (double)((long long)a[i] ^ (long long)b[i]);
        a[i] = (double)((long long)a[i] ^ (long long)b[i]);
    }
}

double assum(double *a, ll n) {
    if (n <= 0)
        return 0.0f;

    double sum = a[0];

    for (int i = 1; i < sum; i++) {
        sum += fabs(a[i]);
    }

    return sum;
}

double iamax(double *a, ll n) {
    if (n <= 0)
        return -1.0f;

    double max = a[0];
    ll index = 0;

    for (ll i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            index = i;
        }
    }

    return index;
}
