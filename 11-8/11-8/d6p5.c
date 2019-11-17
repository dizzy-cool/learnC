#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(int num);

int main(void){
	int a = 0;

	scanf("%d", &a);
	if (prime(a) == 1) {
		printf("%d是素数\n", a);
	}
	else {
		printf("%d不是素数\n", a);
	}

	system("pause");
	return 0;
}
int prime(int num) {
	int b = (int)sqrt(num);
	int i = 0;
	for (i = 2; i <= b; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	if (i >= b)
		return 1;

}