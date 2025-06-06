#include "hash_table_funcs.h"
#include "input_funcs.h"
#include <time.h>


double measure_time(HashTable* table, char* owner_name, hash_func hash_f);

int main(){

    //srand((unsigned)time(NULL));

    int choice;
    printf("       Menu\n");
    printf("-------------------\n");
    printf("1. Bubble Sort\n");
    printf("2. Cocktail Sort\n");
    printf("3. Heapsort\n");
    printf("4. Start test for [1000,...,1000000] el\n");
    printf("0. Exit\n\n");
    printf("Your choice: ");
    choice = get_valid_input_for_positive_int();
    printf("\n");
    switch (choice)
    {
    case 1: {

        break;
    }
    case 2: {

        break;
    }
    case 3: {

        break;
    }
    case 4: {
        int arr_lens[] = {1000, 10000, 50000, 100000, 200000, 500000, 1000000};
        hash_func hash_func_arr[] = {djb2_hash, fnv1a_hash, ascii_sum_hash};
        char* hash_type[] = {"djb2_hash", "fnv1a_hash", "ascii_sum_hash"};
        double time_djb2_hash, time_fnv1a_hash, time_ascii_sum_hash;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                HashTable* table = create_and_fill_table(arr_lens[j]*2, arr_lens[j], hash_func_arr[i]);
                print_table(table);
                
                double run_time = measure_time(table, "tvshb", hash_func_arr[i]);
                printf("HASH FUNC TYPE: %s | Runtime: %.4f | NUM ITEMS: %d\n", hash_type[i], run_time, arr_lens[j]);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                free_table(table);
            }
            printf("-------------------------------------------------------\n");
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


double measure_time(HashTable* table, char* owner_name, hash_func hash_f){
    clock_t start, end;
    start = clock();
    search(table, owner_name, hash_f);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}