#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 64

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Benutzung: %s <Quelle> <Ziel>\n", argv[0]);
        return 1;
    }

    FILE *fileR = fopen(argv[1], "rb");
    if (fileR == NULL) {
        perror("Fehler beim Öffnen der Quelldatei");
        return 1;
    }

    FILE *fileW = fopen(argv[2], "wb");
    if (fileW == NULL) {
        perror("Fehler beim Öffnen der Zieldatei");
        fclose(fileR);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, fileR)) > 0) {
        size_t bytesWritten = fwrite(buffer, 1, bytesRead, fileW);
        if (bytesWritten != bytesRead) {
            perror("Fehler beim Schreiben in die Zieldatei");
            fclose(fileR);
            fclose(fileW);
            return 1;
        }
    }

    if (ferror(fileR)) {
        perror("Fehler beim Lesen der Quelldatei");
    }

    fclose(fileR);
    fclose(fileW);

    return 0;
}
