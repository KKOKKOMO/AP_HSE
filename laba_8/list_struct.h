#ifndef LIST_STRUCT
#define LIST_STRUCT

typedef struct node
{
    int koef;
    int degr;
    struct node *next;
}node;

typedef struct dnode{
    char *word;
    struct dnode *prev;
    struct dnode *next;
} dnode;

#endif