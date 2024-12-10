#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 999
#define MAX_COUNT_WORDS 30
#define MAX_LEN_WORD 11


int str_func(const char *origin_str){
    if (origin_str == NULL)
    return 1;

    size_t size_origin_str = strlen(origin_str);
    char copy_origin_str[size_origin_str+1];
    strncpy(copy_origin_str, origin_str, size_origin_str+1);
    
}





int main(){
    char origin_str[MAX_STR_LEN];
    fgets(origin_str, MAX_STR_LEN-1, stdin);
    size_t size_origin_str = strlen(origin_str);
    char copy_origin_str[size_origin_str+1];
    strncpy(copy_origin_str, origin_str, size_origin_str+1);

    printf("%s\n", origin_str);
    printf("%s\n", copy_origin_str);

    printf("%d\n", strlen(origin_str));
    printf("%d\n", strlen(copy_origin_str));
    

    //char* pch = strtok(origin_str, " ");
    //while (pch != NULL)
    //{
    //    printf("%s", pch);
    //    pch = strtok(NULL, " ");
    //}
    //
    //
//
    //printf("%s", origin_str);

    return 0;
}