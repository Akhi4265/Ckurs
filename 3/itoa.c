#include <stdio.h>
#include <stdlib.h>


int myATOI(char *string){
    int result = 0;
    int sign = 1;

    while (*string == ' '){
        string ++;
    }
    if (*string == '-' || *string == '+') {
        if (*string == '-') {
            sign = -1;
        }
        string ++;
    }
    while(*string >= '0' && *string <= '9'){
        result = result * 10 + (*string - '0');
        string ++;
    }
    return sign * result;
}

char *myITOA(int num){
    int i = 0, sign = num, len = 0;
    char temp[2000];

    if (num < 0) {
        num = -num;
    }
    do {
        temp[i++] = (num % 10) + '0';
        num /= 10;
    }while (num > 0);
    if (sign < 0) {
        temp[i++] = '-';
    }
    temp[i] = '\0';
    len = i;

    // von hier  
    char *result = (char *)malloc(len + 1);
    if (!result) {
        return NULL;
    }
    // bis hier gpt
    
    for(int j = 0; j < len; j++){
        result[j] = temp[len - 1 - j];
    }
    result[len] = '\0';
    return result;
}

int main(void){
    printf("%d\n",myATOI("   -2345hallo"));
    
    printf("%s\n",myITOA(-2345));
}