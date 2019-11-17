#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void func(int* a, int* b);
int d6p2(void){
	int  ch1 = 0;
	int  ch2 = 0;
	printf("输入两个整数:\n");
	scanf("%d%d", &ch1, &ch2);
	func(&ch1, &ch2);

	system("pause");
	return 0;
}
void func(int* a, int* b) {
	int c = 0;
	c = *a;
	*a = *b;
	*b = c;	
	printf("交换后:\n");
	printf("%d\n", *a);
	printf("%d\n", *b);
}