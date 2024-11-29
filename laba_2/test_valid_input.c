#include <stdio.h>
#include "input_funcs.h"


int main(){
    printf("INPUT FLOAT VALUE: ");
    float y = get_valid_input_for_float();
    printf("RESULT FUNC: %f", y);
    return 0;
}