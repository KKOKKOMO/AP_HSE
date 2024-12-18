#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STR_LEN 5


char *strpbrk_m(char *str_1, char *str_2){
    char *return_str = NULL;
    while (*str_2 != '\0')
    {
        while (*str_1 != '\0')
        {
            if (*str_1 == *str_2)
            {
                return_str = str_1;
                return return_str;
            }
            str_1++;
        }
        str_2++;
    }
    return NULL;
}



int main(){
    char str1[15] = "0i123uiy";
    char str2[] = "12";
    //strncat(str1, str2, 4);
    //printf("%lu\n", strspn(str1, "2"));
    //printf("%s", strpbrk(str1, "2"));
    //printf("%s", strncpy(str1, str2, 0));
    //int *a = (int*)calloc(4, 40);
    //free(a+1);
    //printf("%d", a[5]);
    //printf("%s\n", strchr(str1, '2'));
    //strncmp(str1, str2, 3);
    //printf("%d\n", strncmp(str1, str2, 3));
    //printf("%s\n", str1);
    //printf("%s\n", str2);
    //printf("%s\n", str1);
    //strpbrk();
    printf("strpbrk %s\n", strpbrk(str1, "24"));
    printf("strpbrk_m %s\n", strpbrk_m(str1, "2"));
    //char origin_str[MAX_STR_LEN];
    //printf("INPUT SENTENCE: ");
    //fgets(origin_str, MAX_STR_LEN, stdin);
    //printf("%s\n", origin_str);

    //char str3[] = "qwer";
    return 0;
}