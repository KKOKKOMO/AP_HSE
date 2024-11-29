#include <CUnit/Basic.h>
#include <CUnit/CUnit.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>


static FILE* temp_file = NULL;

float max_modul_el(float* array, int size_array, float y){
    float max_el = -FLT_MIN;
    for (int i = 0; i < size_array; i++)
    {
        float curr_arr_number = (array[i] >= 0) ? array[i] : array[i]*(-1); // modul(array[i]); 
        if (curr_arr_number < y && curr_arr_number > max_el)
        {
            max_el = curr_arr_number;
        }
    }

    if (max_el == -FLT_MIN)
    return -FLT_MIN;
    
    return max_el;
}

float avg_between_pos_el(float* array, int size_array){
    float result, sum;
    int elemets_counter;
    int idx_first_pos_el = -1;
    int idx_last_pos_el = -1;

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
    if (idx_last_pos_el == idx_first_pos_el || elemets_counter == 0) {
        return FLT_MAX;
    }

    for (int i = idx_first_pos_el+1; i < idx_last_pos_el; i++)
    {
        sum += array[i];
    }
    
    result = sum/elemets_counter; 
    return result;
}


void test_max_modul_el(void) {
    // Тест 1: нормальный случай. Ожидается: 4
    float arr1[] = {1, 2, 3, 4, 5, 6};
    CU_ASSERT_DOUBLE_EQUAL(max_modul_el(arr1, 6, 5), 4.0, 0.0001);

    // Тест 2: все элементы больше чем y. Ожидается: -FLT_MIN
    float arr2[] = {100, 20, 30, 40, 50};
    CU_ASSERT_DOUBLE_EQUAL(max_modul_el(arr2, 5, 15), -FLT_MIN, 0.0001);

    // Тест 3: все элементы меньше чем y. Ожидается: 4.0
    float arr3[] = {1, 2, 3, 4};
    CU_ASSERT_DOUBLE_EQUAL(max_modul_el(arr3, 4, 10), 4.0, 0.0001);

    // Тест 4: отрицательные значения в массиве. Ожидается: 4.0
    float arr4[] = {-1, -2, -3, -4};
    CU_ASSERT_DOUBLE_EQUAL(max_modul_el(arr4, 4, 5), 4.0, 0.0001);

    // Тест 5: смесь положительных и отрицательных значений. Ожидается: 4.0
    float arr5[] = {-1, 2, -3, 4, -5};
    CU_ASSERT_DOUBLE_EQUAL(max_modul_el(arr5, 5, 5), 4.0, 0.0001);

    // Тест 6: пустой массив. Ожидается: -FLT_MIN 
    float arr6[] = {};
    CU_ASSERT_DOUBLE_EQUAL(max_modul_el(arr6, 0, 5), -FLT_MIN, 0.0001);

    // Тест 7: два максимальных элемента (положительные). Ожидается: 4.0
    float arr7[] = {1, 2, 3, 4, 4, 5};
    CU_ASSERT_DOUBLE_EQUAL(max_modul_el(arr7, 6, 5), 4.0, 0.0001);

    // Тест 8: два максимальных элемента, один отрицательный, другой положительный. Ожидается: 4.0
    float arr8[] = {-5, 2, 3, 4, 5};
    CU_ASSERT_DOUBLE_EQUAL(max_modul_el(arr8, 5, 5), 4.0, 0.0001);

    // Тест 9: два максимальных элемента, один отрицательный, другой положительный. Ожидается: 4.0
    float arr9[] = {-4, 2, 3, 4, -5};
    CU_ASSERT_DOUBLE_EQUAL(max_modul_el(arr9, 5, 5), 4.0, 0.0001);
}

void test_avg_between_pos_el(void) {

    // Тест 1: Несколько положительных элементов с отрицательными между ними. Ожидается: (-3 + 4 - 5) / 3.0
    float arr1[] = {-1, 2, -3, 4, -5, 6};
    CU_ASSERT_DOUBLE_EQUAL(avg_between_pos_el(arr1, 6), (-3 + 4 - 5) / 3.0, 0.0001);

    // Тест 2: Массив состоит только из отрицательных элементов. Ожидается: FLT_MAX
    float arr2[] = {-1, -2, -3, -4};
    CU_ASSERT_DOUBLE_EQUAL(avg_between_pos_el(arr2, 4), FLT_MAX, 0.0001);

    // Тест 3: Массив содержит только один положительный элемент. Ожидается: FLT_MAX
    float arr3[] = {-1, -2, 3, -4};
    CU_ASSERT_DOUBLE_EQUAL(avg_between_pos_el(arr3, 4), FLT_MAX, 0.0001);

    // Тест 4: Положительные элементы на краях массива, есть отрицательные между ними. Ожидается: (-2 - 3) / 2.0
    float arr4[] = {1, -2, -3, 4};
    CU_ASSERT_DOUBLE_EQUAL(avg_between_pos_el(arr4, 4), (-2 - 3) / 2.0, 0.0001);

    // Тест 5: Пустой массив. Ожидается: FLT_MAX
    float arr5[] = {};
    CU_ASSERT_DOUBLE_EQUAL(avg_between_pos_el(arr5, 0), FLT_MAX, 0.0001);

    // Тест 6: Все элементы положительные, без отрицательных между ними. Ожидается: (2 + 3) / 2.0
    float arr6[] = {1, 2, 3, 4};
    CU_ASSERT_DOUBLE_EQUAL(avg_between_pos_el(arr6, 4), (2 + 3) / 2.0, 0.0001);

    // Тест 7: Массив из 1 элемента. Ожидается: FLT_MAX
    float arr7[] = {5};
    CU_ASSERT_DOUBLE_EQUAL(avg_between_pos_el(arr7, 1), FLT_MAX, 0.0001);

    // Тест 8: нет элементов между 1-м и 2-м положительными элементами. Ожидается: FLT_MAX
    float arr8[] = {1, 2, -5, -6, -7};
    CU_ASSERT_DOUBLE_EQUAL(avg_between_pos_el(arr8, 5), FLT_MAX, 0.0001);

    // Тест 9: Сумма элементов между первым и последним положительными элементами 0. Ожидается: 0
    float arr9[] = {1, 2, -2, 4};
    CU_ASSERT_DOUBLE_EQUAL(avg_between_pos_el(arr9, 4), 0, 0.0001);
}


// Настройка тестов
int main() {
    // Инициализация реестра тестов
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Создание тестового набора и добавление тестов
    CU_pSuite suite_1 = CU_add_suite("Max Modul El Suite", NULL, NULL);
    CU_add_test(suite_1, "test_max_modul_el", test_max_modul_el);

    CU_pSuite suite_2 = CU_add_suite("Avg Between Pos El Suite", NULL, NULL);
    CU_add_test(suite_2, "test_avg_between_pos_el", test_avg_between_pos_el);

    CU_basic_set_mode(CU_BRM_VERBOSE);  // Устанавливаем подробный вывод
    CU_basic_run_tests();

    CU_cleanup_registry();
    return 0;
}


