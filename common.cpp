#include "common.h"

const double Eps = 1E-6;

void clear_stdin() {
    while (getchar() != '\n');
}

int is_equal(const float a, const float b) {
    assert(!isnan(a));
    assert(!isnan(b));

    return compare_difference(a, b, Eps);
}

int compare_difference(const float a, const float b, const double eps) {
	assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(eps));
   
    return abs(b - a) < eps;
}
