#include <stdio.h>
#include "series_sum_algorithms.h"


int main(){
    double x;
    double input_ans; // Изменяем на double, чтобы считать дробные числа
    printf("Enter your choice: ");
    scanf("%lf", &input_ans);   // Используем %lf для считывания double



    if (input_ans == 1)
    {
        if (input_ans == (int)input_ans) {
        printf("You entered an integer: %d\n", (int)input_ans);
        } else {
        printf("You entered a floating-point number: %f\n", input_ans);
        }
    } else
    {
        return 1;
    }
    // Проверяем, является ли введенное значение целым
    

    return 0;
}