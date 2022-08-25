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

/*!
 * \brief data_comparison - compare right answers of tests with getting answers
 * \param[in] right_data Struct with information about right answers
 * \param[in] test_answers Struct with information about answers that the programm get
 * \param[in] num_test Number of test that is failed or go successfull
 */
void data_comparison(struct output_data* right_data, struct output_data* test_answers, int num_test);

#endif // UNITTEST_H
