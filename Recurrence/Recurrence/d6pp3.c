#include <stdio.h>
#include <stdlib.h>

int DigitSum(int num) {
	static int sum = 0;
	if (num > 9) {
		DigitSum(num / 10);
	}
	return sum = sum + num % 10;
}

int d6pp3(void){
	
	printf("%d ", DigitSum(1729));

	system("pause");
	return 0;
}