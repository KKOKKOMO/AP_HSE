#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list_struct.h"


int get_idx_first_dot(const char *string){
    int dot_idx = -1;
    int str_len = strlen(string);

    for (int i = 0; i < str_len; i++)
    {
        if (string[i] == '.'){
            dot_idx = i;
            return i;
        }
    }
    return dot_idx;
}

char* cut_string(char *string, int dot_idx){
    char* cutted_str = (char*)malloc(dot_idx + 1);
    strncpy(cutted_str, string, dot_idx);
    cutted_str[dot_idx] = '\0';
    return cutted_str;
}

dnode* create_dnode(char *word){
    dnode *d_node = (dnode*)malloc(sizeof(dnode));
    d_node->word = strdup(word);
    d_node->next = NULL;
    d_node->prev = NULL;
    return d_node;
}

dnode* create_even_list(char *string){
    dnode *head = NULL;
    int len_word = 0;
    char *word = strtok(string, " ");
    while (word != NULL)
    {
        if (strlen(word) % 2 == 0)
        {
            dnode *new_dnode = create_dnode(word);
            new_dnode->next = head;
            if (head != NULL)
                head->prev = new_dnode;
            head = new_dnode;
        }
        word = strtok(NULL, " ");
    }
    return head;
}

dnode* create_odd_list(char *string){
    dnode *head = NULL;
    int len_word = 0;
    char *word = strtok(string, " ");
    while (word != NULL)
    {
        if (strlen(word) % 2 != 0)
        {
            dnode *new_dnode = create_dnode(word);
            new_dnode->next = head;
            if (head != NULL)
                head->prev = new_dnode;
            head = new_dnode;
        }
        word = strtok(NULL, " ");
    }
    return head;
}

dnode* merge_even_odd(dnode *head_even, dnode *head_odd){
    dnode* cur = head_even;
    while (cur->next)
        cur = cur->next;

    cur->next = head_odd;
    head_odd->prev = cur;
    return head_even;
}


void print_list(dnode *head){
    while (head)
    {
        printf("%s ", head->word);
        head = head->next;
    }
}

void free_list(dnode *head){
    while (head) {
        dnode *nx = head->next;
        free(head->word);
        free(head);
        head = nx;
    }
}
