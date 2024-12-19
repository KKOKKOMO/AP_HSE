#include <stdio.h>
#include <stdlib.h>

#define BUFFER_LIMIT 1000 // Максимальный размер буфера, надо смотреть, 
                          // чтобы размер файла был меньше чем sizeof(int)*BUFFER_LIMIT
struct Queue {
  int data[BUFFER_LIMIT];
  int pop_idx;
  int push_idx;
};

int pop(struct Queue *queue) {
  int elt = queue->data[queue->pop_idx]; 
  queue->pop_idx++;
  return elt;
}

void push(struct Queue *queue, int elt) {
  queue->data[queue->push_idx] = elt;
  queue->push_idx++;
}

void write_numbers_to_binary(const char *filename, int *numbers, size_t count);

int main() {
    const char *input_file = "test.bin"; // main_laba_4.c - 984 байта
    struct Queue bigger_c = { .pop_idx = 0, .push_idx = 0 };
    struct Queue lower_c = { .pop_idx = 0, .push_idx = 0 };
    int current_value;
    int С;

    int numbers_to_write[] = {10, 50, 20, 70, 30, 40};
    size_t count = sizeof(numbers_to_write) / sizeof(numbers_to_write[0]);
    write_numbers_to_binary(input_file, numbers_to_write, count);

    printf("ENTER C: ");
    if (scanf("%d", &С) != 1) {
        printf("ERROR: Please enter a valid integer!s\n");
        return 1;
    }

    FILE *file = fopen(input_file, "rb");
    if (file == NULL) {
        printf("OPEN FILE ERROR\n");
        return 1;
    }

    while (fread(&current_value, sizeof(int), 1, file) == 1) {
        if (current_value < С) {
            push(&lower_c, current_value);
        } else {
            push(&bigger_c, current_value);
        }
    }
    fclose(file);


    printf("ELEMENTS BELOW THE C :\n");
    while (lower_c.pop_idx < lower_c.push_idx) {
        printf("%d ", pop(&lower_c));
    }

    printf("\n\n");
    
    printf("ELEMENTS GREATER THAN OR EQUAL TO THE C:\n");
    while (bigger_c.pop_idx < bigger_c.push_idx) {
        printf("%d ", pop(&bigger_c));
    }

    printf("\n");
    return 0;
}




void write_numbers_to_binary(const char *filename, int *numbers, size_t count) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("OPEN FILE ERROR '%s'!\n", filename);
        return;
    }
    fwrite(numbers, sizeof(int), count, file);
    fclose(file);
}