#include <stdio.h>
#include <stdlib.h>
#include "list_struct.h"
#include "input_funcs.h"


node* create_node(int koef, int degr){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->degr = degr;
    new_node->koef = koef;
    new_node->next = NULL;
    return new_node;
}

int degree_exist(node* head, int degr){
    while (head)
    {
        if (head->degr == degr)
            return 1;
        head = head->next;
    }
    return 0;
}

node* append(node* head){
    int koeff, degr;
    node *cur = head;

    do
    {
        printf("Input koeff: ");
        koeff = get_valid_input_for_int();
        printf("Input degr: ");
        degr = get_valid_input_for_int();

        if (degree_exist(cur, degr))
            printf("Degree %d already exists please enter another degree.\n", degr);
        
    } while (degree_exist(cur, degr));
    
    node *new_node = create_node(koeff, degr);
    new_node->next = head;
    return new_node;
}

void print_poly(node *head) {
    node *cur = head;
    int first = 1;

    while (cur) {
        int k = cur->koef;
        int d = cur->degr;

        if (k != 0) {
            if (first) {
                if (k < 0) putchar('-');
            } else {
                putchar(k < 0 ? '-' : '+');
            }
            int ak = abs(k);
            if (d == 0) {
                printf("%d", ak);
            } else {
                if (ak != 1) 
                    printf("%d", ak);

                putchar('x');

                if (d != 1) 
                    printf("^%d", d);
            }
            first = 0;
        }
        cur = cur->next;
    }
    if (first) {
        printf("0");
    }
    putchar('\n');
}

node* merge_lists(node* head_1, node* head_2){
    node dummy;
    node* tail = &dummy;
    dummy.next = NULL;

    node *p1 = head_1;

    while (p1) {
        if (!degree_exist(head_2, p1->degr)) {
            tail->next = create_node(p1->koef, p1->degr);
            tail = tail->next;
        }
        p1 = p1->next;
    }

    node *p2 = head_2;
    while (p2) {
        if (!degree_exist(head_1, p2->degr)) {
            tail->next = create_node(p2->koef, p2->degr);
            tail = tail->next;
        }
        p2 = p2->next;
    }
    
    return dummy.next;
}

void free_memory(node *head){
    node *cur = head;
    while (cur)
    {
        node *next = cur->next;
        free(cur);
        cur = next;
    }
}


