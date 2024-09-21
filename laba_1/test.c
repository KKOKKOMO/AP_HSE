#include <stdio.h>
#include "series_sum_algorithms.h"


int main(){
    double x;
    double accuracy;
    scanf("%lf", &x);
    scanf("%lf", &accuracy);

    printf("Sum of sequence elements -  %.7f\n", approximate_series_sum_with_accuracy(x, accuracy));
    
    printf("%f\n", x);
    return 0; 
}