#include <allocate_utils.h>
#include <stdlib.h>

double *vec_double_init_linspace(ll n) {
    double *out = (double *)malloc(sizeof(double) * n);

    for (ll i = 0; i < n; i++) {
        out[i] = (double)i;
    }

    return out;
}

double *vec_double_init_rand(ll n) {
    double *out = (double *)malloc(sizeof(double) * n);

    for (ll i = 0; i < n; i++) {
        out[i] = ((double)rand()) / RAND_MAX;
    }

    return out;
}
