#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_struct_2.h"

#define MAX_INPUT 10000


node* create_node(const char *w) {
    node *n = malloc(sizeof(node));
    if (!n) {
        perror("malloc");
        exit(1);
    }
    n->word = strdup(w);
    if (!n->word) {
        perror("strdup");
        exit(1);
    }
    n->prev = n->next = NULL;
    return n;
}

node* append_end(node *head, node *n) {
    if (!head) return n;
    node *t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
    return head;
}

void print_list(node *head) {
    for (node *p = head; p; p = p->next) {
        printf("%s", p->word);
        if (p->next) putchar(' ');
    }
    putchar('\n');
}

void free_list(node *head) {
    while (head) {
        node *nx = head->next;
        free(head->word);
        free(head);
        head = nx;
    }
}

node* build_list(const char *input) {
    char *buf = strdup(input);
    if (!buf) {
        perror("strdup");
        exit(1);
    }
    node *head = NULL;
    for (char *tok = strtok(buf, " \t\n"); tok; tok = strtok(NULL, " \t\n")) {
        head = append_end(head, create_node(tok));
    }
    free(buf);
    return head;
}

int is_even_len(const char *w) {
    return (int)strlen(w) % 2 == 0;
}

node* move_even_to_front(node *head) {
    node *even_h = NULL, *even_t = NULL;
    node *odd_h  = NULL, *odd_t  = NULL;
    node *p = head;

    while (p) {
        node *nx = p->next;
        p->prev = p->next = NULL;

        if (is_even_len(p->word)) {
            if (!even_h) even_h = even_t = p;
            else {
                even_t->next = p;
                p->prev = even_t;
                even_t = p;
            }
        } else {
            if (!odd_h) odd_h = odd_t = p;
            else {
                odd_t->next = p;
                p->prev = odd_t;
                odd_t = p;
            }
        }
        p = nx;
    }

    if (even_t) {
        even_t->next = odd_h;
        if (odd_h) odd_h->prev = even_t;
        return even_h;
    } else {
        return odd_h;
    }
}

int main(void) {
    static char input[MAX_INPUT];
    int len = 0;
    int c;
    while (len < MAX_INPUT-1 && (c = getchar()) != EOF && c != '.') {
        input[len++] = (char)c;
    }
    input[len] = '\0';

    node *head = build_list(input);

    printf("Before:\n");
    print_list(head);

    head = move_even_to_front(head);

    printf("After:\n");
    print_list(head);

    free_list(head);
    return 0;
}
