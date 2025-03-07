#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double myAbs(double x){
    if (x < 0) return -x;
    else return x;
}

double mySqrt(double num) {
    if (num < 0) return -1;
    if (num == 0) return 0.0;

    double guess = num;
    double diff = 0.000000001; 

    // https://de.wikipedia.org/wiki/Heron-Verfahren
    while (myAbs(guess * guess - num) > diff) {
        guess = (guess + num / guess) / 2.0;
    }
    //
    return guess;
}

int main(void) {
    double test_values[] = {0, 0.25, 1, 2, 3, 4, 9, 16, 25, 100, 98347};
    int n = sizeof(test_values) / sizeof(test_values[0]); // sizeof(test_values) = 11 * 8; sizeof(test_values[0]) = 8
    printf("%15s %15s %15s %15s\n", "x", "mySqrt(x)", "sqrt(x)", "Difference");
    for (int i = 0; i < n; i++) {
        double x = test_values[i];
        double my_result = mySqrt(x);
        double lib_result = sqrt(x);
        printf("%15.9lf %15.9lf %15.9lf %15.9lf\n", x, my_result, lib_result, my_result - lib_result);
    }
    return 0;
}
