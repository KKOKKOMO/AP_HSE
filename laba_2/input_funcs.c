#include <stdio.h>
#include <stdlib.h> // strtod, strtol
#include <limits.h> // для INT_MAX
#include <float.h>
#include <ctype.h> 


void clean_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

int contains_space(const char *str) {
    while (*str) {
        if (isspace(*str)) {
            return 1; // Если найден пробел
        }
        str++;
    }
    return 0; // Если пробелов нет
}

int is_int(const char *str) {
    char *endptr; 

    if (contains_space(str)) {
        //clean_buffer();
        //printf("dasdasdasd\n");
        return INT_MAX; // Если строка содержит пробелы, возвращаем ошибку
    }

    const long value = strtol(str, &endptr, 10); 

    if (*endptr != '\0') {
        return INT_MAX;
    }

    return value;
}

float is_float(const char *str) {
    char *endptr;

    if (contains_space(str)) {
        return FLT_MAX; // Если строка содержит пробелы, возвращаем ошибку
    }

    float value = strtod(str, &endptr); 

    if (*endptr != '\0') {
        return FLT_MAX;
    }
    return value; 
}

float get_valid_input_for_float(){
    char input[100];
    float x;
    do
    {
        scanf("%[^\n]%*c", input);
        x = is_float(input);
        if (x == FLT_MAX)
        {
            printf("Error input pls again: ");
            //clean_buffer();
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
        scanf("%[^\n]%*c", input);
        x = is_float(input);
        if (x == FLT_MAX || x < 0)
        {
            printf("Error input pls again: ");
            //clean_buffer();
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
        scanf("%[^\n]%*c", input);
        x = is_int(input);
        if (x == INT_MAX || x < 0)
        {
            printf("Error input pls again: ");
            //clean_buffer();
            continue;
        }
        break;
    } while (1);

    return x;
}





//Explanation : Here, [] is the scanset character. 
// ^\n tells to take input until newline doesn’t get encountered.
// Here we used ^ (XOR -Operator ) which gives true until both characters are different. 
//Once the character is equal to New-line (‘\n’),  ^ (XOR Operator ) gives false to read the string. 
//So we use “%[^\n]s” instead of “%s”. 
//So to get a line of input with space we can go with scanf(“%[^\n]s”,str);