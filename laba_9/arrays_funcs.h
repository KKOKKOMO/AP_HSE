#ifndef ARRAY_FUNCS
#define ARRAY_FUNCS
#include "avto_struct.h"
#include "generate_funcs.h"

void print_avto(avto *some_avto);
void print_records(avto *avto_array, int n);
avto* find_avto_in_array(avto *array, int size_array, char* search_name);
avto* append_to_array(avto *old_array, int *size_array, avto *new_avto);
void linear_search(int num, char* search_name);

#endif