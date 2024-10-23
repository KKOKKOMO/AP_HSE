#include "arrays_funcs.h"


int main(){
    int size_array;
    float* array = NULL;
    float y, max_el, avg_pos;

    printf("Input array size: ");
    size_array = get_valid_input_for_positive_int();

    array = create_array(size_array);
    print_array(array, size_array);

    if (size_array == 0)
    {
        printf("max modul el: None\n");
        printf("Avg between first and last positive el: None\n");
        free(array);
        return 0;
    }

    printf("Input y: ");
    y = get_valid_input_for_positive_float();
    //scanf("%f", &y);

    max_el = max_modul_el(array, size_array, y);
    if (max_el == FLT_MIN)
    {
        printf("max modul el: None\n");
    }
    else
    {
        printf("max modul el: %f\n", max_el);
    }

    //printf("FLT_MIN: %f\n", FLT_MIN);
    //if (FLT_MIN > 0)
    //{
    //    printf("FLT_MIN: %f\n", FLT_MIN);
    //}
    avg_pos = avg_between_pos_el(array, size_array);
    if (avg_pos == 0)
    {
        printf("Avg between first and last positive el: None\n");
        free(array);
        return 0;
    }

    printf("Avg between first and last positive el: %f\n", avg_pos);
    printf("ADDRESS FISRT EL %p\n", array);
    free(array);
    return 0;
}