#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    int wert;
    struct Node* next;
};


void listprinter(struct Node *head){
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->wert);
        if(temp->next != NULL){
            printf(" -> ");
        } else {
         printf("\n");
        }
        temp = temp -> next;
    }
}
int main(){

    int zahl;                   // speicher für die eingelesene Zahl
    struct Node *head = NULL;   // zeiger fürs erste element
    struct Node *neu = NULL;    // zeigt aufs neue element

    printf("gib eine zahl ein, -1 bendet die eingabe ");
    while (scanf("%d",&zahl) == 1 && zahl != -1) { // liest elem ein bis anzahl der 
        neu = malloc(sizeof(struct Node)); // speicher alkoation 
        if(neu == NULL){    //fehler behandlung falls kein speicher belegt werden konnte.
            fprintf(stderr, "Fehler: Speicherallokierung fehlgeschlagen.\n");
            return 1;
        }

        neu -> wert = zahl; // wert in neu speichern
        neu -> next = NULL; // next mit null setzen

        if(head == NULL){   // falls head lleer
            head = neu;

        } else {    
            struct Node *current = head; // zeiger um durch liste zu gehen
            while (current->next != NULL){ // bedingung damit wir abbrechen wenn lsite leer
                current = current->next;
            }
            current -> next = neu;
        }

    }
    // printed die liste aus
    listprinter(head);

    // revers liste

    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current -> next; 
        current -> next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    listprinter(head);
    return 0;
}