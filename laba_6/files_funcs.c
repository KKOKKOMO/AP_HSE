#include <io.h> //chsize trunc
#include "avto_struct.h"
#include "input_funcs.h"


struct avto input_avto(){
    struct avto avto;

    printf("Input owner's name: ");
    fgets(avto.owner_name, sizeof(avto.owner_name), stdin);
    avto.owner_name[strcspn(avto.owner_name, "\n")] = '\0';

    printf("Input car brand: ");
    fgets(avto.car_brand, sizeof(avto.car_brand), stdin);
    avto.car_brand[strcspn(avto.car_brand, "\n")] = '\0';

    printf("Input year of issue: ");
    avto.year_of_issue = get_valid_input_for_positive_int();

    printf("Input state license plate: ");
    avto.state_license_plate = get_valid_input_for_positive_int();

    printf("Input car color: ");
    fgets(avto.color, sizeof(avto.color), stdin);
    avto.color[strcspn(avto.color, "\n")] = '\0';

    return avto;
}

void add_record(FILE *file){
    struct avto record = input_avto();
    int check = 0;
    check = fwrite(&record, sizeof(struct avto), 1, file);
    if (check != 1)
    {
        printf("ERROR");
        exit(1);
    }
}

void add_records_from_array(FILE *file){
    struct avto record;
    struct avto records[] = {
        {"Ivan Ivanov", "Toyota", 2015, 12345, "Red"},
        {"Petr Petrov", "BMW", 2018, 67890, "Blue"},
        {"Anna Sidorova", "Mercedes", 2020, 11223, "Black"},
        {"Sergey Ivanov", "Toyota", 2017, 44567, "Green"},
        {"Petr Petrov", "Audi", 2019, 78901, "Red"},
        {"Olga Sidorova", "BMW", 2021, 33456, "Black"}
    };

    for (int i = 0; i < 5; i++)
    {
        record = records[i];
        fwrite(&record, sizeof(struct avto), 1, file);
    }
}

void display_records(FILE *file){
    struct avto record;
    rewind(file);

    printf("List of cars:\n");
    printf("-----------------------------------------------------------\n");
    printf("| ID | Owner           | Brand      | Year | Plate | Color |\n");
    printf("-----------------------------------------------------------\n");

    int i = 0;
    while (fread(&record, sizeof(struct avto), 1, file))
    {
        printf("| %-1d | %-15s | %-10s | %-4d | %-5d | %-5s |\n",
               i, record.owner_name, record.car_brand,
               record.year_of_issue, record.state_license_plate, record.color);
        i++;
    }

    printf("-----------------------------------------------------------\n");
}

void change_record(FILE *file, int index){
    int file_size;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    if (index * sizeof(struct avto) >= file_size)
    {
        printf("Invalid index\n\n");
        return;
    }
    struct avto new_record = input_avto();
    fseek(file, index * sizeof(struct avto), SEEK_SET);
    fwrite(&new_record, sizeof(struct avto), 1, file);
}

void delete_record(FILE *file, int index){
    int file_descriptor = fileno(file);
    int file_size;
    struct avto record;
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    if (index * sizeof(struct avto) >= file_size)
    {
        printf("Invalid index\n\n");
        return;
    }
    fseek(file, 0, SEEK_SET);

    for (int i = index+1; i*sizeof(struct avto) < file_size; i++)
    {
        fseek(file, i * sizeof(struct avto), SEEK_SET);
        fread(&record, sizeof(struct avto), 1, file);
        fseek(file, (i-1) * sizeof(struct avto), SEEK_SET);
        fwrite(&record, sizeof(struct avto), 1, file);
    }
    chsize(file_descriptor, file_size - sizeof(struct avto));
}

void search_by_owner_name(FILE *file){
    char value[100];
    struct avto record;
    rewind(file);

    printf("Input owner's name: ");
    fgets(value, 100, stdin);
    value[strcspn(value, "\n")] = '\0';

    printf("-------------------------------------------------------\n");
    printf("| Owner           | Brand      | Year | Plate | Color |\n");
    printf("-------------------------------------------------------\n");

    while (fread(&record, sizeof(struct avto), 1, file))
    {
        if (strcmp(record.owner_name, value) == 0)
        {
            printf("| %-15s | %-10s | %-4d | %-5d | %-5s |\n",
               record.owner_name, record.car_brand,
               record.year_of_issue, record.state_license_plate, record.color);
        }
    }
}

