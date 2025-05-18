//Пузырьком Bubble Sort, Шейкер Cocktail Sort, Пирамидальная Heapsort
#include "avto_struct.h"
#include <stdio.h>
#include <string.h>
#include <time.h>


void swap(avto *a, avto *b) {
    avto temp = *a;
    *a = *b;
    *b = temp;
}

int avto_compare(const avto *fisrt, const avto *second){
    int cmp = strcmp(fisrt->owner_name, second->owner_name);
    if (cmp != 0)
        return cmp;
    
    cmp = strcmp(fisrt->car_brand, second->car_brand);
    if (cmp != 0)
        return cmp;
    
    if (fisrt->year_of_issue != second->year_of_issue)
        return fisrt->year_of_issue - second->year_of_issue;
    
    if (fisrt->state_license_plate != second->state_license_plate)
        return fisrt->state_license_plate - second->state_license_plate;
    
    return strcmp(fisrt->color, second->color);
}

void printRecords(avto arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Id: %d  Owner: %-15s  Brand: %-10s  Year: %d  License: %d  Color: %s\n", 
            i, arr[i].owner_name, arr[i].car_brand, arr[i].year_of_issue, 
            arr[i].state_license_plate, arr[i].color);
    }
}

void print_two_type_sort(sort_func_ptr sort_func, sort_func_ptr sort_func_reverse){

    avto sample[] = {
        {"Ivan Ivanov", "Toyota", 2015, 12345, "Red"},
        {"Petr Petrov", "BMW", 2018, 67890, "Blue"},
        {"Anna Sidorova", "Mercedes", 2020, 11223, "Black"},
        {"Sergey Ivanov", "Toyota", 2017, 44567, "Green"},
        {"Petr Petrov", "Audi", 2019, 78901, "Red"},
        {"Olga Sidorova", "BMW", 2021, 33456, "Black"},
        {"Petr Petrov", "Audi", 2019, 78901, "Red"},
        {"Petr Petrov", "Audi", 2019, 78902, "Red"},
        {"Petr Petrov", "Audi", 2019, 78901, "White"}
    };
    int n = sizeof(sample) / sizeof(sample[0]); //n=9
    avto copy1[9];
    avto copy2[9];
    memcpy(copy1, sample, sizeof(sample));
    memcpy(copy2, sample, sizeof(sample));

    sort_func(copy1, n, avto_compare);
    printf("From low to high:\n");
    printRecords(copy1, n);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    sort_func_reverse(copy2, n, avto_compare);
    printf("From high to low:\n");
    printRecords(copy2, n);
    printf("\n\n");
}

double measure_time(sort_func_ptr some_sort, avto arr[], int n, int (*cmp)(const avto*, const avto*)){
    clock_t start, end;
    start = clock();
    some_sort(arr, n, cmp);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}
