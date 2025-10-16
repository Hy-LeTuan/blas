#include <allocate_utils.h>
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <vector_ops.h>
#include <vector_ops_test.h>

void axpy_test(ll n) {
    double x = 2.0f;
    double y = 3.0f;

    double *a = vec_double_init_rand(n);

    double *res = axpy(a, x, y, n);

    for (ll i = 0; i < n; i++) {
        assert(res[i] == a[i] * x + y);
    }
}

void copy_test(ll n) {
    double *a = vec_double_init_rand(n);
    double *b = copy(a, n);

    for (ll i = 0; i < n; i++) {
        assert(a[i] == b[i]);
    }
}

/*
 * The testing function for swapping 2 vectors. This test should only be called
 * after copy_test has passed, since it depends on the copy function to work
 * properly.
 */
void swap_test(ll n) {
    double *a = vec_double_init_rand(n);
    double *b = vec_double_init_rand(n);

    double *old_a = copy(a, n);
    double *old_b = copy(b, n);

    swap(a, b, n);

    for (int i = 0; i < n; i++) {
        assert(a[i] == old_b[i]);
        assert(b[i] == old_a[i]);
    }
}

void assum_test(ll n) {
    double *a = vec_double_init_rand(n);
    double sum = assum(a, n);

    double test_sum = a[0];

    for (ll i = 1; i < n; i++) {
        test_sum += fabs(a[i]);
    }

    assert(sum == test_sum);
}

void iamax_test(ll n) {
    double *a = vec_double_init_rand(n);

    ll index = iamax(a, n);
    ll max_index = 0;

    for (ll i = 0; i < n; i++) {
        if (a[i] > a[max_index])
            max_index = i;
    }

    assert(index == max_index);
}

int main() {
    ll n = 2000000;

    axpy_test(n);
    copy_test(n);
    swap_test(n);
    assum_test(n);
    iamax_test(n);

    return 0;
}
