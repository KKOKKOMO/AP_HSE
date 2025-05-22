#ifndef AVTO_STRUCT
#define AVTO_STRUCT


typedef struct binary_tree bnode;

struct binary_tree
{
    avto data;
    bnode *left;
    bnode *right;
};

typedef struct avto
{
    char owner_name[100];
    char car_brand[20];
    int year_of_issue;
    int state_license_plate;
    char color[20];
} avto;

#endif