void search_by_car_brand(FILE *file){
    char value[100];
    struct avto record;
    rewind(file);

    printf("Input owner's name: ");
    fgets(value, 100, stdin);
    value[strcspn(value, "\n")] = '\0';

    printf("-------------------------------------------------------\n");
    printf("| Owner           | Brand      | Year | Plate | Color |\n");
    printf("-------------------------------------------------------\n");

    while (fread(&record, sizeof(struct avto), 1, file))
    {
        if (strcmp(record.car_brand, value) == 0)
        {
            printf("| %-15s | %-10s | %-4d | %-5d | %-5s |\n",
               record.owner_name, record.car_brand,
               record.year_of_issue, record.state_license_plate, record.color);
        }
    }
}

void search_by_color(FILE *file){
    char value[100];
    struct avto record;
    rewind(file);

    printf("Input owner's name: ");
    fgets(value, 100, stdin);
    value[strcspn(value, "\n")] = '\0';

    printf("-------------------------------------------------------\n");
    printf("| Owner           | Brand      | Year | Plate | Color |\n");
    printf("-------------------------------------------------------\n");

    while (fread(&record, sizeof(struct avto), 1, file))
    {
        if (strcmp(record.color, value) == 0)
        {
            printf("| %-15s | %-10s | %-4d | %-5d | %-5s |\n",
               record.owner_name, record.car_brand,
               record.year_of_issue, record.state_license_plate, record.color);
        }
    }
}

void search_by_year_of_issue(FILE *file){
    int value;
    struct avto record;
    rewind(file);

    printf("Input value: ");
    value = get_valid_input_for_positive_int();
    printf("\n");

    printf("-------------------------------------------------------\n");
    printf("| Owner           | Brand      | Year | Plate | Color |\n");
    printf("-------------------------------------------------------\n");

    while (fread(&record, sizeof(struct avto), 1, file))
    {
        if (record.year_of_issue == value)
        {
            printf("| %-15s | %-10s | %-4d | %-5d | %-5s |\n",
               record.owner_name, record.car_brand,
               record.year_of_issue, record.state_license_plate, record.color);
        }
    }
}

void search_by_state_license_plate(FILE *file){
    int value;
    struct avto record;
    rewind(file);

    printf("Input value: ");
    value = get_valid_input_for_positive_int();
    printf("\n");

    printf("-------------------------------------------------------\n");
    printf("| Owner           | Brand      | Year | Plate | Color |\n");
    printf("-------------------------------------------------------\n");

    while (fread(&record, sizeof(struct avto), 1, file))
    {
        if (record.state_license_plate == value)
        {
            printf("| %-15s | %-10s | %-4d | %-5d | %-5s |\n",
               record.owner_name, record.car_brand,
               record.year_of_issue, record.state_license_plate, record.color);
        }
    }
}


void get_records(FILE *file){
    struct avto record;
    int choice;
    rewind(file);
    
    while (1)
    {
        printf("Choose a field to search by:\n");
        printf("1. Owner Name\n");
        printf("2. Car Brand\n");
        printf("3. Year of Issue\n");
        printf("4. State License Plate\n");
        printf("5. Color\n");
        printf("0. Back to Menu\n");
        printf("Enter your choice (1-5): ");
        choice = get_valid_input_for_positive_int();
        printf("\n");

        switch (choice)
        {
        case 1: {
            search_by_owner_name(file);
            break;
        }
        case 2: {
            search_by_car_brand(file);
            break;
        }
        case 3: {
            search_by_year_of_issue(file);
            break;
        }
        case 4: {
            search_by_state_license_plate(file);
            break;
        }
        case 5: {
            search_by_color(file);
            break;
        }
        case 0: {
            return;
        }
        default:
            printf("Wrong command\n");
        }
    }
}