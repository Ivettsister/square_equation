// #define NDEBUG

#include "square_equation.h"
#include "unittest.h"

int main() {
#ifdef NDEBUG   
   printf("Let me help you solve your quadratic equation!\n"
          "To do this, enter its coefficients:\n");

   struct input_data input = {};
   get_data(&input);

   struct output_data output = {};
   solve_square(&input, &output);

   give_answer(&output);
#else
   test_program();
#endif // NDEBUG
}
