#include "node_funcs.h"

void task_1(){
    int n_l1, n_l2;
    node *head_1 = NULL, *head_2 = NULL, *head_L = NULL;
    printf("Input number of terms for L1: ");
    n_l1 = get_valid_input_for_positive_int();
    printf("Input number of terms for L2: ");
    n_l2 = get_valid_input_for_positive_int();


    printf("For L1: \n");
    for (size_t i = 0; i < n_l1; i++)
    {
        head_1 = append(head_1);
        printf("L1=");
        print_poly(head_1);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }
    printf("\nFor L2: \n");

    for (size_t i = 0; i < n_l2; i++)
    {
        head_2 = append(head_2);
        printf("L2=");
        print_poly(head_2);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }

    head_L = merge_lists(head_1, head_2);
    printf("L=");
    print_poly(head_L);
    free_memory(head_1);
    free_memory(head_2);
    free_memory(head_L);
}