#include "sort_funcs.h"


void heapify(avto arr[], int n, int i, int (*cmp)(const avto*, const avto*)) {
    int largest = i;         // Изначально корень
    int left = 2 * i + 1;      // левый потомок
    int right = 2 * i + 2;     // правый потомок

    // Если левый потомок больше корня
    if (left < n && cmp(&arr[left], &arr[largest]) > 0)
        largest = left;

    // Если правый потомок больше текущего наибольшего
    if (right < n && cmp(&arr[right], &arr[largest]) > 0)
        largest = right;

    // Если наибольший не корень, меняем их местами и рекурсивно вызываем heapify
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest, cmp);
    }
}

void heap_sort(avto arr[], int n, int (*cmp)(const avto*, const avto*)) {
    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, cmp);
    }
    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        swap(&arr[0], &arr[i]);
        // Вызываем heapify для уменьшенной кучи
        heapify(arr, i, 0, cmp);
    }
}

void heapify_reverse(avto arr[], int n, int i, int (*cmp)(const avto*, const avto*)) {
    int smallest = i;        // Изначально считаем, что элемент в i-ой позиции — наименьший
    int left = 2 * i + 1;      // индекс левого потомка
    int right = 2 * i + 2;     // индекс правого потомка

    // Если левый потомок меньше текущего наименьшего, обновляем smallest
    if (left < n && cmp(&arr[left], &arr[smallest]) < 0)
        smallest = left;

    // Если правый потомок меньше текущего наименьшего, обновляем smallest
    if (right < n && cmp(&arr[right], &arr[smallest]) < 0)
        smallest = right;

    // Если наименьший элемент не является корнем, меняем их местами и рекурсивно вызываем heapify_reverse
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify_reverse(arr, n, smallest, cmp);
    }
}

void heap_sort_reverse(avto arr[], int n, int (*cmp)(const avto*, const avto*)) {
    // 1. Построение min-кучи: проходим по всем узлам, у которых есть потомки
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_reverse(arr, n, i, cmp);
    }
    
    // 2. Извлечение элементов из кучи один за другим
    for (int i = n - 1; i > 0; i--) {
        // Меняем корень (наименьший элемент) с последним элементом текущей кучи
        swap(&arr[0], &arr[i]);
        // Восстанавливаем min-кучу для уменьшенной части массива
        heapify_reverse(arr, i, 0, cmp);
    }
}