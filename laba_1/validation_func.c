#include <stdio.h>
#include <stdlib.h> // strtod, strtol
#include <limits.h> // для INT_MAX
#include <math.h> // для HUGE_VAL



void clean_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

double is_double(const char *str) {
    char *endptr;
    errno = 0; 
    double value = strtod(str, &endptr); // Преобразуем строку в вещественное число
                                         // Если endptr указывает на конец строки ('\0'), то ввод корректен
                                         // Если endptr указывает на что-то другое, значит есть лишние символы
    if (*endptr != '\0') {
        return HUGE_VAL; // Лишние символы найдены
    }

    return value; // Корректное число
}

double get_valid_input_for_double(){
    char input[100];
    double x;
    do
    {
        //printf("Enter a real number: ");
        scanf(" %s", input);
        x = is_double(input);
        if (x == HUGE_VAL)
        {
            printf("Error input pls again: ");
            clean_buffer();
            continue;
        }
        break;
    } while (1);

    return x;
}

double get_valid_input_for_accuracy(){
    char input[100];
    double x;
    do
    {
        //printf("Enter a real number: ");
        scanf(" %s", input);
        x = is_double(input);
        if (x == HUGE_VAL || x <= 0)
        {
            printf("Error input pls again: ");
            clean_buffer();
            continue;
        }
        break;
    } while (1);

    return x;
}

int is_int(const char *str) {
    char *endptr; 
    const long value = strtol(str, &endptr, 10); // Преобразуем строку в вещественное число
                                         // Если endptr указывает на конец строки ('\0'), то ввод корректен
                                         // Если endptr указывает на что-то другое, значит есть лишние символы
    if (*endptr != '\0') {
        return INT_MAX; // Лишние символы найдены
    }

    return value; // Корректное число
}

int get_valid_input_for_int(){
    char input[100];
    int x;
    do
    {
        //printf("Enter a real number: ");
        scanf(" %s", input);
        x = is_int(input);
        if (x == INT_MAX || x < 0)
        {
            printf("Error input pls again: ");
            clean_buffer();
            continue;
        }
        break;
    } while (1);

    return x;
}
