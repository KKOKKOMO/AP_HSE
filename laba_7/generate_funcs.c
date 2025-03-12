#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "avto_struct.h"

const char* names[] = {
    "Ivan Ivanov",
    "Petr Petrov",
    "Anna Sidorova",
    "Sergey Ivanov",
    "Olga Sidorova",
    "Dmitry Sidorov",
    "Elena Kuznetsova",
    "Nikolay Smirnov",
    "Maria Ivanova",
    "Andrey Sidorov",
    "Svetlana Petrova",
    "Yulia Volkova",
    "Maxim Egorov",
    "Viktoria Fedorova",
    "Roman Pavlov",
    "Irina Sokolova"
};

const char* brands[] = {
    "Toyota",
    "BMW",
    "Mercedes",
    "Audi",
    "Honda",
    "Lamborghini",
    "Moskvich",
    "Lada",
    "Ford",
    "Chevrolet",
    "Volkswagen",
    "Volvo"
};

const char* colors[] = {
    "Red",
    "Blue",
    "Black",
    "Green",
    "White",
    "Yellow",
    "Gray",
    "Orange",
    "Purple",
    "Brown"
};

int names_count = sizeof(names) / sizeof(names[0]);
int brands_count = sizeof(brands) / sizeof(brands[0]);
int colors_count = sizeof(colors) / sizeof(colors[0]);


avto generate_random_avto() {
    avto car;
    strcpy(car.owner_name, names[rand() % names_count]);
    strcpy(car.car_brand, brands[rand() % brands_count]);
    car.year_of_issue = 1990 + rand() % 36;
    car.state_license_plate = 10000 + rand() % 90000;
    strcpy(car.color, colors[rand() % colors_count]);
    return car;
}

avto* generate_avto_array(int n) {
    avto* arr = (avto*)malloc(n * sizeof(avto));
    for (int i = 0; i < n; i++)
        arr[i] = generate_random_avto();
    return arr;
}