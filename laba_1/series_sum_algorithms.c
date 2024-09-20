#include <stdio.h>
#include "series_sum_algorithms.h"


double approximate_series_sum_with_accuracy(double x, double accuracy){
    if (accuracy <= 0.0)
    {
        printf("Accuracy must be greater than zero.\n");
        return 0.0;
    }
    double curr_number = 0.0;
    double sum = 0.0;
    int term_index = 1;

    do
    {
        int temp_power = (2*term_index - 1);
        curr_number = ((power(x, temp_power)/factorial(temp_power)));
        sum += curr_number;
        //if (curr_number < accuracy) Не понимаю, надо ли выводить пограничное значение: текущий элемент меньше точности.
        //{
        //    break;
        //}
        printf("%d: %.7f\nCurrenly number is: %.7f\nAccuracy: %.7f\n-------------------\n", term_index, sum, curr_number, accuracy);
        term_index++;
    } while (curr_number > accuracy);    
    return sum;
}

double approximate_series_sum_n_terms(double x, int num_terms){
    double curr_number = 0.0;
    double sum = 0.0;
    for (int i = 1; i <= num_terms; i++) {
        int temp_power = (2*i - 1);
        curr_number = ((power(x, temp_power)/factorial(temp_power)));
        sum += curr_number;
        //sum += ((power(x, temp_power)/factorial(temp_power)));
        printf("%d: %.7f\nCurrenly number is: %.7f\n-------------------\n", i, sum, curr_number);
    }
    return sum;
}