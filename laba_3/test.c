#include "arrays_funcs.h"


int** test_create_array(int size_array){
    int number = 0;
    int** array = (int**)malloc(sizeof(int*) * size_array);
    for (int i = 0; i < size_array; ++i) {
        array[i] = (int*)malloc(sizeof(int) * size_array);
    }

    for (int i = 0; i < size_array; i++)
    {
        for (int j = 0; j < size_array; j++)
        {
            //printf("Input el of array[%d][%d]: ", i, j);
            array[i][j] = number;
            number++;
        }
    }
    printf("\n");
    return array;
}

void test_print_pattern(){
    for (int i = 2; i < 10; i++)
    {
        printf("MATRIX %dx%d\n", i, i);
        int array_size = i;
        int **array = test_create_array(array_size);
        print_array(array, array_size);
        print_pattern(array, array_size);
        free_two_dimension_array(array, array_size);
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
}

int main(){
    test_print_pattern();
    return 0;
}