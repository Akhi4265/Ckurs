#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
struct glied {
    int wert;
    struct glied *next;
};

int main(){
    int zahl;
    struct glied *kopf = NULL;
    printf("gib eine zahl ein, -1 bendet die eingabe ");
    while (scanf("%d",&zahl) == 1 && zahl != -1) {
        struct glied *neu = malloc(sizeof(struct glied));
        if(neu == NULL){
            printf(stderr, "Fehler: Speicherallokierung fehlgeschlagen.\n");
            while (kopf != NULL) {
                struct glied *temp = kopf;
                kopf = kopf->next;
                free(temp);
            }
            return 1;
        }

        neu -> wert = zahl;
        neu -> next = kopf;
    
    }    
}