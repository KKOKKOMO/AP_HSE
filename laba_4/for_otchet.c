#include "arrays_funcs.h"


int main(){
    double positive_value;
    printf("\nINPUT DOUBLE VALUE: ");
    positive_value = get_valid_input_for_double();

    printf("double_value: %lf", positive_value);
    return 0;
}