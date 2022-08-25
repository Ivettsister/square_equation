#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <math.h>
#include <assert.h>

/**
 * \brief clear_stdin - clear stdin
 */
void clear_stdin();

/**
 * \brief is_equal - compare two numbers
 * \param[in] a First number
 * \param[in] b Second number
 * \return The result of comparing of the two numbers
 */
int is_equal(float a, float b);

/*!
 * \brief compare_difference - compare the difference between a and b and some constant
 */
int compare_difference(const float a, const float b, const double eps);

#endif // COMMON_H
