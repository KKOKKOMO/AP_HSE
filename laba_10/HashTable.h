#ifndef HASH_TABLE
#define HASH_TABLE
#include "avto_struct.h"

typedef struct HashNode{
    avto car;
    struct HashNode* next;
}HashNode;

typedef struct HashTable
{
    HashNode** items;
    int table_size;
    int count_items;
}HashTable;


#endif