
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
int main(){
    int pcNumber;
    int playerNumber;
    int trys = 0;
    
    srand(time(NULL));
    pcNumber = rand() % 100 + 1;
    
    do {
        trys ++;
        printf("das ist dein %d Versuch, gib eine Zahl ein zwischen 1 - 100: ",trys);
        scanf("%d", &playerNumber);

        if(pcNumber == playerNumber){
            printf("%d ist die gesuchte Zahl, es wurden %d versuche gebraucht.\n",pcNumber ,trys);
        } else if (pcNumber > playerNumber) {
            printf("%d ist zu klein\n",playerNumber);
        } else {
            printf("%d zugross\n",playerNumber);
        }
    } while (pcNumber != playerNumber);
    
    return 0;
}