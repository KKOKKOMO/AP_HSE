#ifndef BUBBLE_SORT
#define BUBBLE_SORT
#include "sort_funcs.h"
void bubble_sort(avto arr[], int n, int (*cmp)(const avto*, const avto*));
void bubble_sort_reverse(avto arr[], int n, int (*cmp)(const avto*, const avto*));

#endif