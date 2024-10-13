#ifndef VALID_FUNC_H
#define VALID_FUNC_H
#include <errno.h>  

void clean_buffer();
double is_double(const char *str);
int is_int(const char *str);
double get_valid_input_for_double();
double get_valid_input_for_accuracy();
int get_valid_input_for_int();

#endif
