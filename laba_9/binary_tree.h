#ifndef BIN_TREE
#define BIN_TREE
#include "avto_struct.h"

typedef struct bnode {
    avto        data;
    struct bnode *left;
    struct bnode *right;
} bnode;


#endif