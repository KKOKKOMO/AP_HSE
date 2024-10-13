#include <stdio.h>
#include "validation_func.h"

void test_get_valid_input_for_double() {
    printf("Test case 1: Enter a valid double (e.g., 3.14)\n");
    double result = get_valid_input_for_double();
    printf("Result: %.7f\n", result); // Ожидается: должно вывести введенное значение
    printf("-----------------------------------\n");

    printf("Test case 2: Enter an invalid string (e.g., abc)\n");
    result = get_valid_input_for_double();
    printf("Result: %.7f\n", result); // Ожидается: должно запросить ввод снова
    printf("-----------------------------------\n");

    printf("Test case 3: Enter a number in exponential form (e.g., 2.5e2)\n");
    result = get_valid_input_for_double();
    printf("Result: %.7f\n", result); // Ожидается: должно правильно интерпретировать экспоненциальную форму
    printf("-----------------------------------\n");

    printf("Test case 4: Enter a mixed input (e.g., 12abc)\n");
    result = get_valid_input_for_double();
    printf("Result: %.7f\n", result); // Ожидается: должно отклонить ввод и запросить снова
    printf("-----------------------------------\n");

    printf("Test case 5: Enter a number bigger than MAX_DOUBLE/HUGE_VAL (e.g., 12abc)\n");
    result = get_valid_input_for_double();
    printf("Result: %.7f\n", result); // Ожидается: должно отклонить ввод и запросить снова
}


int main() { 
    test_get_valid_input_for_double();
    return 0;
}