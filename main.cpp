#include "square_equation.h"

int main() {
   printf("Let me help you solve your quadratic equation!\n"
          "To do this, enter its coefficients:\n");

   struct input_data input = {};
   get_data(&input);

   struct output_data output = {};
   solve_square(&input, &output);

   give_answer(&output);

   test_program();
}
