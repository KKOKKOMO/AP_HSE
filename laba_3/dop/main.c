//Вычислить численно интеграл от (sin(arctg(exp(x^(2/9)))))*log(arccos(1/x))dx 
//в пределах интегрирования от a до b, которые вводит пользователь. 
//Для нахождения значения данного интеграла требуется использовать метод Симпсона 
//и метод правых прямоугольников. 
#include <stdio.h>
#include <math.h>
#define N 10 //any even integer

double func(double x){
    double y = sin(atan(exp(pow(x, (2/9))))) * log10(acos((1/x)));
    return y;
}

double simpsons_metod(double a, double b){ //delta/3 * (f(x0) + f(xn) + 4*sum(f(x1,3,5...)) + 2*sum(f(x2,4,6...)))
    double result = 0;
    int count_fx = (N-2)/2;
    double even_position_fx[count_fx]; // *2
    double odd_position_fx[count_fx]; // *4
    double delta_x = (b - a)/(N);

    for (int i = 0; i < count_fx; i++)
    {
        odd_position_fx[i] = func(a + delta_x*(2*i+1));
        //printf("%d\n", i);
        //printf("count_fx %d\n", count_fx);
        printf("odd_position_fx %lf\n", odd_position_fx[i]);
    }
    printf("------------------------------\n");

    for (int i = 1; i <= count_fx; i++)
    {
        even_position_fx[i] = func(a + delta_x*(2*i));
        //printf("%d\n", i);
        //printf("count_fx %d\n", count_fx);
        printf("even_position_fx %lf\n", even_position_fx[i]);
    }
    return 0;
}

double right_rectangle_metod(double a, double b, double x){
    
    return 0;
}


int main(){
    double a,b;
    printf("INPUT (a) - low boundary: ");
    scanf("%lf", &a);
    printf("INPUT (b) - high boundary: ");
    scanf("%lf", &b);
    simpsons_metod(a, b);

    printf("RESULT FUNC: %lf\n", func(2.4));
    return 0;
}