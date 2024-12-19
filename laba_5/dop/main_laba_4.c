#include "arrays_funcs.h"


int main(){
    int size_array;
    int new_size_array;
    double positive_value;
    double* array = NULL;
    printf("INPUT ARRAY SIZE: ");
    size_array = get_valid_input_for_positive_int();
    if (size_array == 0)
    {
        printf("ARRAY SIZE - 0\n");
        return 0;
    }
    printf("\nINPUT POSITIVE VALUE: ");
    positive_value = get_valid_input_for_positive_double();
    
    array = create_array(size_array);
    new_size_array = remove_values(array, size_array, positive_value);
    if (new_size_array == 0)
    {
        printf("New array have size 0\n");
        return 0; 
    }
    
    printf("\n");
    printf("ARRAY WITH OLD ARRAY SIZE(%d): \n", size_array);
    print_array(array, size_array);
    printf("\n");
    new_array(array, size_array);
    printf("REALLOCATED ARRAY WITH NEW SIZE(%d): \n", new_size_array);
    print_array(array, new_size_array);
    free(array);
    return 0;
}
