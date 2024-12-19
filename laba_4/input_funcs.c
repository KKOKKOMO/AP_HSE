#include <stdio.h>
#include <stdlib.h> // strtod, strtol
#include <string.h> // strcspn
#include <limits.h> // для INT_MAX DBL_MAX
#include <ctype.h>  //isspace
#include <float.h>


int contains_space(const char *str) {
    while (*str) {
        if (isspace(*str)) {
            return 1;
        }
        str++;
    }
    return 0;
}

int is_int(const char *str) {
    char *endptr; 
    if (contains_space(str)) {
        return INT_MAX;
    }
    const long value = strtol(str, &endptr, 10); 
    if (*endptr != '\0') {
        return INT_MAX;
    }
    return value;
}

double is_double(const char *str) {
    char *endptr = NULL;
    if (contains_space(str)) {
        return DBL_MAX;
    }
    float value = strtod(str, &endptr); 
    if (*endptr != '\0') {
        return DBL_MAX;
    }
    return value; 
}

double get_valid_input_for_double(){
    char input[100];
    double x;
    do
    {
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0;
        x = is_double(input);
        if (x == DBL_MAX || input[0] == '\0')
        {
            printf("Error input pls again: ");
            input[0] = '\0'; 
            continue;
        }
        break;
    } while (1);

    return x;
}

double get_valid_input_for_positive_double(){
    char input[100];
    double x;
    do
    {
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0;
        x = is_double(input);
        if (x == DBL_MAX || x < 0 || input[0] == '\0')
        {
            printf("Error input pls again: ");
            input[0] = '\0'; 
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
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0;
        x = is_int(input);
        if (x == INT_MAX || x < 0 || input[0] == '\0')
        {
            printf("Error input pls again: ");
            input[0] = '\0';
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
