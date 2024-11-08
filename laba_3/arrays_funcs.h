#ifndef ARRAYS_FUNCS_H
#define ARRAYS_FUNCS_H
#include "input_funcs.h"


int** create_array(int size_array);
void print_array(int** array, int size_array);
void print_pattern(int** array, int array_size);
void free_two_demetnion_array(int** array, int array_size);

#endif
