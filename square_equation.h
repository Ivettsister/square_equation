#ifndef SQUARE_EQUATION_H
#define SQUARE_EQUATION_H

#include <stdio.h>
#include <math.h>
#include <assert.h>

/**
 * \brief get_data - function of entering coeffitients
 * \param[out] data Clear structure with the coeffitients
 */
int get_data(struct input_data* data);

/**
 * \brief incorrect_input - check if input is incorrect, call function clear_stdin()
 * \see clear_stdin()
 */
void incorrent_input();

/**
 * \brief solve_square - solves square equation with given coeffitients
 * \param[in] input Structure with the coeffitients of the equation
 * \param[out] output Structure with the information of the number of roots and with roots
 * \note If the coefficient a is 0, call the function solve_lineal()
 * \see solve_lineal()
 */
int solve_square(const struct input_data* input, struct output_data* output);

/**
 * \brief solve_lineal - solves a lineal equation bx + c = 0
 * \param[in] input Structure with the coeffitients of the equation
 * \param[out] output Structure with the information of the number of roots and with roots
 */
int solve_lineal(const struct input_data* input, struct output_data* output);

/**
 * \brief count_dixr - count discriminant
 * \param[in] a Coefficient a
 * \param[in] b Coefficient b
 * \param[in] c Coefficient c
 * \return Discriminant of the square equation
 */
float count_dixr(float a, float b, float c);

/**
 * \brief give_answer - print the result of solving the equation
 * \param[in] output Structure with the information about number of roots and the roots
 */
void give_answer(const struct output_data* output);

/**
 * \brief test_program - test the programm with the special coeffitients
 * \warning Give the result of testing the programm, call different asserts
 */
void test_program();

/*!
 * \struct input_data
 * \brief Struct with coefficients
 */
struct input_data {
   float a, b, c; //!< The coeffitients of the square equation
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
 * \struct test
 * \brief Struct for tests (input and output data)
 */
struct test {
   struct input_data test_data;
   struct output_data right_data;
};

/*!
 * \brief A set of the number of solutions to the equation
 */
enum {
   ZERO_ROOTS = 0,  //!< The quation has zero number of roots
   ONE_ROOT   = 1,  //!< The equation has one root
   TWO_ROOTS  = 2,  //!< The equation has two roots
   INF_ROOTS  = 3,  //!< The equation has an infinity number of roots
};

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

#endif // SQUARE_EQUATION_H
