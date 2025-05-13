#ifndef VALID_FUNC_H
#define VALID_FUNC_H
#include <stdio.h>
#include <stdlib.h>


void clean_buffer();
double is_double(const char *str);
int is_int(const char *str);
float get_valid_input_for_float();
float get_valid_input_for_norm_float();
int get_valid_input_for_positive_int();

#endif