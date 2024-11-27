#include <stdio.h>
#include <stdlib.h> // strtod, strtol
#include <string.h>
#include <limits.h> // для INT_MAX
#include <ctype.h> 


void clean_buffer(){
    scanf("%*[^\n]");
    scanf("%*c");
}

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

int int_input_between_1_10(){
    char input[100];
    int x;
    do
    {
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0;
        x = is_int(input);
        if (x == INT_MAX || x < 2 || x >= 10 || input[0] == '\0')
        {
            printf("Error input pls again_: ");
            input[0] = '\0';
            continue;
        }
        break;
    } while (1);
    return x;
}

int int_input(){
    char input[100];
    int x;
    do
    {
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0;
        x = is_int(input);

        if (x == INT_MAX || input[0] == '\0')
        {
            printf("Error input pls again_: ");
            input[0] = '\0';
            continue;
        }
        break;
    } while (1);
    return x;
}
