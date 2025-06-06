#ifndef HASHTABLE_FUNC
#define HASHTABLE_FUNC
#include "HashTable.h"
#include "hash_func.h"


void free_table(HashTable* table);
HashNode* search(HashTable* table, char* owner_name, hash_func hash_f);
HashTable* create_and_fill_table(int table_size, int num_items, hash_func hash_f);
void print_table(HashTable* table);

#endif