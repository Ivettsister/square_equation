#include "unittest.h"

void data_comparison(struct output_data* right_data, struct output_data* test_answers, int num_test) {
   const double accuracy = 0.01;
   if (right_data->info != test_answers->info) {
         printf("Test %d is failed\n"
                "Failed: number of roots = %d\n"
                "Expected: number of roots = %d\n", num_test, test_answers->info, right_data->info);
      }
      else {
         switch (test_answers->info) {
            case ZERO_ROOTS: 
               printf("Test %d is successfully passed\n", num_test);
               break;
            case ONE_ROOT: 
               if (!(compare_difference(right_data->x1, test_answers->x1, accuracy))) {
                  printf("Test %d is failed\n"
                         "Failed: number of roots = %d, x = %g\n"
                         "Expected: number of roots = %d, x = %g\n", 
                         num_test, test_answers->info, test_answers->x1, right_data->info, right_data->x1);
               }
               else {
                  printf("Test %d is successfully passed\n", num_test);
               }    
               break;  
            case TWO_ROOTS: 
               if (!(compare_difference(test_answers->x1, right_data->x1, accuracy)) || 
                   !(compare_difference(test_answers->x2, right_data->x2, accuracy))) {
                  printf("Test %d is failed\n"
                         "Failed: number of roots = %d, x1 = %g, x2 = %g\n"
                         "Expected: number of roots = %d, x1 = %g, x2 = %g\n", 
                         num_test, test_answers->info, test_answers->x1, test_answers->x2, 
                         right_data->info, right_data->x1, right_data->x2);
               }
               else {
                  printf("Test %d is successfully passed\n", num_test);
               }
               break;
            case INF_ROOTS: 
               printf("Test %d is successfully passed\n", num_test);
               break;
            default: assert(0 && "Incorrect number of roots");
         }
      }
}

void test_program() {
   struct test arr[] = {{{1, 2,   1},   {ONE_ROOT,   -1.00, 0}}, 
                        {{1, 2,   3},   {ZERO_ROOTS, 0,     0}},
                        {{0, 0,   0},   {INF_ROOTS,  0,     0}}, 
                        {{0, 0,   1},   {ZERO_ROOTS, 0,     0}},
                        {{0, 3,   0},   {ONE_ROOT,   0.00,  0}},
                        {{7, 0,   0},   {ONE_ROOT,   0.00,  0}},
                        {{0, 5,   9},   {ONE_ROOT,   -1.80, 0}},
                        {{7, 0,   3},   {ZERO_ROOTS, 0,     0}},
                        {{9, 0,   -8},  {TWO_ROOTS,  -0.94, 0.94}},
                        {{5, 3,   0},   {TWO_ROOTS,  -0.60, 0}},
                        {{5, 9,   4},   {TWO_ROOTS,  -1.00, -0.80}},
                        {{6, 132, -21}, {TWO_ROOTS,  -22.16, 0.16}}};

   for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
      struct output_data test_answers = {};

      solve_square(&arr[i].test_data, &test_answers);

      data_comparison(&(arr[i].right_data), &test_answers, i);
   }
}
