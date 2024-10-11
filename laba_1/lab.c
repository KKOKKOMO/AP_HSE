//Лабораторная работа №1.
//ВЫЧИСЛЕНИЯ ПО РЕКУРРЕНТНЫМ ФОРМУЛАМ С ПОМОЩЬЮ ОПЕРАТОРОВ ЦИКЛА.
//Вычислить приближенное значение функции, вычислив сумму конечного числа элементов ряда двумя способами, используя разные типы циклов: 
//1) с заданной точностью (критерий остановки цикла – значение текущего члена ряда не превосходит точность); 
//2) для заданного количества членов ряда. 
//
//Дополнительные требования:
//Переход к способу вычисления реализовать на этапе выполнения с помощью условного оператора. +
//Проверять корректность введенных данных на этапе выполнения. В случае ввода пользователем некорректных данных (например, отрицательное число членов ряда) на этапе выполнения, возвращать его к повторному вводу, не завершая выполнение программы.
//Не использовать математические функции (из math.h) для вычисления результата.

#include <stdio.h>
# include <stdlib.h>
long double power(double n, int num){   // функция для степени
    if (n == 0){
        return 1;       // в случае нулевой степени возвращет единицу
    }
    long double result = 1.0;
    for (int i = 0; i < num; i++){
        result = result * n;
    }
    return result;
}

long double factorial(int n){       // функция для факториала 
    if(n == 0){
        return 1;       // в случае факториала нуля возвращает единицу   
    }
    int result = 1;
    for(int i = 1; i < n+1; i++){
        result *= i;
    }
    return result;
}


int main(){
    do
    {
    double x;
    int input_ans;
    printf("Input your x: ");
    scanf("%lf", &x);
    if (abs(x)<1)
    {
    printf("Select metod: 1 - With N elements, 2 - with accuracy, 3 - close program\n");
    printf("Press 1 or 2 or 3: ");
    scanf("%d", &input_ans);
    
    if (input_ans == 1)
    {
        int n, a;
        double curr_number, result_first_method;
        printf("Input the quantity of members of the series: ");
        scanf("%d", &n);

        result_first_method = 0;
        for (int i = 1; i < n+1; i++){
            a = 2*i+1;
            curr_number = power(-1.0, i+1)*(((power(3.0, 2*i-1)-3)*power(x, a))/factorial(a));
            printf("Curr_number - %.25lf\n", curr_number);
            result_first_method += curr_number;
            //printf("result_first_method - %lf\n", result_first_method);
        }
        result_first_method = result_first_method/4.0;
        printf("Sum elements first method: %.25lf\n", result_first_method);
    }

    else if (input_ans == 2)
    {
        double accur;
        printf("Input accuracy: ");
        scanf("%Lf", accur);
        int a;
        int i = 1;
        double curr_number = 0.0;
        double sum_result = 0.0;
        while(1)
        {
            a = 2*i+1;
            curr_number = power(-1, i+1)*(((power(3, 2*i-1)-3)*power(x, a))/factorial(a));
            sum_result += curr_number;
            i += 1;
            if (curr_number > accur)
            {
                printf("Done\n");
                sum_result = sum_result/4;
                printf("Sum elements second method: %.25lf\n", sum_result);
                break;
            }
        }
    }
    
    else if (input_ans == 3)
    {
        printf("Goodbye ^_^\n");
        return 0;
    }

    else
    {
        printf("Wrong command. Try again\n");
        scanf("%*[^\n]");
        scanf("%*c");
        continue;
    }

    }
    } while(1);
    return 0;
}


// -0.0014715968967808422222798
// -0.0014723693228807074786374