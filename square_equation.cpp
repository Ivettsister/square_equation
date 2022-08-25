#include "square_equation.h"

const double Eps = 1E-6;

int get_data(struct input_data* data) {
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

int solve_square(const struct input_data* input, struct output_data* output) {
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

void give_answer(const struct output_data* data) {
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

void clear_stdin() {
   while (getchar() != '\n');
}

inline int is_equal(const float a, const float b) {
   return compare_difference(a, b, Eps);
}

inline int compare_difference(const float a, const float b, const double eps) {
   return abs(b - a) < eps;
}

void incorrent_input() {
   clear_stdin();
   printf("Please enter the correct coefficient!\n");
}
 
inline float count_dixr(const float a, const float b, const float c) {
   return b * b - 4 * a * c;
}

void test_program() {
   const double accuracy = 0.01;
   struct test arr[] = {{{1, 2, 1},     {ONE_ROOT, -1.00, 0}}, 
                        {{1, 2, 3},     {ZERO_ROOTS, 0, 0}},
                        {{0, 0, 0},     {INF_ROOTS, 0, 0}}, 
                        {{0, 0, 1},     {ZERO_ROOTS, 0, 0}},
                        {{0, 3, 0},     {ONE_ROOT, 0.00, 0}},
                        {{7, 0, 0},     {ONE_ROOT, 0.00, 0}},
                        {{0, 5, 9},     {ONE_ROOT, -1.80, 0}},
                        {{7, 0, 3},     {ZERO_ROOTS, 0, 0}},
                        {{9, 0, -8},    {TWO_ROOTS, -0.94, 0.94}},
                        {{5, 3, 0},     {TWO_ROOTS, -0.60, 0}},
                        {{5, 9, 4},     {TWO_ROOTS, -1.00, -0.80}},
                        {{6, 132, -21}, {TWO_ROOTS, -22.16, 0.16}}};

   for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
      struct output_data test_answers = {};

      solve_square(&arr[i].test_data, &test_answers);

      if (arr[i].right_data.info != test_answers.info) {
         printf("Test %d is failed\n"
                "Failed: number of roots = %d\n"
                "Expected: number of roots = %d\n", i, test_answers.info, arr[i].right_data.info);
      }
      else {
         switch (test_answers.info) {
            case ZERO_ROOTS: 
               printf("Test %d is successfully passed\n", i);
               break;
            case ONE_ROOT: 
               if (!(compare_difference(arr[i].right_data.x1, test_answers.x1, accuracy))) {
                  printf("Test %d is failed\n"
                         "Failed: number of roots = %d, x = %g\n"
                         "Expected: number of roots = %d, x = %g\n", 
                         i, test_answers.info, test_answers.x1, arr[i].right_data.info, arr[i].right_data.x1);
               }
               else {
                  printf("Test %d is successfully passed\n", i);
               }    
               break;  
            case TWO_ROOTS: 
               if (!(compare_difference(test_answers.x1, arr[i].right_data.x1, accuracy)) || 
                   !(compare_difference(test_answers.x2, arr[i].right_data.x2, accuracy))) {
                  printf("Test %d is failed\n"
                         "Failed: number of roots = %d, x1 = %g, x2 = %g\n"
                         "Expected: number of roots = %d, x1 = %g, x2 = %g\n", 
                         i, test_answers.info, test_answers.x1, test_answers.x2, 
                         arr[i].right_data.info, arr[i].right_data.x1, arr[i].right_data.x2);
               }
               else {
                  printf("Test %d is successfully passed\n", i);
               }
               break;
            case INF_ROOTS: 
               printf("Test %d is successfully passed\n", i);
               break;
            default: assert(0 && "Incorrect number of roots");
         }
      }
   }
}
