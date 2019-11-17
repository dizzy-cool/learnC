#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void factor(int a);

int d6p1(void) {

	int b;
	scanf("%d", &b);
	factor(b);

	system("pause");
	return 0;
}
void factor(int a) {
	int i = 0;
	int j = 0;
	for (i = 1; i <= a; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d * %d = %d" , j, i, i*j);
		}
		printf("\n");
	}
}