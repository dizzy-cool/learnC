#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int TimesSquare(int num , int k) {
	if (k == 0) {
		return 1;
	}
	return TimesSquare(num , k - 1) * num;
}

int d6pp2(void){
	
	int num = 0;
	int times = 0;

	printf("���������n = ");
	scanf("%d", &num);
	printf("������η���times = ");
	scanf("%d", &times);

	printf("%d \n", TimesSquare(num, times));

	system("pause");
	return 0;
}