#include <stdio.h>
#define N 4


void print_pattern(int array[][N]){
    for (int j = N - 1; j >= 0; j--) {
        for (int i = 0; i < N; i++) {
            printf("%d ", array[i][j]); 
            if (i + j == N - 1) {
                for (int k = j + 1; k < N; k++) {
                    printf("%d ", array[i][k]);
                }
                break; 
            }
        }
    }
}

void print_element(int array[][N], int i, int j) {
    // Способ 1: Стандартный доступ
    printf("Standard access: %d\n", array[i][j]);

    // Способ 2: Указатель на массив строк
    printf("Pointer to array of rows: %d\n", *(*(array + i) + j));

    // Способ 3: Прямое преобразование к int*
    printf("Direct cast to int*: %d\n", *((int*)array + i * N + j));
}

int main() {
    int arr[][N] = {
        {1, 2, 3, 99},
        {4, 5, 6, 98},
        {7, 8, 9, 97},
        {71, 18, 19, 95}
    };
    
    for (int j = N - 1; j >= 0; j--) {
        for (int i = 0; i < N; i++) {
            printf("%d ", arr[i][j]); 
            if (i + j == N - 1) {
                for (int k = j + 1; k < N; k++) {
                    printf("%d ", arr[i][k]);
                }
                break; 
            }
        }
    }
    printf("\n");
    print_pattern(arr);
    printf("\n");
    print_element(arr, 2, 2);
    
    return 0;
}