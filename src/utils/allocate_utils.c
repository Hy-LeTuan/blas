#include <allocate_utils.h>
#include <stdlib.h>

double *vec_double_init_linspace(ll n)
{
    double *out = (double *)malloc(sizeof(double) * n);

    for (ll i = 0; i < n; i++) {
        out[i] = (double)i;
    }

    return out;
}

double *vec_double_init_rand(ll n)
{
    double *out = (double *)malloc(sizeof(double) * n);

    for (ll i = 0; i < n; i++) {
        out[i] = ((double)rand()) / RAND_MAX;
    }

    return out;
}

double **mat_double_init_linspace_array(ll m, ll n)
{
    double **a = malloc(sizeof(double *) * m);

    for (ll i = 0; i < m; i++) {
        a[i] = vec_double_init_linspace(n);
    }

    return a;
}

double **mat_double_init_rand_array(ll m, ll n)
{
    double **a = malloc(sizeof(double *) * m);

    for (ll i = 0; i < m; i++) {
        a[i] = vec_double_init_rand(n);
    }

    return a;
}

double *mat_double_init_linspace(ll m, ll n)
{
    double *out = malloc(sizeof(double) * m * n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            out[i * n + j] = j;
        }
    }

    return out;
}

double *mat_double_init_rand(ll m, ll n)
{
    double *out = malloc(sizeof(double) * m * n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            out[i * n + j] = ((double)rand()) / RAND_MAX;
        }
    }

    return out;
}
