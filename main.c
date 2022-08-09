#include <stdio.h>
#include <math.h>

int count_D(float a, float b, float c);
int check_D(float D);

int main(void){
   float a, b, c, x;
   double x1, x2;
   float dyscr;
   printf("Давайте помогу решить ваше квадратное уравнение!\n");
   printf("Для этого введите его коэффициенты:\n");
   printf("Коэффициент а: ");
   scanf("%f", &a);
   printf("Коэффициент b: ");
   scanf("%f", &b);
   printf("Коэффициент c: ");
   scanf("%f", &c); 
   // уравнение квадратное или линейное?
   if (a != 0){
      if (b != 0){
         if (c != 0){
            dyscr = count_D(a, b, c);
            if (check_D(dyscr) > 0){
               x1 = (-b - pow(dyscr, 0.5)) / (2 * a);
               x2 = (-b + pow(dyscr, 0.5)) / (2 * a);
               if (x1 != x2) {
                  printf("Ваше уравнение имеет два корня: x1 = %.2f, x2 = %.2f\n", x1, x2);
                  return 0;
               }
               else {
                  printf("Ваше уравнение имеет единственный корень: x = %.2f\n", x1);
                  return 0;
               }
            }
            else {
               printf("Ваше уравнение не имеет решений! (Дискриминант отрицательный)\n");
               return 0;
            }
         }
         else {
            x1 = 0;
            x2 = -b / a;
            printf("Ваше уравнение имеет два корня: x1 = %.2f, x2 = %.2f\n", x1, x2);
            return 0;
         }
      }
      if (c != 0){
         if ((-c / a) > 0){
            x1 = pow(-c / a, 0.5);
            x2 = -x1;
            printf("Ваше уравнение имеет два корня: x1 = %.2f, x2 = %.2f\n", x1, x2);
            return 0;
         }
         else {
            printf("Уравнение не имеет решений!");
            return 0;
         }
      }
      else {
         x = 0;
         printf("Ваше уравнение имеет один корень, равный %f\n", x);
         return 0;
      }
   }
   else {
      if (b != 0){
         if (c == 0){
            x = 0;
            printf("Ваше уравнение является линейным и имеет один корень, равный %.0f\n", x);
            return 0;
         }
         else {
         x = -c / b;
         printf("Ваше уравнение является линейным и имеет один корень, равный %.2f\n", x);
         return 0;
         }
      }
      else {
         if (c == 0){
            printf("Ваше уравнение имеет бесконечное число решений!\n");
            return 0;
         }
         else {
            printf("Ваше уравнение не имеет решений!\n");
            return 0;
         }
      }
   }
}

int count_D(float a, float b, float c){
   float D;
   D = b * b - 4 * a * c;
   return D;
}

int check_D(float D){
   if (D >= 0){
      return 1;
   }
   else {
      return 0;
   }
}
