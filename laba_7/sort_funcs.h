#ifndef SORT_FUNCS
#define SORT_FUNCS
#include "avto_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(struct avto *a, struct avto *b);
int avto_compare(const struct avto *fisrt, const struct avto *second);
void printRecords(struct avto arr[], int n);
void print_two_type_sort(sort_func_ptr sort_func, sort_func_ptr sort_func_reverse);
double measure_time(sort_func_ptr some_sort, struct avto arr[], int n, int (*cmp)(const struct avto*, const struct avto*));

#endif