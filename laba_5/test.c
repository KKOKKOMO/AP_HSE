#include <stdio.h>


int main(){

    int result_puts = 10;
    int* ptr = NULL;
    ptr = &result_puts; 
    printf("%p\n", &ptr);
    printf("%p\n", ptr);
    return 0;
}