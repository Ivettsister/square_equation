#include "square_equation.h"

int get_data(struct input_data* data) {
   assert(data != nullptr);

   printf("Сoefficient a: ");
   while (scanf("%g", &data->a) != 1) {
      incorrent_input();
   }
   printf("Сoefficient b: ");
   while (scanf("%g", &data->b) != 1) {
      incorrent_input();
   }
   printf("Сoefficient c: ");
   while (scanf("%g", &data->c) != 1) {
      incorrent_input();
   }
   return 0;
}

void incorrent_input() {
   clear_stdin();
   printf("Please enter the correct coefficient!\n");
}

//=============================================================================================

int solve_square(const struct input_data* input, struct output_data* output) {
   assert(input  != nullptr);
   assert(output != nullptr);

   if (!is_equal(input->a, 0)) {
      if (!is_equal(input->c, 0)) {
         float discriminant = count_dixr(input->a, input->b, input->c);
         if (is_equal(discriminant, 0)) {
            output->x1 = -input->b / (2 * input->a);
            output->info = ONE_ROOT;
         }
         else if (discriminant > 0) {
            /* sqrt_*/ discriminant = sqrtf(discriminant);
            double x1 = (-input->b - discriminant) / (2 * input->a);
            double x2 = (-input->b + discriminant) / (2 * input->a);
            output->x1 = (x1 < x2) ? x1 : x2;
            output->x2 = (x1 > x2) ? x1 : x2;
            output->info = TWO_ROOTS;
         } 
         else {
            output->info = ZERO_ROOTS;
         }
      }
      else {
         if (!is_equal(input->b, 0)) {
            double x = -input->b / input->a;
            output->x1 = (x < 0) ? x : 0;
            output->x2 = (x > 0) ? x : 0;
            output->info = TWO_ROOTS;
         }
         else {
            output->x1 = 0;
            output->info = ONE_ROOT;
         }
      }
   }
   else {
      solve_lineal(input, output);    
   }
   return 0;
}

int solve_lineal(const struct input_data* input, struct output_data* data) {
   assert(input != nullptr);
   assert(data  != nullptr);

   if (!is_equal(input->b, 0)) {
      if (is_equal(input->c, 0)) {
         data->x1 = 0;
         data->info = ONE_ROOT;
      }
      else {
      data->x1 = -input->c / input->b;
      data->info = ONE_ROOT;
      }
   }
   else {
      data->info = is_equal(input->c, 0) ? INF_ROOTS : ZERO_ROOTS;
   }
   return 0;
}

inline float count_dixr(const float a, const float b, const float c) {
   return b * b - 4 * a * c;
}

//=============================================================================================

void give_answer(const struct output_data* data) {
   assert(data != nullptr);

   switch (data->info) {
      case 0: printf("Your equation has no solutions!\n");
              break;
      case 1: printf("Your equation has a single root: x = %.2f\n", data->x1);
              break;
      case 2: printf("Your equation has two roots: x1 = %.2f, x2 = %.2f\n", data->x1, data->x2);
              break;
      case 3: printf("Your equation has an infinite number of solutions!\n");
              break;
      default: assert(0 && "Incorrect number of solutions");
   }
}
