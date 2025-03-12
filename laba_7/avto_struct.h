#ifndef AVTO_STRUCT
#define AVTO_STRUCT

typedef struct avto
{
    char owner_name[100];
    char car_brand[20];
    int year_of_issue;
    int state_license_plate;
    char color[20];
} avto;

typedef void (*sort_func_ptr)(avto arr[], int n, int (*cmp)(const avto*, const avto*));

#endif