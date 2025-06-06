#include "HashTable.h"
#include "hash_func.h"
#include "generate_funcs.h"


HashTable* create_table(int table_size){
    HashTable* table = (HashTable*)malloc(sizeof(HashTable) * table_size);
    table->table_size = table_size;
    table->count_items = 0;
    table->items = (HashNode**)calloc(table->table_size, sizeof(HashNode*));
    return table;
}

void free_table(HashTable* table){
    for (int i = 0; i < table->table_size; i++)
    {
        HashNode* node = table->items[i];
        while (node != NULL)
        {
            HashNode* temp = node;
            node = temp->next;
            free(temp);
        }
    }
    free(table->items);
    free(table);
}

void insert(HashTable* table, avto car, hash_func hash_f){
    uint32_t hash = hash_f(car.owner_name, table->table_size);

    HashNode* new_node = (HashNode*)malloc(sizeof(HashNode));
    new_node->car = car;
    new_node->next = NULL;

    if (table->items[hash] == NULL)
        table->items[hash] = new_node;
    else{
        new_node->next = table->items[hash];
        table->items[hash] = new_node;
    }
    table->count_items++;
}

HashNode* search(HashTable* table, char* owner_name, hash_func hash_f){
    uint32_t hash = hash_f(owner_name, table->table_size);

    HashNode* found_node = table->items[hash];

    while (found_node != NULL)
    {
        if (strcmp(found_node->car.owner_name, owner_name) == 0){
            printf("1\n");
            return found_node;
        }
            

        found_node = found_node->next;
    }
    return NULL;
}

HashTable* create_and_fill_table(int table_size, int num_items, hash_func hash_f){
    HashTable* table = create_table(table_size);
    for (int i = 0; i < num_items; i++)
    {
        avto car = generate_random_avto();
        insert(table, car, hash_f);
    }
    return table;
}


void print_avto(avto car, int id) {
    printf(
        "Id: %d  Owner: %-15s  Brand: %-10s  Year: %d  License: %d  Color: %s\n",
        id,
        car.owner_name,
        car.car_brand,
        car.year_of_issue,
        car.state_license_plate,
        car.color
    );
}

void print_table(HashTable* table) {
    if (table == NULL) {
        printf("HashTable == NULL\n");
        return;
    }

    printf("=== Hash table contents (table_size = %d, count_items = %d) ===\n",
           table->table_size, table->count_items);

    // Iterate over each bucket
    for (int i = 0; i < 4; i++) {
        HashNode* node = table->items[i];
        if (node == NULL) {
            // You could print that the bucket is empty, for example:
            // printf("Bucket [%d]: (empty)\n", i);
            continue;
        }

        // If the bucket has at least one node, traverse the chain
        int idx_in_chain = 0;
        while (node != NULL) {
            // Print the record: use a combination of "bucket index + position in chain" as the id
            int id = i * 100 + idx_in_chain; // e.g., bucket_index*100 + position_in_chain
            print_avto(node->car, id);

            node = node->next;
            idx_in_chain++;
        }
    }
    printf("=== End of output ===\n");
}

