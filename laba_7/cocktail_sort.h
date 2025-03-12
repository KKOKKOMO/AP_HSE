#ifndef COCKTAIL_SORT
#define COCKTAIL_SORT
#include "sort_funcs.h"
void cocktail_sort(avto arr[], int n, int (*cmp)(const avto*, const avto*));
void cocktail_sort_reverse(avto arr[], int n, int (*cmp)(const avto*, const avto*));

#endif