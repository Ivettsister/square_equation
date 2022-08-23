#include <stdio.h>
#include <math.h>

int get_data(struct input_data* data);
int is_correct_input();
int solve_square(float a, float b, float c, struct output_data* data);
int solve_lineal(float b, float c, struct output_data* data);
int count_dixr(float a, float b, float c);
int check_dixr(float D);
int output_data(struct output_data* data);
void give_answer(struct output_data* data);
struct input_data {
   float a, b, c;
};
struct output_data {
   int info;
   float x1, x2;
};

int main(){
   float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
   int info = 0;
   printf("Let me help you solve your quadratic equation!\n"
       "To do this, enter its coefficients:\n");
   struct input_data input;
   get_data(&input);
    a = input.a;
    b = input.b;
    c = input.c;
   // уравнение квадратное или линейное?
   struct output_data output;
   if (a != 0) {
      solve_square(a, b, c, &output);
   }
   else {
      solve_lineal(b, c, &output);
   }
   give_answer(&output);
}

int get_data(struct input_data* data) {
   printf("Сoefficient a: ");
   while (scanf("%f", &(*data).a) != 1) {
      is_correct_input();
   }
   printf("Сoefficient b: ");
   while (scanf("%f", &(*data).b) != 1) {
      is_correct_input();
   }
   printf("Сoefficient c: ");
   while (scanf("%f", &(*data).c) != 1) {
      is_correct_input();
   }
   return 0;
}

int solve_square(float a, float b, float c, struct output_data* data) {
   float discriminant = 0, x1 = 0, x2 = 0, x = 0;
   if (b != 0) {
         if (c != 0) {
            discriminant = sqrtf(count_dixr(a, b, c));
            if (check_dixr(discriminant) > 0) {
               x1 = (-b - discriminant) / (2 * a);
               x2 = (-b + discriminant) / (2 * a);
               if (x1 != x2) {
                  (*data).info = 2;
                  (*data).x1 = x1;
                  (*data).x2 = x2;
                  return 0;
               }
               else {
                  (*data).info = 1;
                  (*data).x1 = x1;
                  return 0;
               }
            }
            else {
               (*data).info = 0;
               return 0;
            }
         }
         else {
            x1 = 0;
            x2 = -b / a;
            (*data).info = 2;
            (*data).x1 = x1;
            (*data).x2 = x2;
            return 0;
         }
   }
   else {
      if (c != 0) {
         if ((-c / a) > 0) {
            x1 = sqrtf(-c / a);
            x2 = -x1;
            (*data).info = 2;
            (*data).x1 = x1;
            (*data).x2 = x2;
            return 0;
         }
         else {
            (*data).info = 0;
            return 0;
         }
      }
      else {
         x = 0;
         (*data).info = 1;
         (*data).x1 = x;
         return 0;
      }
   }
}

int solve_lineal(float b, float c, struct output_data* data) {
   float x = 0;
   if (b != 0) {
         if (c == 0) {
            x = 0;
            (*data).info = 1;
            (*data).x1 = x;
            return 0;
         }
         else {
         x = -c / b;
         (*data).info = 1;
         (*data).x1 = x;
         return 0;
         }
   }
   else {
      if (c == 0) {
         (*data).info = 3; //infinity number of solutions//
         return 0;
      }
      else {
         (*data).info = 0;
         return 0;
      }
   }
}

void give_answer(struct output_data* data) {
   int info = 0;
   float x1 = 0, x2 = 0;
   info = (*data).info;
   if (info == 0) {
      printf("Your equation has no solutions!\n");
   }
   else {
      if (info == 1) {
         x1 = (*data).x1;
         printf("Your equation has a single root: x = %.2f\n", x1);
      }
      else {
         if (info == 2) {
            x1 = (*data).x1;
            x2 = (*data).x2;
            printf("Your equation has two roots: x1 = %.2f, x2 = %.2f\n", x1, x2);
         }
         else {
            printf("Your equation has an infinite number of solutions!\n");
         }
      }
   }
}

int is_correct_input() {
   while (getchar() != '\n');
   printf("Please enter the correct coefficient!\n");
   return 0;
}

int count_dixr(float a, float b, float c) {
   float D;
   D = b * b - 4 * a * c;
   return D;
}

int check_dixr(float D) {
   if (D >= 0){
      return 1;
   }
   else {
      return 0;
   }
}
