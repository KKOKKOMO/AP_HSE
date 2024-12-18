//Вычислить численно интеграл от (sin(arctg(exp(x^(2/9)))))*log(arccos(1/x))dx 
//в пределах интегрирования от a до b, которые вводит пользователь. 
//Для нахождения значения данного интеграла требуется использовать метод Симпсона 
//и метод правых прямоугольников. 
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 10 //any even integer

double func(double x){
    double y = sin(atan(exp(pow(x, (2/9))))) * log10(acos((1/x)));
    return y;
}

double simpsons_metod(double a, double b){ //delta/3 * (f(x0) + f(xn) + 4*sum(f(x1,3,5...)) + 2*sum(f(x2,4,6...)))
    double result = func(a) + func(b);
    double h = (b - a)/(N);

    for (int i = 1; i < N; i += 2) {
        result += 4 * func(a + i * h);
    }
    for (int i = 2; i < N - 1; i += 2) {
        result += 2 * func(a + i * h);
    }
    return result * h / 3;
}

double right_rectangle_metod(double a, double b){
    double h = (b - a) / N;
    double sum = 0;

    for (int i = 1; i <= N; i++) {
        sum += func(a + i * h);
    }

    return sum * h;
}


int main(){
    double a,b;
    printf("INPUT (a) - low boundary: ");
    scanf("%lf", &a);
    printf("INPUT (b) - high boundary: ");
    scanf("%lf", &b);
    if (a > b)
    {
        printf("ERROR: a should be bigger then b");
        exit(0);
        /* code */
    }
    
    printf("RESULT FUNC simpsons_metod: %lf\n", simpsons_metod(a, b));
    printf("RESULT FUNC simpsons_metod: %lf\n", right_rectangle_metod(a, b));
    return 0;
}