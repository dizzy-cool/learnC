#include <stdio.h>
#include <stdlib.h>

int factorial_T(int num) {
	int product = 1;

	while (num != 0) {
		product = product * num;
		num--;
	}
	return product;
}

int d6pp6p(void) {

	printf("%d \n", factorial_T(10));
	system("pause");
	return 0;
}