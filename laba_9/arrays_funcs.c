#include "avto_struct.h"
#include "generate_funcs.h"

avto* find_avto_in_array(avto *array, int size_array, char* search_name){    
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
            some_avto->owner_name, 
            some_avto->car_brand, 
            some_avto->year_of_issue, 
            some_avto->state_license_plate, 
            some_avto->color);
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

void linear_search(int num, char* search_name) {
    printf("================================\n");
    printf("Linear Search Searching for element:\n");
    avto *found_avto = NULL;
    avto *avto_array = generate_avto_array(num);
    //print_records(avto_array, size_array);
    found_avto = find_avto_in_array(avto_array, num, search_name);
    print_avto(found_avto);
}


