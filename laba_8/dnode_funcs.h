#ifndef DNODE_FUNCS
#define DNODE_FUNCS
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "list_struct.h"

int get_idx_first_dot(const char *string);
char* cut_string(char *string, int dot_idx);
dnode* create_dnode(char *word);
dnode* create_even_list(char *string);
dnode* create_odd_list(char *string);
dnode* merge_even_odd(dnode *head_even, dnode *head_odd);
void print_list(dnode *head);
void free_list(dnode *head);


#endif