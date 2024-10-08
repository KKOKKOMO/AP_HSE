long double power(double x, int power){
    long double result = 1.0;
    for (int i = 0; i < power; i++) {
        result *= x;
    }
    return result;
}

long double factorial(int number) {
    if (number == 1 || number == 0)
        return 1;
    return number * factorial(number - 1);
}
