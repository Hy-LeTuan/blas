#include <allocate_utils.h>
#include <assert.h>
#include <vector_vector_ops.h>
#include <vector_vector_ops_test.h>

void scal_test(ll n)
{
    double *x = vec_double_init_rand(n);
    double scalar = 3.0;
    double *out = dscal(x, scalar, n, 1, 0);

    for (ll i = 0; i < n; i++) {
        assert(out[i] == x[i] * scalar);
    }
}

void axpy_no_alpha_test(ll n)
{
    double *x = vec_double_init_rand(n);
    double *y = vec_double_init_rand(n);

    double *out = daxpy_no_alpha(x, y, n, 1, 1, 0, 0);

    for (ll i = 0; i < n; i++) {
        assert(out[i] == x[i] + y[i]);
    }
}

/*
 * The testing function for the axpy operation. This test should only be called
 * after scal_test and axpy_no_alpha_test has passed.
 */
void axpy_test(ll n)
{
    double a = 3.0f;

    double *x = vec_double_init_rand(n);
    double *y = vec_double_init_rand(n);

    double *out = daxpy(a, x, y, n, 1, 1, 0, 0);

    double *test_out = daxpy_no_alpha(dscal(x, a, n, 1, 0), y, n, 1, 1, 0, 0);

    for (ll i = 0; i < n; i++) {
        assert(out[i] == test_out[i]);
    }
}

void copy_test(ll n)
{
    double *a = vec_double_init_rand(n);
    double *b = dcopy(a, n, 1, 0);

    for (ll i = 0; i < n; i++) {
        assert(a[i] == b[i]);
    }
}

/*
 * The testing function for swapping 2 vectors. This test should only be called
 * after copy_test has passed, since it depends on the copy function to work
 * properly.
 */
void swap_test(ll n)
{
    double *a = vec_double_init_rand(n);
    double *b = vec_double_init_rand(n);

    double *old_a = dcopy(a, n, 1, 0);
    double *old_b = dcopy(b, n, 1, 0);

    dswap(a, b, n, 1, 1, 0, 0);

    for (int i = 0; i < n; i++) {
        assert(a[i] == old_b[i]);
        assert(b[i] == old_a[i]);
    }
}

void dot_test(ll n)
{
    double *a = vec_double_init_linspace(n);
    double *b = vec_double_init_linspace(n);

    double out = ddot(a, b, n, 1, 1, 0, 0);
    double out_man = a[0] * b[0];

    for (int i = 1; i < n; i++) {
        out_man += (a[i] * b[i]);
    }

    assert(out_man == out);
}

int main()
{
    ll n = 100000;

    scal_test(n);
    axpy_no_alpha_test(n);
    axpy_test(n);
    copy_test(n);
    swap_test(n);
    dot_test(n);

    return 0;
}
