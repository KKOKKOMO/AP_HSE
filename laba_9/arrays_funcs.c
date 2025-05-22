#include "avto_struct.h"
#include "generate_funcs.h"

avto* find_avto_in_array(avto *array, int size_array){
    printf("Input name for search: ");
    char search_name[100];
    fgets(search_name, 99, stdin);
    printf("\n");

    for (int i = 0; i < 100; i++)
    {
        if (search_name[i] == '\n')
            search_name[i] = '\0';
    }
    

    avto *avto_to_find = NULL;
    for (int i = 0; i < size_array; i++)
    {
        if (strcmp(search_name, array[i].owner_name) == 0){
            avto *find_avto = &array[i];
            return find_avto;
        }
    }

    printf("Avto array hasn`t avto with owner name: %s\n", search_name);
    return NULL;
}

void print_records(avto *avto_array, int n) {
    for (int i = 0; i < n; i++) {
        printf("Id: %d  Owner: %-15s  Brand: %-10s  Year: %d  License: %d  Color: %s\n", 
            i, avto_array[i].owner_name, avto_array[i].car_brand, avto_array[i].year_of_issue, 
            avto_array[i].state_license_plate, avto_array[i].color);
    }
}

void print_avto(avto *some_avto){
    printf("Owner: %-15s  Brand: %-10s  Year: %d  License: %d  Color: %s\n", 
            some_avto->owner_name, some_avto->car_brand, some_avto->year_of_issue, 
            some_avto->state_license_plate, some_avto->color);
}

avto* append_to_array(avto *old_array, int *size_array, avto *new_avto){
    int new_size = *size_array + 1;
    avto *new_array = (avto*)realloc(old_array, sizeof(avto)*new_size);
    if (!new_array)
        return old_array;
    
    new_array[new_size-1] = *new_avto;
    *size_array = new_size;
    return new_array;
}


