#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int d6p1ppp(void){
	int arr[100] = { 1, 1 };
	int n = 0;
	printf("����������õ���쳲��������г���:\n");
	scanf("%d", &n);
	
	for (int i = 2; i < n; i++) {
		arr[i] = arr[i - 2] + arr[i - 1];
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	system("pause");
	return 0;
}