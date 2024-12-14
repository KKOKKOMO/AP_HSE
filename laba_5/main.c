#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STR_LEN 999
#define MAX_COUNT_WORDS 30
#define MAX_LEN_WORD 11


int first_dot_idx(const char *original_str){
    int dot_idx = 0;
    int str_len = strlen(original_str);

    for (int i = 0; i < str_len; i++)
    {
        if (original_str[i] == '.'){
            //printf("dot_idx: %lu\n", dot_idx);
            return ++i;
        }
    }
    printf("str_len: %d\n", str_len);

    return str_len;
}

int count_words_in_sentence(const char *original_str){
    if (original_str == NULL)
    return 0;

    int number_of_words = 0;
    int dot_idx = first_dot_idx(original_str);
    //printf("dot_idx: %lu\n", dot_idx);
    int len_original_str = strlen(original_str);
    char previos_symbol = original_str[0];

    if (previos_symbol == '\n' || previos_symbol == '\0')
    return 0;
    
    for (int i = 0; i < dot_idx; i++)
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
            printf("TOO MUCH WORDS GIVE ME 6 for labs))\n");
            return 0;
        }
    return number_of_words;
}

char **exctract_words_from_sentence(const char *original_str, int number_of_words, int dot_idx){
    if (number_of_words == 0)
    {
        printf("The sentence has no words\n");
        return NULL; //return NULL для тестов
    }
    
    char **words_array = NULL;
    char *word = NULL;
    //int dot_idx = first_dot_idx(original_str);
    //printf("dot_idx: %lu\n", dot_idx);
    
    int size_origin_str = strlen(original_str);
    //printf("size_origin_str: %d\n", size_origin_str);
    char copy_original_str[dot_idx+2]; // 6 8
    strncpy(copy_original_str, original_str, dot_idx+2);
    //printf("LAST STR EL %c\n", copy_original_str[dot_idx+2]);
    copy_original_str[dot_idx+1] = '\0';

    //printf("ORIGINAL %s\n", original_str);
    //printf("COPY STR <%s>\n", copy_original_str);
    word = strtok(copy_original_str, " \t.\n");
    words_array = (char**)malloc(number_of_words * sizeof(char*));
    for (int i = 0; i < number_of_words; i++)
    {
        words_array[i] = (char*)malloc(MAX_LEN_WORD * sizeof(char));
        strncpy(words_array[i], word, strlen(word) + 1);
        //printf("i:%zu ADDRESS: %p\n", i ,words_array[i]);
        //printf("LEN WORD: %lu\n", strlen(word));
        word = strtok(NULL, " \t.\n");
    }
    return words_array;
}

void find_correct_word(char ***words_array, int *number_of_words){
    char **word_arr = *words_array;
    int j = 0;
    for (int i = 0; i < *number_of_words; i++)
    {
        int curr_len_word = strlen(word_arr[i]);
        if (curr_len_word < 10)
        {
            if (j != i)
            {
                strncpy(word_arr[j], word_arr[i], curr_len_word);
                word_arr[j][curr_len_word] = '\0';
            }
            j++;
        }
    }
    *number_of_words = j;
    //printf("*number_of_words %d\n", *number_of_words);
    *words_array = (char**)realloc(word_arr, *number_of_words*sizeof(char*));
}

char *delete_duplicate_words(char ***words_array, int *number_of_words){
    char **word_arr = *words_array;
    char *last_word = word_arr[*number_of_words-1];
    int j = 0;

    for (int i = 0; i < *number_of_words; i++)
    {
        int curr_len_word = strlen(word_arr[i]);
        if (strcmp(word_arr[i], last_word) != 0)
        {
            if (j != i)
            {
                strncpy(word_arr[j], word_arr[i], curr_len_word);
                word_arr[j][curr_len_word] = '\0';
            }
            j++;
        }
    }
    *number_of_words = j;
    *words_array = (char**)realloc(word_arr, *number_of_words*sizeof(char*));

    return last_word;
}

char *chage_position(char *word){
    int j = 0;
    char first_simbol = word[0];
    for (int i = 1; i < strlen(word); i++)
    {
        word[j] = word[i];
        j++;
    }
    word[strlen(word)-1] = first_simbol;
    return word;
}



void print_final_sentence(char **words_array, char *last_word, int number_of_words){
    for (int i = 0; i < number_of_words; i++)
    {
        if (strcmp(words_array[i], last_word) != 0)
        printf("%s", chage_position(words_array[i]));
        if (i < number_of_words - 1)
        {
            printf(" ");
        }
        else{
            printf(".");
        }
        
    }
    printf("\n");
}

void free_words_array(char **words_array, int number_of_words) {
        for (int i = 0; i < number_of_words; i++)
        free(words_array[i]);
        free(words_array);
    }


int main(){
    while (1)
    {
        char **words = NULL;
        char origin_str[MAX_STR_LEN];
        fgets(origin_str, MAX_STR_LEN-1, stdin);
        int dot_idx = first_dot_idx(origin_str);

        int size_origin_str = strlen(origin_str);
        //char copy_origin_str[size_origin_str+1]; //VLA ARRAY? 
        //strncpy(copy_origin_str, origin_str, size_origin_str+1);

        int number_of_words = count_words_in_sentence(origin_str);
        printf("number_of_words %zu\n", number_of_words);

        words = exctract_words_from_sentence(origin_str, number_of_words, dot_idx);
        //printf("find_correct_word %d\n", find_correct_word(words, &number_of_words));
        find_correct_word(&words, &number_of_words);
        printf("CURR number_of_words %zu\n", number_of_words);
        char *last_word = delete_duplicate_words(&words, &number_of_words);
        printf("CURR number_of_words %zu\n", number_of_words);
        
        for (int i = 0; i < number_of_words; i++)
        {
            printf("Idx: <%lu> || WORD: <%s> - LEN WORD[%lu]: %lu\n", i+1, words[i], i, strlen(words[i]));
        }

        print_final_sentence(words, last_word, number_of_words);

        //char test[] = {'s', '2', '3', '4', '5', '\0'};
        //chage_position(test);
        //printf("%s\n", test);

        //printf("%s\n", origin_str);
        //printf("%s\n", copy_origin_str);
        //printf("%d\n", count_words_in_sentence(origin_str));
        //printf("%lu\n", strlen(origin_str));
        //printf("%lu\n", strlen(copy_origin_str));

        if (words != NULL)
        free_words_array(words, number_of_words);
        origin_str[0] = '\0';
    }
    
    //char **words = NULL;
    //char origin_str[MAX_STR_LEN];
    //fgets(origin_str, MAX_STR_LEN-1, stdin);
//
    //int size_origin_str = strlen(origin_str);
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