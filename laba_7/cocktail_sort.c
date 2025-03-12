#include "sort_funcs.h"


void cocktail_sort(avto arr[], int n, int (*cmp)(const avto*, const avto*)) {
    int start = 0, end = n - 1;
    int swapped = 1;
    
    while(swapped) {
        swapped = 0;
        // Проход слева направо
        for (int i = start; i < end; i++) {
            if (cmp(&arr[i], &arr[i+1]) > 0) {
                swap(&arr[i], &arr[i+1]);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
        
        swapped = 0;
        end--;
        // Проход справа налево
        for (int i = end - 1; i >= start; i--) {
            if (cmp(&arr[i], &arr[i+1]) > 0) {
                swap(&arr[i], &arr[i+1]);
                swapped = 1;
            }
        }
        start++;
    }
}

void cocktail_sort_reverse(avto arr[], int n, int (*cmp)(const avto*, const avto*)) {
    int start = 0, end = n - 1;
    int swapped = 1;
    
    while (swapped) {
        swapped = 0;
        // Проход слева направо
        for (int i = start; i < end; i++) {
            if (cmp(&arr[i], &arr[i+1]) < 0) {  // если текущий элемент меньше следующего, меняем местами
                swap(&arr[i], &arr[i+1]);
                swapped = 1;
            }
        }
        if (!swapped)
            break;
        
        swapped = 0;
        end--;
        // Проход справа налево
        for (int i = end - 1; i >= start; i--) {
            if (cmp(&arr[i], &arr[i+1]) < 0) {  // аналогично, меняем местами, если элемент меньше следующего
                swap(&arr[i], &arr[i+1]);
                swapped = 1;
            }
        }
        start++;
    }
}