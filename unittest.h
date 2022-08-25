#ifndef UNITTEST_H
#define UNITTEST_H

#include <stdio.h>
#include <assert.h>
#include "square_equation.h"

/*!
 * \struct test
 * \brief Struct for tests (input and output data)
 */
struct test {
   struct input_data test_data;
   struct output_data right_data;
};

//=============================================================================================

/*!
 * \brief test_program - test the programm with the special coeffitients
 * \warning Give the result of testing the programm, call different asserts
 */
void test_program();

#endif // UNITTEST_H
