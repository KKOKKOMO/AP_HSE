#include <stdio.h>
#include <stdlib.h>
#include "list_struct.h"


node* create_node(int koef, int degr){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->degr = degr;
    new_node->koef = koef;
    new_node->next = NULL;

    return new_node;
}

node* append(node* head){
    node *cur = head;
    int koeff, degr;
    printf("Input new el: ");
    scanf("%d", &koeff);
    scanf("%d", &degr);

    node *new_node = create_node(koeff, degr);

    while (cur->next)
        cur = cur->next;
    
    cur->next = new_node;
    return head;
}

void print_poly(node *head) {
    node *cur = head;
    int first = 1;  // have we printed any term yet?

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

int contains_deg(node* head, int degr){
    while (head)
    {
        if (head->degr == degr)
            return 1;
        
        head = head->next;
    }
    return 0;
}

node* merge_list(node* head_1, node* head_2){
    node dummy;
    node* tail = &dummy;
    dummy.next = NULL;

    node *p1 = head_1;

    while (p1) {
        if (!contains_deg(head_2, p1->degr)) {
            tail->next = create_node(p1->koef, p1->degr);
            tail = tail->next;
        }
        p1 = p1->next;
    }

    node *p2 = head_2;
    while (p2) {
        if (!contains_deg(head_1, p2->degr)) {
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


int main(){
    node *head_1 = create_node(2, 2);
    head_1 = append(head_1);
    head_1 = append(head_1);
    print_poly(head_1);

    

    node *head_2 = create_node(-5, 2);
    head_2 = append(head_2);
    head_2 = append(head_2);
    head_2 = append(head_2);
    print_poly(head_2);
    
    printf("\n");

    print_poly(merge_list(head_1, head_2));

    free_memory(head_1);
    free_memory(head_2);
    return 0;
}