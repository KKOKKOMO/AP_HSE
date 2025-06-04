#ifndef BIN_TREE_FUNCS
#define BIN_TREE_FUNCS
#include "binary_tree.h"

bnode* bt_insert(bnode *root, avto *car_data);
bnode* fill_tree(bnode *root, int num_el);
bnode* bt_find(bnode *root, char *owner_name);
void bnode_free(bnode *root);
void pre_ord_tree_print(bnode *root);
void b_tree_operations(int num, char* search_name);


#endif