#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[] ) {

	for (int i = 1; i < argc; i++){
		int year = atoi(argv[i]);
		if((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0){
			printf("%d ist ein Schaltjahr\n",year);
		} else{
			printf("%d ist kein Schaltjahr\n", year);
		}
	}
	return 0;
}
