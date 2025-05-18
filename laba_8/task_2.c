#include "dnode_funcs.h"
#define MAX_STR_LEN 999

void task_2(){
    char origin_str[MAX_STR_LEN];
    printf("INPUT SENTENCE: ");
    fgets(origin_str, MAX_STR_LEN-1, stdin);
    int dot_idx = get_idx_first_dot(origin_str);
    if (dot_idx == -1)
    {
        printf("SENTENCE WITHOUT DOT");
        return;
    }
    
    char *cutted_str = cut_string(origin_str, dot_idx);
    char *copy_cutted_str = strdup(cutted_str);
    dnode *head_even = create_even_list(cutted_str);
    dnode *head_odd = create_odd_list(copy_cutted_str);
    if ((head_even != NULL) && (head_odd != NULL))
    {
        dnode *result_list = merge_even_odd(head_even, head_odd);
        print_list(result_list);
        printf("\n");
        free_list(result_list);
        return;
    }else if (head_even != NULL && !head_odd)
    {
        print_list(head_even);
        printf("\n");
        free_list(head_even);
        return;
    }else if (!head_even && head_odd != NULL)
    {
        print_list(head_odd);
        printf("\n");
        free_list(head_odd);
        return;
    }
}