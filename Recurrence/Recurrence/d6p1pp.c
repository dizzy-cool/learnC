#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int n) {
	if ( n < 3 ) {
		return n;
	}
	return Fibonacci(n - 2) + Fibonacci(n - 1);
}

int d6p1pp1(void){
	
	int arr[100] = { 1, 1 };
	int n = 0;
	printf("请输入你想得到的斐波那契数列长度:\n");
	scanf("%d", &n);

	for (int i = 2; i < n; i++) {
		arr[i] = Fibonacci(i);
		
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	

	system("pause");
	return 0;
}