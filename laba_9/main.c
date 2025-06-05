#include "input_funcs.h"
#include "arrays_funcs.h"
#include "binary_tree_funcs.h"
#include "red_black_tree.h"
#include <time.h>

typedef void (*search_func)(int num, char* search_name);
double measure_time(search_func search_f, int n, char* search_name);

int main(){
    
    //printf("Input name for search: ");
    //char search_name[100];
    //fgets(search_name, 99, stdin);
    //НАДО
    //search_name[strcspn(search_name, "\n")] = '\0';
    //srand(56);
    //demo_rb_tree_operations(30, "Viktoria Fedorova");
    //printf("\n");
    //srand(56);
    //b_tree_operations(30, "Viktoria Fedorova");
    //printf("\n");
    //srand(56);
    //linear_search(30, "Viktoria Fedorova");
    //---------------------------
    int num_el;
    printf("Input num of el: ");
    num_el = get_valid_input_for_positive_int();
    printf("\n");
    int choice;
    printf("       Menu\n");
    printf("-------------------\n");
    printf("1. Linear Search\n");
    printf("2. Bin Tree\n");
    printf("3. Red-Black Tree\n");
    printf("4. Start test for [100,...,300000] el\n");
    printf("0. Exit\n\n");
    printf("Your choice: ");
    choice = get_valid_input_for_positive_int();
    printf("\n");
    switch (choice)
    {
    case 1: {
        srand(56);
        linear_search(num_el, "Viktoria Fedorova");
        break;
    }
    case 2: {
        srand(56);
        b_tree_operations(num_el, "Viktoria Fedorova");
        break;
    }
    case 3: {
        srand(56);
        demo_rb_tree_operations(num_el, "Viktoria Fedorova");
        break;
    }
    case 4: {
        
        int arr_lens[] = {100, 1000, 10000, 50000, 100000, 200000, 300000};
        search_func search_fs[] = {linear_search, b_tree_operations, demo_rb_tree_operations};
        char* type_of_sort[] = {"linear_search", "b_tree_operations", "RED BLACK TREE"};
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 7; j++)
            {
                srand(56);
                double run_time = 0;
                run_time = measure_time(search_fs[i], arr_lens[j], "Viktoria Fedorova");
                printf("Search type: %s | Runtime: %.4f | Arr len: %d\n", type_of_sort[i], run_time, arr_lens[j]);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
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

double measure_time(search_func search_f, int n, char* search_name){
    clock_t start, end;
    start = clock();
    search_f(n, search_name);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}



//BIN_TREE
//bnode *root = NULL;
//root = fill_tree(root, 40);
//pre_ord_tree_print(root);
//printf("===============================\n");
//bnode *found_root = bt_find(root, "Viktoria Fedorova");
//print_avto(&found_root->data);
//bnode_free(root);
//ARRAY
//avto *found_avto = NULL;
//int size_array = get_valid_input_for_positive_int();
//avto *avto_array = generate_avto_array(size_array);
//print_records(avto_array, size_array);
//avto new = generate_random_avto();
//avto *avto_array_n = NULL;
//avto_array_n = append_to_array(avto_array, &size_array, &new);
//found_avto = find_avto_in_array(avto_array_n, size_array);
//print_records(avto_array_n, size_array);
//print_avto(found_avto);
