#include <stdio.h>
//#include "input_funcs.h"


int main(){
    int number = 10;
    int* ar = NULL;
    ar = &number;
    printf("%d\n", *ar);
    printf("%p\n", &ar);
    printf("%p\n", ar);


    int x = 1;
    float y = 2.4;
    const char *str = "abd";
    void* a[] = {&x, &y, str};
    printf("Int: %d\n", *(int*)a[0]);        // Приводим к (int*) и разыменовываем
    printf("Float: %.2f\n", *(float*)a[1]);  // Приводим к (float*) и разыменовываем
    printf("String: %s\n", (char*)a[2]);

    return 0; 
}