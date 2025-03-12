#include "sort_funcs.h"

void bubble_sort(avto arr[], int n, int (*cmp)(const avto*, const avto*)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (avto_compare(&arr[j], &arr[j+1]) > 0) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void bubble_sort_reverse(avto arr[], int n, int (*cmp)(const avto*, const avto*)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (avto_compare(&arr[j], &arr[j+1]) < 0) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}