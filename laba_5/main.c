#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STR_LEN 999
#define MAX_COUNT_WORDS 30
#define MAX_LEN_WORD 11





size_t count_words_in_sentence(const char *original_str){
    if (original_str == NULL)
    return 0;

    size_t number_of_words = 0;
    int len_original_str = strlen(original_str);
    char previos_symbol = original_str[0];

    if (previos_symbol == '\n' || previos_symbol == '\0')
    return 0;
    
    for (size_t i = 0; i < len_original_str; i++)
    {
        if ((original_str[i] == ' ' || original_str[i] == '\n' || original_str[i] == '\0' || original_str[i] == '.')
            && previos_symbol != ' ' && previos_symbol != '.')
        {
            number_of_words++;
        }
        previos_symbol = original_str[i];
    }
    return number_of_words;
}

char **exctract_words_from_sentence(const char *original_str, size_t number_of_words){
    if (number_of_words == 0)
    {
        printf("The sentence has no words");
        exit(0); //return NULL для тестов
    }
    
    char **words_array = NULL;
    char *word = NULL;
    
    size_t size_origin_str = strlen(original_str);
    char copy_original_str[size_origin_str+1];
    strncpy(copy_original_str, original_str, size_origin_str+1);

    printf("ORIGINAL %s\n", original_str);
    printf("COPY %s\n", copy_original_str);
    
    word = strtok(copy_original_str, " .\n");
    words_array = (char**)malloc(number_of_words * sizeof(char*));
    for (size_t i = 0; i < number_of_words; i++)
    {
        words_array[i] = (char*)malloc(MAX_LEN_WORD * sizeof(char));
        strncpy(words_array[i], word, strlen(word) + 1);
        printf("i:%d ADDRESS: %p\n", i ,words_array[i]);
        printf("LEN WORD: %lu\n", strlen(word));
        word = strtok(NULL, " .\n");
        
    }

    return words_array;
}


void free_words_array(char **words_array, int number_of_words) {
    for (int i = 0; i < number_of_words; i++) {
        free(words_array[i]);
    }
    free(words_array);
}


int main(){

    char **words = NULL;
    
    char origin_str[MAX_STR_LEN];
    fgets(origin_str, MAX_STR_LEN-1, stdin);
    size_t size_origin_str = strlen(origin_str);
    char copy_origin_str[size_origin_str+1]; //VLA ARRAY? 
    strncpy(copy_origin_str, origin_str, size_origin_str+1);
    size_t number_of_words = count_words_in_sentence(origin_str);
    printf("number_of_words %d\n", number_of_words);
    words = exctract_words_from_sentence(origin_str, number_of_words);
    for (size_t i = 0; i < number_of_words; i++)
    {
        printf("%s\n", words[i]);
        printf("LEN WORDS[i]: %lu\n", strlen(words[i]));
    }
    


    //printf("%s\n", origin_str);
    //printf("%s\n", copy_origin_str);
    //printf("%d\n", count_words_in_sentence(origin_str));
//
    //printf("%lu\n", strlen(origin_str));
    //printf("%lu\n", strlen(copy_origin_str));

    free_words_array(words, number_of_words);
    return 0;
}