#include <matrix_utils.h>
#include <stdlib.h>

/*
 * @param m: The number of rows in a
 */
double *get_col(double **a, ll m, ll col_index)
{
    double *out = malloc(sizeof(double) * m);

    for (ll i = 0; i < m; i++) {
        out[i] = a[i][col_index];
    }

    return out;
}
