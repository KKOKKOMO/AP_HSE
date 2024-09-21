//Дополнительные требования:
//Переход к способу вычисления реализовать на этапе выполнения с помощью условного оператора. +
//Проверять корректность введенных данных на этапе выполнения. В случае ввода пользователем некорректных данных 
//(например, отрицательное число членов ряда) на этапе выполнения, возвращать его к повторному вводу, не завершая выполнение программы.
//Не использовать математические функции (из math.h) для вычисления результата.

//При вводе двухзначного числа, которое начинается с 1,2,3 программа считывает только первое число и не останавливает работу!
//Аналогично для 1.1 если поставить int input

#include <stdio.h>
#include <stdlib.h>
#include "series_sum_algorithms.h"


int main(){
    printf("Hello!\nIf you want to calculate with a given accuracy, enter - 1\nIf you want to count with a given number of elements, enter - 2\n");
    printf("If you want to exit, enter - 3\n");
    do
    {
    double x;
    double input_ans;
    printf("Enter your chose: ");
    scanf(" %lf", &input_ans);  //Не до конца понял, почему нужен пробел " %lf"? stackoverflow 
                                //Beacuse scanf accepts a \n character and leaves it in the buffer. To consume that character you can use:
                                //scanf(" %lf",&ch); Пробел перед %lf говорит функции scanf игнорировать все пробельные символы, такие как пробелы, табуляции и символы новой строки (\n), пока не будет встречен непробельный символ.
                                //scanf(" %lf", &input_ans); fl - позволяет считать целую и дробную часть 
    if (input_ans == 1)         //Поэтому при таком сравнение мы получае True только, когда input_ans == 1, а не 1.1
    {
        double accuracy;
        printf("Please, enter your X: ");
        scanf(" %lf", &x);
        printf("Please, enter your accuracy: ");
        scanf(" %lf", &accuracy);
        printf("Sum of sequence elements -  %.7f\n", approximate_series_sum_with_accuracy(x, accuracy));
    } else if (input_ans == 2)
    {
        int num_terms;
        printf("Please, enter your X: ");
        scanf(" %lf", &x);
        printf("Please, enter number of el. of the series: ");
        scanf(" %d", &num_terms);
        printf("Sum of sequence elements -  %.7f\n", approximate_series_sum_n_terms(x, num_terms));
    } else if (input_ans == 3)
    {
        printf("Goodbye ^_^\n");
        exit(EXIT_SUCCESS); //exit - функция завершения, EXIT_SUCCESS - макрос, аналог 0 - завершение без ошибок
    } else
    {
        printf("Wrong command. Try again\n");
        continue;
    }
    } while (1);
    
    return 0;
}