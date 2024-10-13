//Лабораторная работа №1.
//ВЫЧИСЛЕНИЯ ПО РЕКУРРЕНТНЫМ ФОРМУЛАМ С ПОМОЩЬЮ ОПЕРАТОРОВ ЦИКЛА.
//Вычислить приближенное значение функции, вычислив сумму конечного числа элементов ряда двумя способами, используя разные типы циклов: 
//1) с заданной точностью (критерий остановки цикла – значение текущего члена ряда не превосходит точность); 
//2) для заданного количества членов ряда. 
//
//Дополнительные требования:
//Переход к способу вычисления реализовать на этапе выполнения с помощью условного оператора. +
//Проверять корректность введенных данных на этапе выполнения. В случае ввода пользователем некорректных данных 
//(например, отрицательное число членов ряда) на этапе выполнения, возвращать его к повторному вводу, не завершая выполнение программы.
//Не использовать математические функции (из math.h) для вычисления результата.
//Программа лоамается если ввести валидное значение для выбора метода, а потом добавить символ не являющийся цифрой
//Так же исправить логику, при которой после срабатывания if (a == 0) пользователя просят заново ввести x

#include <stdio.h>
#include <stdlib.h>
#include "series_sum_algorithms.h"
#include "validation_func.h"


int main(){
    printf("Hello!\n");
    printf("Enter X before starting and then select the counting mode.\n");
    printf("If you want to calculate with a given accuracy, enter - 1.\n");
    printf("If you want to count with a given number of elements, enter - 2.\n");
    printf("If you want to exit, enter - 3\n");
    do
    {
        printf("Please, enter your X: ");
        double x = get_valid_input_for_double();
        int input_ans;
        printf("Select the counting mode: 1 - with accuracy, 2 - with n elements, 3 - exit: ");
        input_ans = get_valid_input_for_int();

        if (input_ans == 1)         
        {
            double accuracy;
            printf("Please, enter your accuracy: ");
            accuracy = get_valid_input_for_accuracy();
            printf("Sum of sequence elements -  %.7f\n", approximate_series_sum_with_accuracy(x, accuracy));
        } else if (input_ans == 2)
        {
            printf("Please, enter number of el. of the series: ");
            int num_terms = get_valid_input_for_int();
            printf("Sum of sequence elements -  %.7f\n", approximate_series_sum_n_terms(x, num_terms));
        } else if (input_ans == 3)
        {
            printf("Goodbye ^_^\n");
            exit(EXIT_SUCCESS);
        } else
        {
            printf("Wrong command. Try again\n");
            clean_buffer();
            continue;
        }
    } while (1);
    
    return 0;
}
