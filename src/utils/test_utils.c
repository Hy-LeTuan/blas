#include <math.h>
#include <test_utils.h>

double abs_diff(double a, double b) { return fabs(a - b); }

int approx(double a, double b, double epsilon)
{
    if (abs_diff(a, b) <= epsilon)
        return 1;
    else
        return 0;
}
