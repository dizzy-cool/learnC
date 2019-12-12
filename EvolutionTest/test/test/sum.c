#include <stdio.h>
#include <stdlib.h>

int sumFuct(int n) {
	int sum = 0;
	int i = 5;
	int temp = 0;
	while (i--) {
		temp = temp * 10 + n;
		sum = sum + temp;
	}
	return sum;
}

int sum(void) {

	printf("%d\n", sumFuct(2));

	system("pause");
	return 0;
}