#ifndef ARRAYS_FUNCS
#define ARRAYS_FUNCS

#include <stdio.h>
#include <stdlib.h>

float modul(float number);
float* create_array(int size_array);
void print_array(float* array, int size_array);
float max_modul_el(float* array, int size_array, float y);
float avg_between_pos_el(float* array, int size_array);

#endif

