#include "bubble_sort.h"
#include "cocktail_sort.h"
#include "heap_sort.h"
#include "input_funcs.h"
#include "generate_funcs.h"



int main(){
    int choice;
    printf("       Menu\n");
    printf("-------------------\n");
    printf("1. Bubble Sort\n");
    printf("2. Cocktail Sort\n");
    printf("3. Heapsort\n");
    printf("4. Start test for [100,...,300000] el\n");
    printf("5. Generate an array with n el\n");
    printf("0. Exit\n\n");
    printf("Your choice: ");
    choice = get_valid_input_for_positive_int();
    printf("\n");
    switch (choice)
    {
    case 1: {
        print_two_type_sort(bubble_sort, bubble_sort_reverse);
        break;
    }
    case 2: {
        print_two_type_sort(cocktail_sort, cocktail_sort_reverse);
        break;
    }
    case 3: {
        print_two_type_sort(heap_sort, heap_sort_reverse);
        break;
    }
    case 4: {
        int arr_lens[] = {100, 1000, 10000, 50000, 100000, 200000, 300000};
        sort_func_ptr sort_func_arr[] = {bubble_sort, cocktail_sort, heap_sort};
        char* type_of_sort[] = {"Bubble_sort", "Cocktail_sort", "Heap_sort"};
        printf("\n");
        double time_bubble_sort, time_cocktail_sort, time_heap_sort;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                double run_time = 0;
                avto* arr = generate_avto_array(arr_lens[j]);
                run_time = measure_time(sort_func_arr[i], arr, arr_lens[j], avto_compare);
                printf("Sort type: %s | Runtime: %.4f | Arr len: %d\n", type_of_sort[i], run_time, arr_lens[j]);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                free(arr);
            }
            printf("-------------------------------------------------------\n");
        }
        break;
    }
    case 5: {
        printf("Input array len: ");
        int arr_len = get_valid_input_for_positive_int();
        printf("\n");
        sort_func_ptr sort_func_arr[] = {bubble_sort, cocktail_sort, heap_sort};
        char* type_of_sort[] = {"Bubble_sort", "Cocktail_sort", "Heap_sort"};
        for (int i = 0; i < 3; i++)
        {
            double run_time = 0;
            avto* arr = generate_avto_array(arr_len);
            run_time = measure_time(sort_func_arr[i], arr, arr_len, avto_compare);
            printf("Sort type: %s | Runtime: %.4f | Arr len: %d\n", type_of_sort[i], run_time, arr_len);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            free(arr);
        }
        break;
    }
    case 0: {
        printf("Bye Bye\n");
        return 0;
    }
    default:
        printf("Wrong command\n");
    }
    return 0;
}



