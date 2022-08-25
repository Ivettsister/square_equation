#ifndef SQUARE_EQUATION_H
#define SQUARE_EQUATION_H

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "common.h"

/*!
 * \brief A set of the number of solutions to the equation
 */
enum {
   ZERO_ROOTS = 0,  //!< The quation has zero number of roots
   ONE_ROOT   = 1,  //!< The equation has one root
   TWO_ROOTS  = 2,  //!< The equation has two roots
   INF_ROOTS  = 3,  //!< The equation has an infinity number of roots
};

//=============================================================================================

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

//=============================================================================================

/*!
 * \brief get_data - function of entering coeffitients
 * \param[out] data Clear structure with the coeffitients
 */
int get_data(struct input_data* data);

/*!
 * \brief incorrect_input - check if input is incorrect, call function clear_stdin()
 * \see clear_stdin()
 */
void incorrent_input();

//=============================================================================================

/*!
 * \brief solve_square - solves square equation with given coeffitients
 * \param[in] input Structure with the coeffitients of the equation
 * \param[out] output Structure with the information of the number of roots and with roots
 * \note If the coefficient a is 0, call the function solve_lineal()
 * \see solve_lineal()
 */
int solve_square(const struct input_data* input, struct output_data* output);

/*!
 * \brief solve_lineal - solves a lineal equation bx + c = 0
 * \param[in] input Structure with the coeffitients of the equation
 * \param[out] output Structure with the information of the number of roots and with roots
 */
int solve_lineal(const struct input_data* input, struct output_data* output);

/*!
 * \brief count_dixr - count discriminant
 * \param[in] a Coefficient a
 * \param[in] b Coefficient b
 * \param[in] c Coefficient c
 * \return Discriminant of the square equation
 */
float count_dixr(float a, float b, float c);

//=============================================================================================

/*!
 * \brief give_answer - print the result of solving the equation
 * \param[in] output Structure with the information about number of roots and the roots
 */
void give_answer(const struct output_data* output);

#endif // SQUARE_EQUATION_H
