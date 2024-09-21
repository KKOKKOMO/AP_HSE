//Дополнительные требования:
//Переход к способу вычисления реализовать на этапе выполнения с помощью условного оператора. +
//Проверять корректность введенных данных на этапе выполнения. В случае ввода пользователем некорректных данных 
//(например, отрицательное число членов ряда) на этапе выполнения, возвращать его к повторному вводу, не завершая выполнение программы.
//Не использовать математические функции (из math.h) для вычисления результата.
#include <stdio.h>
#include <stdlib.h>
#include "series_sum_algorithms.h"


int main(){
    //printf("Sum of sequence elements -  %.7f\n", approximate_series_sum_n_terms(12.0, 20));
    //printf("Sum of sequence elements -  %.7f\n", approximate_series_sum_with_accuracy(12.0, 2.5));
    printf("Hello!\nIf you want to calculate with a given accuracy, enter - 1\nIf you want to count with a given number of elements, enter - 2\n");
    printf("If you want to exit, enter - 3\n");
    do
    {
    char input_ans;
    printf("Enter your chose: ");
    scanf("%c", &input_ans);
    //printf("%c\n", input_ans);

    if (input_ans == '1')
    {
        double x;
        double accuracy;
        printf("Please, enter your X: ");
        scanf("%lf", &x);
        printf("Please, enter your accuracy: ");
        scanf("%lf", &accuracy);
        printf("Sum of sequence elements -  %.7f\n", approximate_series_sum_with_accuracy(x, accuracy));
    } else if (input_ans == '2')
    {
        double x;
        int num_terms;
        printf("Please, enter your X: ");
        scanf("%lf", &x);
        printf("Please, enter number of el. of the series: ");
        scanf("%d", &num_terms);
        printf("Sum of sequence elements -  %.7f\n", approximate_series_sum_n_terms(x, num_terms));
        /* code */
    } else if (input_ans == '3')
    {
        printf("Goodbye ^_^\n");
        exit(EXIT_SUCCESS);
        /* code */
    } else
    {
        /* code */
    }
    } while (1);
    
    return 0;
}