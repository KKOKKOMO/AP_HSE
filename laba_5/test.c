#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STR_LEN 999
#define MAX_COUNT_WORDS 30
#define MAX_LEN_WORD 11


int main(){
    char origin_str[MAX_STR_LEN];
    fgets(origin_str, MAX_STR_LEN-1, stdin);
    size_t size_origin_str = strlen(origin_str);
    char copy_origin_str[size_origin_str+1]; //VLA ARRAY? VLA массив нельзя вернуть из функции потому-что выходит из области видимости
    strncpy(copy_origin_str, origin_str, size_origin_str+1);

    printf("ORIGINAL STR: %s\n", origin_str);
    printf("COPY STR: %s\n", copy_origin_str);

    char *pch = NULL;
    pch = strtok(copy_origin_str, " .\n");
    while (pch != NULL)
    {
        printf("strtok STR: %s\n", pch);
        pch = strtok(NULL, " .\n");
    }
    
    //printf("strtok STR: %s\n", pch);
//
    //printf("ORIGINAL STR: %s\n", origin_str);

    //printf("%lu\n", strlen(origin_str));
    //printf("%lu\n", strlen(copy_origin_str));
    return 0;
}