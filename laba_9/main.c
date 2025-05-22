#include "input_funcs.h"
#include "arrays_funcs.h"

int main(){
    avto *found_avto = NULL;
    int size_array = get_valid_input_for_positive_int();
    avto *avto_array = generate_avto_array(size_array);
    print_records(avto_array, size_array);
    avto new = generate_random_avto();
    avto *avto_array_n = NULL;
    avto_array_n = append_to_array(avto_array, &size_array, &new);
    found_avto = find_avto_in_array(avto_array_n, size_array);
    print_records(avto_array_n, size_array);
    print_avto(found_avto);
    return 0;
}