#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STR_LEN 999
#define MAX_COUNT_WORDS 30
#define MAX_LEN_WORD 11


size_t first_dot_idx(const char *original_str){
    size_t dot_idx = 0;
    size_t str_len = strlen(original_str);

    for (size_t i = 0; i < str_len; i++)
    {
        if (original_str[i] == '.'){
            //printf("dot_idx: %lu\n", dot_idx);
            return ++dot_idx;
        }
        dot_idx++;
    }
    //printf("dot_idx: %lu\n", dot_idx);
    return str_len;
}

size_t count_words_in_sentence(const char *original_str){
    if (original_str == NULL)
    return 0;

    size_t number_of_words = 0;
    size_t dot_idx = first_dot_idx(original_str);
    //printf("dot_idx: %lu\n", dot_idx);
    int len_original_str = strlen(original_str);
    char previos_symbol = original_str[0];

    if (previos_symbol == '\n' || previos_symbol == '\0')
    return 0;
    
    for (size_t i = 0; i < dot_idx; i++)
    {   
        if ((original_str[i] == ' ' || original_str[i] == '\n' || original_str[i] == '\0' || original_str[i] == '.'|| original_str[i] == '\t')
            && previos_symbol != ' ' && previos_symbol != '.' && previos_symbol != '\t')
        {
            number_of_words++;
        }
        previos_symbol = original_str[i];
    }

    if (number_of_words > 30)
        {
            printf("TOO MUCH WORDS GIVE ME 6))\n");
            return 0;
        }
    return number_of_words;
}

char **exctract_words_from_sentence(const char *original_str, size_t number_of_words, size_t dot_idx){
    if (number_of_words == 0)
    {
        printf("The sentence has no words\n");
        return NULL; //return NULL для тестов
    }
    
    char **words_array = NULL;
    char *word = NULL;
    //size_t dot_idx = first_dot_idx(original_str);
    //printf("dot_idx: %lu\n", dot_idx);
    
    size_t size_origin_str = strlen(original_str);
    char copy_original_str[dot_idx+2]; // 6 8
    strncpy(copy_original_str, original_str, dot_idx+2);
    //printf("LAST STR EL %c\n", copy_original_str[dot_idx+2]);
    copy_original_str[dot_idx+1] = '\0';

    //printf("ORIGINAL %s\n", original_str);
    //printf("COPY STR <%s>\n", copy_original_str);
    word = strtok(copy_original_str, " \t.\n");
    words_array = (char**)malloc(number_of_words * sizeof(char*));
    for (size_t i = 0; i < number_of_words; i++)
    {
        
        words_array[i] = (char*)malloc(MAX_LEN_WORD * sizeof(char));
        strncpy(words_array[i], word, strlen(word) + 1);
        //printf("i:%zu ADDRESS: %p\n", i ,words_array[i]);
        //printf("LEN WORD: %lu\n", strlen(word));
        word = strtok(NULL, " \t.\n");
    }
    return words_array;
}

void free_words_array(char **words_array, int number_of_words) {
    for (int i = 0; i < number_of_words; i++) {
        free(words_array[i]);
    }
    free(words_array);
}

void print_final_sentence(char **words_array, int number_of_words){
    
}


int main(){
    while (1)
    {
        char **words = NULL;
        char origin_str[MAX_STR_LEN];
        fgets(origin_str, MAX_STR_LEN-1, stdin);
        size_t dot_idx = first_dot_idx(origin_str);

        size_t size_origin_str = strlen(origin_str);
        char copy_origin_str[size_origin_str+1]; //VLA ARRAY? 
        strncpy(copy_origin_str, origin_str, size_origin_str+1);

        size_t number_of_words = count_words_in_sentence(origin_str);
        printf("number_of_words %zu\n", number_of_words);

        words = exctract_words_from_sentence(origin_str, number_of_words, dot_idx);
        if (words == NULL)
        {
            free_words_array(words, number_of_words);
            origin_str[0] = '\0';
            /* code */
        }
        
        for (size_t i = 0; i < number_of_words; i++)
        {
            printf("Idx: <%lu> || WORD: <%s> - LEN WORD[%lu]: %lu\n", i+1, words[i], i, strlen(words[i]));
        }

        //printf("%s\n", origin_str);
        //printf("%s\n", copy_origin_str);
        //printf("%d\n", count_words_in_sentence(origin_str));
        //printf("%lu\n", strlen(origin_str));
        //printf("%lu\n", strlen(copy_origin_str));

        free_words_array(words, number_of_words);
        origin_str[0] = '\0';
    }
    
    //char **words = NULL;
    //char origin_str[MAX_STR_LEN];
    //fgets(origin_str, MAX_STR_LEN-1, stdin);
//
    //size_t size_origin_str = strlen(origin_str);
    //char copy_origin_str[size_origin_str+1]; //VLA ARRAY? 
    //strncpy(copy_origin_str, origin_str, size_origin_str+1);
//
    //size_t number_of_words = count_words_in_sentence(origin_str);
    //printf("number_of_words %zu\n", number_of_words);
//
    //words = exctract_words_from_sentence(origin_str, number_of_words);
    //for (size_t i = 0; i < number_of_words; i++)
    //{
    //    printf("WORD: <%s> - LEN WORDS[%lu]: %lu\n", words[i], i, strlen(words[i]));
    //}
    //
//
//
    ////printf("%s\n", origin_str);
    ////printf("%s\n", copy_origin_str);
    ////printf("%d\n", count_words_in_sentence(origin_str));
    ////printf("%lu\n", strlen(origin_str));
    ////printf("%lu\n", strlen(copy_origin_str));
//
    //free_words_array(words, number_of_words);
    //return 0;
}