#include <stdio.h>
#include <string.h>
#define MAX_STR_LEN 999
#define MAX_COUNT_WORDS 30
#define MAX_LEN_WORD 11


//TODO:
// Функция для вычленения слов из предложения
// (Будет возвращать указатель на массив слов, 
// в котором последний элемент это последнее словово в исходной строке)
// Функция уделения лишних пробелов ?
// Функция для сравнения слов
// Функция переноса первой буквы в слове
// Функция проверки длинны слов
// Функция проверки кол-во слов в исходной строке
// Тестирующая функция >>> 


int count_words_in_sentence(const char *original_str){
    if (original_str == NULL)
    {
        return -1;
    }

    int words_count = 0;
    int len_original_str = strlen(original_str);
    char previos_symbol = original_str[0];
    if (previos_symbol == '\n')
    {
        return 0;
    }
    
    for (size_t i = 0; i < len_original_str; i++)
    {
        if ((original_str[i] == ' ' || original_str[i] == '\n' || original_str[i] == '\0') && previos_symbol != ' ')
        {
            words_count++;
        }
        previos_symbol = original_str[i];
    }

    return words_count;
}

char* exctract_words_from_sentence(const char *original_str){
    char *words_array = NULL;


    size_t size_original_str = strlen(original_str);
    char copy_original_str[size_original_str+1];
    strncpy(copy_original_str, original_str, size_original_str+1);
    


    return words_array;
}





int main(){
    char origin_str[MAX_STR_LEN];
    fgets(origin_str, MAX_STR_LEN-1, stdin);
    size_t size_origin_str = strlen(origin_str);
    char copy_origin_str[size_origin_str+1]; //VLA ARRAY? VLA массив нельзя вернуть из функции потому-что выходит из области видимости
    strncpy(copy_origin_str, origin_str, size_origin_str+1);

    printf("%s\n", origin_str);
    printf("%s\n", copy_origin_str);
    printf("%d\n", count_words_in_sentence(origin_str));

    printf("%lu\n", strlen(origin_str));
    printf("%lu\n", strlen(copy_origin_str));
    return 0;
}