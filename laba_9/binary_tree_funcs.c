#include "binary_tree.h"
#include "generate_funcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



bnode* bt_insert(bnode *root, avto *car_data){
    if (root == NULL){
        bnode *node = (bnode*)malloc(sizeof(bnode));
        node->data = *car_data;
        node->left = NULL;
        node->right = NULL;

        return node;
    }

    int res_compare = strcmp(car_data->owner_name, root->data.owner_name);

    if (res_compare < 0){
        root->left = bt_insert(root->left, car_data);
    } else if (res_compare > 0){
        root->right = bt_insert(root->right, car_data);
    }

    return root;
}

bnode* fill_tree(bnode *root, int num_el){
    for (int i = 0; i < num_el; i++)
    {
        avto car = generate_random_avto();
        root = bt_insert(root, &car);
    }
    return root;
}

bnode* bt_find(bnode *root, char *owner_name){
    if (root == NULL)
        return NULL;

    int res_compare = strcmp(owner_name, root->data.owner_name);

    if (res_compare == 0) 
        return root;
    else if (res_compare < 0)
        return bt_find(root->left, owner_name);
    else
        return bt_find(root->right, owner_name);    
}

void bnode_free(bnode *root){
    if (root == NULL)
        return;

    bnode_free(root->left);
    bnode_free(root->right);
    free(root);
}

void print_avto_t(avto *some_avto){
    printf("Owner: %-15s  Brand: %-10s  Year: %d  License: %d  Color: %s\n", 
            some_avto->owner_name, some_avto->car_brand, some_avto->year_of_issue, 
            some_avto->state_license_plate, some_avto->color);
}

void pre_ord_tree_print(bnode *root){
    if (root)
    {
        print_avto_t(&(root->data));
        pre_ord_tree_print(root->left);
        pre_ord_tree_print(root->right);
    } 
}
