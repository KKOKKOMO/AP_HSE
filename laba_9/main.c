#include "avto_struct.h"
#include "generate_funcs.h"
#include "input_funcs.h"
#include "search_funcs.h"


void print_avto(avto *some_avto){
    printf("Owner: %-15s  Brand: %-10s  Year: %d  License: %d  Color: %s\n", 
            some_avto->owner_name, some_avto->car_brand, some_avto->year_of_issue, 
            some_avto->state_license_plate, some_avto->color);
}



int main(){
    avto *found_avto = NULL;
    int size_array = get_valid_input_for_positive_int();
    avto *avto_array = generate_avto_array(size_array);
    found_avto = find_avto_in_array(avto_array, size_array);
    printRecords(avto_array, size_array);
    print_avto(found_avto);
    








    return 0;
}