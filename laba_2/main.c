#include "arrays_funcs.h"


int main(){
    int size_array;
    float* array = NULL;
    float y, max_el, avg_pos;

    printf("Input array size: ");
    scanf("%d", &size_array);

    array = create_array(size_array);
    print_array(array, size_array);

    printf("Input y: ");
    scanf("%f", &y);

    max_el = max_modul_el(array, size_array, y);
    printf("max modul el: %f\n", max_el);

    avg_pos = avg_between_pos_el(array, size_array);
    printf("Avg between first and last positive el: %f\n", avg_pos);

    free(array);
    return 0;
}