#ifndef ARRAYS_FUNCS
#define ARRAYS_FUNCS
#include "input_funcs.h"

double* create_array(int size_array);
void print_array(double* array, int size_array);
int remove_values(double* array, int size_array, double posi_value);
void new_array(double* array, int new_size);

#endif
