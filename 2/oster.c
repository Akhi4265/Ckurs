#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    
    for (int i = 1; i < argc; i++) {
        int year = atoi(argv[i]);
        // https://de.wikipedia.org/wiki/Gau%C3%9Fsche_Osterformel
        int a = year % 19;
        int b = year % 4;
        int c = year % 7;
        int k = year / 100;
        int p = (13 + 8 * k) / 25;
        int q = k / 4;
        int M = (15 - p + k - q) % 30;
        int d = (19 * a + M) % 30;
        int N = (4 + k - q) % 7;
        int e = (2 * b + 4 * c + 6 * d + N) % 7;

        int day = 22 + d + e;
        int month = 3;

        if (day > 31) {
            day -= 31;
            month = 4;
        }

        
        if (d == 29 && e == 6) {
            day = 19;
        }
        if (d == 28 && e == 6 && (11* M) % 30 < 19) {
            day = 18;
        }

        printf("Ostern %d ist am: %02d.%02d.\n", year, day, month);
    }

    return 0;
}