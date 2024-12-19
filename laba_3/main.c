#include "arrays_funcs.h"


int main(){
    printf("Input array size(1 < N < 10): ");
    int array_size = int_input_between_1_10();
    int **array = create_array(array_size);
    print_array(array, array_size);
    print_pattern(array, array_size);
    free_two_dimension_array(array, array_size);
    return 0;
}
