#include <stdio.h>

unsigned int sadd(unsigned int x) {
    unsigned int count = 0;
    
    while (x) {  
        printf("x = %d  x&1 = %d\n", x, x&1);
        count += x & 1;  
        
        x = x >> 1;  // schiebt kommer nach recht zahl wird kleiner um die hälfte
    }
    
    return count;
}

unsigned int ctz(unsigned int x) {
    unsigned int count = 0;
    
    while ((x&1) == 0) {  
        count ++;
        x = x >> 1;  // schiebt kommer nach recht zahl wird kleiner um die hälfte
    }
    
    return count;
}
unsigned int rev(unsigned int x) {
    unsigned int result = 0;
    for (int i = 0; i < 32; i++) {  
        result = (result << 1) | (x & 1); // gpt
        x >>= 1;
    }
    return result;
}


int main() {
    unsigned int num = 2;  // Beispiel: 29 = 11101 (3 gesetzte Bits)
    printf("Anzahl der gesetzten Bits in %u: %u\n", num, sadd(num));

    printf("durch 2 teilbar in %u: %u\n", num, ctz(num));

    printf(" rev(%u) = %u\n", num, rev(num));
    return 0;
}


