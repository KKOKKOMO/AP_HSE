#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h> // Только для HUGE_VAL


double is_double(const char *str) {
    char *endptr; 
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
            scanf("%*[^\n]"); //
            scanf("%*c");
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
            scanf("%*[^\n]"); //
            scanf("%*c");
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
            scanf("%*[^\n]");
            scanf("%*c");
            continue;
        }
        break;
    } while (1);

    return x;
}


//int main(){
//
//    char input[100];
//    scanf("%s", input); 
//    int x = get_valid_input_for_int();
//    printf("%d", x);
//    return 0;
//}