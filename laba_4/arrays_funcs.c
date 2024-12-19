#include "input_funcs.h"


double* create_array(int size_array){
    double* array = (double*)malloc(size_array*sizeof(double));
    printf("Input elements for array(P.S. %d elements): \n", size_array);
    for (int i = 0; i < size_array; i++)
    {
        printf("Input element %d: ", i);
        array[i] = get_valid_input_for_double();
    }
    return array;
}

void print_array(double* array, int size_array){
    for (int i = 0; i < size_array; i++)
    printf("%f\t", array[i]);
    printf("\n");   
}

int remove_values(double* array, int size_array, double posi_value) {
    int j = 0; // новое положение в массиве

    for (int i = 0; i < size_array; i++) {
        if ((array[i]>=0 ? array[i] : array[i]*(-1) ) > posi_value ) { // если не нужно удалять элемент
            array[j++] = array[i]; // помещаем элемент в новое место
        }
    }

    size_array = j; // обновляем размер массива
    return size_array;
}

void new_array(double* array, int new_size){
    if (new_size != 0)
    {
        array = (double*)realloc(array, new_size*sizeof(double));
    }
}


