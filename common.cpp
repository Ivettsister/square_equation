#include "common.h"

const double Eps = 1E-6;

void clear_stdin() {
   while (getchar() != '\n');
}

inline int is_equal(const float a, const float b) {
   return compare_difference(a, b, Eps);
}

inline int compare_difference(const float a, const float b, const double eps) {
   return abs(b - a) < eps;
}
