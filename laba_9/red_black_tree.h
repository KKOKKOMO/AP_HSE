#ifndef RBIN_TREE_FUNCS
#define RBIN_TREE_FUNCS
#include "red_black_tree.h"
#include "avto_struct.h"

typedef enum { RED, BLACK } Color;

typedef struct rbnode {
    avto data;
    Color color;
    struct rbnode *left, *right, *parent;
} rbnode;

void demo_rb_tree_operations(int num, char* search_name);

#endif