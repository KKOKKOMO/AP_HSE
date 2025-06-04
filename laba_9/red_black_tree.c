#include "binary_tree.h"
#include "generate_funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { RED, BLACK } Color;

typedef struct rbnode {
    avto data;
    Color color;
    struct rbnode *left, *right, *parent;
} rbnode;

rbnode* rb_create_node(avto *car_data) {
    rbnode *node = (rbnode*)malloc(sizeof(rbnode));
    node->data = *car_data;
    node->color = RED;
    node->left = node->right = node->parent = NULL;
    return node;
}

rbnode* rb_find(rbnode *root, char *owner_name) {
    if (root == NULL)
        return NULL;

    int res_compare = strcmp(owner_name, root->data.owner_name);

    if (res_compare == 0) 
        return root;
    else if (res_compare < 0)
        return rb_find(root->left, owner_name);
    else
        return rb_find(root->right, owner_name);
}

void rb_left_rotate(rbnode **root, rbnode *x) {
    rbnode *y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rb_right_rotate(rbnode **root, rbnode *y) {
    rbnode *x = y->left;
    y->left = x->right;
    if (x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    x->right = y;
    y->parent = x;
}

void rb_insert_fixup(rbnode **root, rbnode *z) {
    while (z->parent != NULL && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            rbnode *y = z->parent->parent->right;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    rb_left_rotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rb_right_rotate(root, z->parent->parent);
            }
        } else {
            // Симметричный случай
            rbnode *y = z->parent->parent->left;
            if (y != NULL && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rb_right_rotate(root, z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rb_left_rotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

rbnode* rb_insert(rbnode *root, avto *car_data) {
    if (rb_find(root, car_data->owner_name) != NULL) {
        return root;
    }

    rbnode *z = rb_create_node(car_data);
    rbnode *y = NULL;
    rbnode *x = root;

    while (x != NULL) {
        y = x;
        if (strcmp(z->data.owner_name, x->data.owner_name) < 0)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == NULL)
        root = z;
    else if (strcmp(z->data.owner_name, y->data.owner_name) < 0)
        y->left = z;
    else
        y->right = z;

    rb_insert_fixup(&root, z);
    return root;
}

rbnode* rb_fill_tree(rbnode *root, int num_el) {
    for (int i = 0; i < num_el; i++) {
        avto car = generate_random_avto();
        root = rb_insert(root, &car);
    }
    return root;
}

void rb_free(rbnode *root) {
    if (root == NULL)
        return;

    rb_free(root->left);
    rb_free(root->right);
    free(root);
}

void print_avto_rb(avto *car) {
    printf("Owner: %-15s  Brand: %-10s  Year: %d  License: %d  Color: %s\n", 
            car->owner_name,
            car->car_brand, 
            car->year_of_issue, 
            car->state_license_plate, 
            car->color);
}

void pre_ord_tree_print_rb(rbnode *root) {
    if (root != NULL) {
        print_avto_rb(&root->data);
        pre_ord_tree_print_rb(root->left);
        pre_ord_tree_print_rb(root->right);
    }
}

void demo_rb_tree_operations(int num, char* search_name) {
    rbnode *root = NULL;
    root = rb_fill_tree(root, num);
    
    //printf("Red-Black Tree (pre-order traversal):\n");
    //printf("================================\n");
    //pre_ord_tree_print_rb(root);
    
    printf("================================\n");
    printf("Red-Black Tree Searching for element:\n");
    rbnode *found_node = rb_find(root, search_name);
    
    if (found_node != NULL) {
        printf("Found element:\n");
        print_avto_rb(&found_node->data);
    } else {
        printf("Element with name '%s' not found.\n", search_name);
    }
    
    rb_free(root);
}