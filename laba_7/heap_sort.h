#ifndef HEAP_SORT
#define HEAP_SORT
#include "sort_funcs.h"
void heap_sort(avto arr[], int n, int (*cmp)(const avto*, const avto*));
void heap_sort_reverse(avto arr[], int n, int (*cmp)(const avto*, const avto*));

#endif