#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <float.h>
#include <limits.h>
#include <string.h>
//#include "input_funcs.h"
#define SIZE 10

int main(){
    int number = INT_MAX;
    float number_flt = FLT_MAX;
    printf("INT_MAX: %d\n", number);
    printf("FLT_MAX: %f\n", number_flt);

    char pch[] = {'1', '2', '\0', '3'};
    int a = puts(pch);
    printf("RETURN PUTS: %d\n", a);
    printf("%c", *pch);
    char *rstr;
    char line[SIZE]="";
    rstr = gets(line);
    char c;
    scanf("ADD C: %c", &c);
    puts(line);
    printf("\n\n%c", c);
    strncpy()
    return 0; 
}