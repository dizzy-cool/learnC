#include <stdio.h>
#include <stdlib.h>

void printfAll(int num) {
	if (num > 9) {
		printfAll(num / 10);
		
	}
	printf("%d " , num % 10);
}

int d6pp7(void){
	
	printfAll(1234);
	system("pause");
	return 0;
}