#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <float.h>

int main(){
    int intt;
    float floatt;
    char charr;
    int result_1;
    result_1 = scanf("%d %c %f", &intt, &charr, &floatt);
    printf("result 1 - %d\n", result_1);
    printf("int - %d\n", intt);
    printf("char - %c\n", charr);
    printf("float - %f\n", floatt);
    return 0;
}