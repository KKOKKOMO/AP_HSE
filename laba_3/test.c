#include <stdio.h>
#define N 4


void print_pattern(int array[N][N], int array_size){
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
}

int main() {
    int arr[N][N] = {
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
    print_pattern(arr, N);
    printf("\n");
    
    return 0;
}