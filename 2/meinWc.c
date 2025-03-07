#include <ctype.h>
#include <stdio.h>
int main(int argc, char *argv[]){
    if (argc < 2) {
        printf("gebe noch eine datei an");
        return 1;
    }
    for(int i = 1; i < argc; i++ ){
        
        FILE *file = fopen(argv[i], "r");
        if(file == NULL){
            perror("Fehler beim öffnen\n");
            continue;
        }

        int c = fgetc(file);

        int charCount = 0;
        int wordCount = 0;
        int lineCount = 1;
        int inWord = 0;

        while (c != EOF) {
            charCount++;
            
            if(isspace(c)){
                inWord = 0;
            } else if (!inWord) {
                inWord = 1;
                wordCount ++;
            }
            
            if (c == '\n') {
                lineCount ++;
                c = fgetc(file);
                continue;
            }


            c = fgetc(file);
        }

        printf("%-15s | Zeilen: %10d | Wörter: %10d | Zeichen: %10d\n", argv[i], lineCount, wordCount, charCount);
        fclose(file);
    }//
    return 0;
}