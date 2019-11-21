#include <stdio.h>
#include <stdlib.h>

int factorial(int num) {
	if (num == 1) {
		return 1;
	}
	return factorial(num - 1) * num;
}

int d6pp66(void){
	
	printf("%d \n" , factorial(10));
	system("pause");
	return 0;
}