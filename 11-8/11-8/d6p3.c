#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int year_run(int ye);
int d6p3(void){
	int year = 0;
	printf("����һ�����:\n");
	scanf("%d", &year);

	if (year_run(year) == 1) {
		printf("%d ������\n", year);
	}
	else {
		printf("%d ��������\n", year);
	}

	system("pause");
	return 0;
}
int year_run(int ye) {
	if (ye % 4 == 0 && ye % 100 != 0) {
		return 1;
	}
	else if (ye % 400 == 0) {
		return 1;
	}
	else
		return 0;
}