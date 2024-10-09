#include <stdio.h>
#include <stdlib.h>


float modul(float number){
    if (number < 0)
    {
        return number*(-1);
    }
    return number;
}

float* create_array(int size_array){
    float* array = (float*)malloc(size_array*sizeof(float));
    printf("Input elements for array(P.S. %d elements): ", size_array);
    for (int i = 0; i < size_array; i++)
    {
        scanf(" %f", &array[i]);
    }
    return array;
}

void print_array(float* array, int size_array){
    for (int i = 0; i < size_array; i++)
    {
        printf("%f\t", array[i]);
    }
    printf("\n");   
}

float max_modul_el(float* array, int size_array, float y){
    float max_el = 0.0;
    for (int i = 0; i < size_array; i++)
    {
        float curr_arr_number = modul(array[i]);
        if (curr_arr_number < y && curr_arr_number > max_el)
        {
            max_el = curr_arr_number;
        }
    }
    return max_el;
}

float avg_between_pos_el(float* array, int size_array){
    float result, sum;
    int elemets_counter;
    int idx_first_pos_el, idx_last_pos_el;

    for (int i = 0; i < size_array; i++)
    {
        if (array[i] > 0)
        {
            idx_first_pos_el = i;
            break;
        }
    }

    for (int i = 0; i < size_array; i++)
    {
        if (array[i] > 0)
        {
            idx_last_pos_el = i;
        }
    }

    elemets_counter = idx_last_pos_el - idx_first_pos_el - 1;
    
    for (int i = idx_first_pos_el+1; i < idx_last_pos_el; i++)
    {
        sum += array[i];
    }
    
    result = sum/elemets_counter; 
    return result;
}