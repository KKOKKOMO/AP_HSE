#include <stdio.h>
#include <stdlib.h>


int** create_array(int size_array){
    int** array = (int**)malloc(sizeof(int*) * size_array);
    for (int i = 0; i < size_array; ++i) {
        array[i] = (int*)malloc(sizeof(int) * size_array);
    }

    for (int i = 0; i < size_array; i++)
    {
        for (int j = 0; j < size_array; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    return array;
}

void print_array(int** array, int size_array){
    for (int i = 0; i < size_array; i++)
    {
        for (int j = 0; j < size_array; j++)
        {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
}

void print_vertic(int** array, int size_array, int vertic, int end){
    for (int i = 0; i < size_array; i++)
    {
        printf("%d\n", array[i][vertic]);
    }   
}

void print_horizont(int** array, int size_array, int horizont, int start, int end){
    for (int j = 0; j < size_array; j++)
    {
        printf("%d ", array[horizont][j]);
    }   
}

void print_angle(int** array, int size_array, int horizont, int vertic){

}



int main(){
    int** array = create_array(5);
    print_array(array, 5);
    printf("\n\n");
    print_vertic(array, 5, 0, 0);
    printf("\n\n");
    print_horizont(array, 5, 0, 0,0);
    printf("\n");
    return 0;
}