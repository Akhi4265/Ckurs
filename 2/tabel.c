#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("%5s %15s %25s %40s\n", "x", "x^2", "2^x", "x!"); 

    for (int i = 1; i <= 100; i++) {
        int xHoch2 = i * i;
        unsigned long long zweiHochI = 1ULL << i;
        
        long long fakultaet = 1;
        for (int j = 1; j <= i; j++) {
            fakultaet *= j;
        }

        printf("%5d %15d %25llu %40lld\n", i, xHoch2, zweiHochI, fakultaet);
    }

    return 0;
}
