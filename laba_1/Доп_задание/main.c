//Формулировка дополнительного задания следующая:
//Вычислить выражение вида 
//floor(sqrt(a)/cbrt(log(b)-c^2)), где a,b,c - переменные типа int , которые вводит пользователь. При реализации использовать для данных вычислений побитовые операции
//
//В данном случае ^ - возведение в степень,
//floor -округление вниз
//log берется по основанию 2
//
//Дедлайн : 19.10.24 22:30



#include <stdio.h>


int square_bitwise(int n){
        int i = n;
        int sq = 0;
        int count = 0;

        while(i > 0){
            if((i & 1) == 1){
                sq += n << count;
            }

            i = i >> 1;
            count++;
        }

        return sq;
    }

int sqrt_bitwise(int n) {
    int res = 0;
    int bit = 1 << 30; // Максимально возможное число, с которого начнем поиск
    
    // Пытаемся найти корень побитовым образом
    while (bit > n)
        bit >>= 2;

    while (bit != 0) {
        if (n >= res + bit) {
            n -= res + bit;
            res = (res >> 1) + bit;
        } else {
            res >>= 1;
        }
        bit >>= 2;
    }
    return res;
}

int log2_bitwise(int n) {
    int res = 0;
    while (n >>= 1) {
        res++;
    }
    return res;
}

int cbrt_bitwise(unsigned x) { //The book "Hacker's Delight" has algorithms for this and many other problems. https://stackoverflow.com/questions/4331820/integer-cube-root
   int s;
   unsigned y, b, y2;

   y2 = 0;
   y = 0;
   for (s = 30; s >= 0; s = s - 3) {
      y2 = 4*y2;
      y = 2*y;
      b = (3*(y2 + y) + 1) << s;
      if (x >= b) {
         x = x - b;
         y2 = y2 + 2*y + 1;
         y = y + 1;
      }
   }
   return y;
}


int main(){
    printf("SQRT_BITWISE: %d\n", sqrt_bitwise(4));
    printf("LOG2_BITWISE: %d\n", log2_bitwise(8));
    printf("CBRT_BITWISE: %d\n", cbrt_bitwise(27));
    printf("SQUARE_BITWISE: %d\n", square_bitwise(4));


    int a, b, c;
    printf("Введите значения a, b и c: ");
    scanf("%d %d %d", &a, &b, &c);

    int sqrt_a = sqrt_bitwise(a);
    int log_b_suare_c = log2_bitwise(b) - square_bitwise(c);
    return 0;
}