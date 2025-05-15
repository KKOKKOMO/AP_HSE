#ifndef LIST_STRUCT_H
#define LIST_STRUCT_H

typedef struct node{
    char *word;
    struct node *prev;
    struct node *next;
} node;
#endif