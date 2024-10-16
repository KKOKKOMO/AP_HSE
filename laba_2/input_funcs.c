#include <stdio.h>
#include <stdlib.h> // strtod, strtol
#include <limits.h> // для INT_MAX
#include <float.h> 


void clean_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
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

float is_float(const char *str) {
    char *endptr;
    float value = strtod(str, &endptr); // Преобразуем строку в вещественное число
                                         // Если endptr указывает на конец строки ('\0'), то ввод корректен
                                         // Если endptr указывает на что-то другое, значит есть лишние символы
    if (*endptr != '\0') {
        return FLT_MAX; // Лишние символы найдены
    }
    return value; // Корректное число
}

float get_valid_input_for_float(){
    char input[100];
    float x;
    do
    {
        //printf("Enter a real number: ");
        scanf("%s", input);
        x = is_float(input);
        if (x == FLT_MAX)
        {
            printf("Error input pls again: ");
            clean_buffer();
            continue;
        }
        break;
    } while (1);

    return x;
}

float get_valid_input_for_positive_float(){
    char input[100];
    float x;
    do
    {
        //printf("Enter a real number: ");
        scanf("%s", input);
        x = is_float(input);
        if (x == FLT_MAX || x < 0)
        {
            printf("Error input pls again: ");
            clean_buffer();
            continue;
        }
        break;
    } while (1);

    return x;
}



int get_valid_input_for_positive_int(){
    char input[100];
    int x;
    do
    {
        //printf("Enter a real number: ");
        scanf("%s", input);
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