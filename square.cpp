#include <stdio.h>
#include <math.h>
#include <assert.h>

int get_data(struct input_data* data);
void clear_input();
void incorrent_input();
int solve_square(struct input_data* input, struct output_data* output);
int solve_lineal(float b, float c, struct output_data* data);
int count_dixr(float a, float b, float c);
int output_data(struct output_data* data);
void give_answer(const struct output_data* data);
int compare_nums(float a, float b);
struct input_data {
   float a, b, c;
};
struct output_data {
   int info;      // number of solutions
   float x1, x2;  // roots
};
enum {
   ZERO_ROOTS = 0,
   ONE_ROOT = 1,
   TWO_ROOTS = 2,
   INF_ROOTS = 3,
};

int main(){
   float a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
   printf("Let me help you solve your quadratic equation!\n"
          "To do this, enter its coefficients:\n");
   struct input_data input = {};
   get_data(&input);
   struct output_data output;
   solve_square(&input, &output);
   give_answer(&output);
}

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

int solve_square(struct input_data* input, struct output_data* output) {
   float discriminant = NAN, x1 = NAN, x2 = NAN;
   if (input->a != 0){
      if (input->c != 0) {
         discriminant = count_dixr(input->a, input->b, input->c);
         if (compare_nums(discriminant, discriminant)) {
            discriminant = sqrtf(discriminant);
            x1 = (-input->b - discriminant) / (2 * input->a);
            x2 = (-input->b + discriminant) / (2 * input->a);
            if (compare_nums(x1, x2)) {
               output->info = ONE_ROOT;
               output->x1 = x1;
            }
            else {
               output->info = TWO_ROOTS;
               output->x1 = x1;
               output->x2 = x2;
            }
         }
         else {
            output->info = ZERO_ROOTS;
         }
      }
      else {
         if (input->b != 0) {
            output->x1 = 0;
            output->x2 = -input->b / input->a;
            output->info = TWO_ROOTS;
         }
         else {
            output->info = INF_ROOTS;
         }
      }
   }
   else {
      solve_lineal(input->b, input->c, output);    
   }
   return 0;
}

int solve_lineal(float b, float c, struct output_data* data) {
   float x = 0;
   if (b != 0) {
      if (c == 0) {
         x = 0;
         data->info = ONE_ROOT;
         data->x1 = x;
      }
      else {
      x = -c / b;
      data->info = ONE_ROOT;
      data->x1 = x;
      }
   }
   else {
      if (c == 0) {
         data->info = INF_ROOTS; // infinity number of solutions
      }
      else {
         data->info = ZERO_ROOTS;
      }
   }
   return 0;
}

void give_answer(const struct output_data* data) {
   assert (data->info <= 3);
   switch (data->info) {
      case 0: printf("Your equation has no solutions!\n");
      break;
      case 1: printf("Your equation has a single root: x = %.2f\n", data->x1);
      break;
      case 2: printf("Your equation has two roots: x1 = %.2f, x2 = %.2f\n", data->x1, data->x2);
      break;
      case 3: printf("Your equation has an infinite number of solutions!\n");
      break;
   }
}

void clear_stdin() {
   while (getchar() != '\n');
}

void incorrent_input() {
   clear_stdin();
   printf("Please enter the correct coefficient!\n");
}
 
int count_dixr(float a, float b, float c) {
   float D;
   D = b * b - 4 * a * c;
   return D;
}

int compare_nums(float a, float b) {
   return (abs(b - a) < powf(10, -6));
}
