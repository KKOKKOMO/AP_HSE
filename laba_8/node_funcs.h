#ifndef NODE_FUNCS
#define NODE_FUNCS
#include <stdio.h>
#include "list_struct.h"
#include "input_funcs.h"

node* append(node* head);
void print_poly(node *head);
node* merge_lists(node* head_1, node* head_2);
void free_memory(node *head);


#endif