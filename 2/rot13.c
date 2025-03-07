#include <stdio.h>


int main() {
    int c;
    while ((c = getchar()) != EOF) {

        if ('A' <= c && c <= 'Z') {
            c = ((c - 'A' + 13) % 26) + 'A';
        }
        if ('a' <= c && c <= 'z') {
            c = ((c - 'a' + 13) % 26) + 'a';
        }
        putchar(c);
    }
    return 0;
}
