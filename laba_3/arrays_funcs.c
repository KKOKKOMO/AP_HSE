#include "input_funcs.h"


int** create_array(int size_array){
    int** array = (int**)malloc(sizeof(int*) * size_array);
    for (int i = 0; i < size_array; ++i) {
        array[i] = (int*)malloc(sizeof(int) * size_array);
    }

    for (int i = 0; i < size_array; i++)
    {
        for (int j = 0; j < size_array; j++)
        {
            printf("Input el of array[%d][%d]: ", i, j);
            array[i][j] = int_input();
        }
    }
    printf("\n");
    return array;
}

void print_array(int** array, int size_array){
    for (int i = 0; i < size_array; i++)
    {
        for (int j = 0; j < size_array; j++)
        printf("%d\t", array[i][j]);
        printf("\n");
    }
    printf("\n");
}

void print_pattern(int** array, int array_size){
    for (int j = array_size - 1; j >= 0; j--) {
        for (int i = 0; i < array_size; i++) {
            printf("%d ", array[i][j]); 
            if (i + j == array_size - 1) {
                for (int k = j + 1; k < array_size; k++) {
                    printf("%d ", array[i][k]);
                }
                break; 
            }
        }
    }
    printf("\n");
}

void free_two_demetnion_array(int** array, int array_size){
    for(int i = 0; i < array_size; i++)
    free(array[i]);
    free(array);
}
