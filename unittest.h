#ifndef UNITTEST_H
#define UNITTEST_H

#include <stdio.h>
#include <assert.h>

/*!
 * \brief A set of the number of solutions to the equation
 */
enum {
   ZERO_ROOTS = 0,  //!< The quation has zero number of roots
   ONE_ROOT   = 1,  //!< The equation has one root
   TWO_ROOTS  = 2,  //!< The equation has two roots
   INF_ROOTS  = 3,  //!< The equation has an infinity number of roots
};

/*!
 * \struct test
 * \brief Struct for tests (input and output data)
 */
struct test {
   struct input_data test_data;
   struct output_data right_data;
};

/*!
 * \struct output_data
 * \brief Struct with the information about the number of roots of the equation and the roots
 */
struct output_data {
   int info;      //!< Number of solutions
   float x1, x2;  //!< Roots
};

/*!
 * \struct input_data
 * \brief Struct with coefficients
 */
struct input_data {
   float a, b, c; //!< The coeffitients of the square equation
};

/**
 * \brief test_program - test the programm with the special coeffitients
 * \warning Give the result of testing the programm, call different asserts
 */
void test_program();

#endif // UNITTEST_H