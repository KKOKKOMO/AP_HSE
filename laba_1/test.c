#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Только для HUGE_VAL
//#include "series_sum_algorithms.h"

double is_real(const char *str) {
    char *endptr; 
    double value = strtod(str, &endptr); // Преобразуем строку в вещественное число
                                         // Если endptr указывает на конец строки ('\0'), то ввод корректен
                                         // Если endptr указывает на что-то другое, значит есть лишние символы
    if (*endptr != '\0') {
        return HUGE_VAL; // Лишние символы найдены
    }

    return value; // Корректное число
}

double get_valid_input(){
    char input[100];
    double x;
    int flag;
    do
    {
        printf("Enter a real number: ");
        scanf("%s", input);
        x = is_real(input);
        if (x == HUGE_VAL)
        {
            printf("Error input pls again\n");
            continue;
        }
        break;
    } while (1);

    return x;
}


int main() {
    double x = get_valid_input();
    printf("%lf", x);
    return 0;
}