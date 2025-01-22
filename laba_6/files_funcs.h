#ifndef FILES_FUNCS
#define FILES_FUNCS
#include <io.h>
#include "avto_struct.h"
#include "input_funcs.h"

struct avto input_avto();
void add_record(FILE *file);
void change_record(FILE *file, int index);
void display_records(FILE *file);
void delete_record(FILE *file, int index);
void search_by_owner_name(FILE *file);
void search_by_car_brand(FILE *file);
void search_by_color(FILE *file);
void search_by_year_of_issue(FILE *file);
void search_by_state_license_plate(FILE *file);
void get_records(FILE *file);

#endif