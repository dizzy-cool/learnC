#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void flowerNumber(void) {
	int i = 0;
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	int sum = 0;
	int n = 0;

	for (i = 0; i < 100000; i++) {
		a = i / 10000;
		b = i % 10000 / 1000;
		c = i % 1000 / 100;
		d = i % 100 / 10;
		e = i % 10;
		while (i = i / 10) {
			n++;
		}
		n = n + 1;
		switch (n) {
		case 1: sum = (int)pow(e, n);
			break;
		case 2: sum = (int)pow(d, n) + (int)pow(e, n);
			break;
		case 3: sum = (int)pow(c, n) + (int)pow(d, n) + (int)pow(e, n);
			break;
		case 4: sum = (int)pow(b, n) + (int)pow(c, n) + (int)pow(d, n) + (int)pow(e, n);
			break;
		case 5: sum = (int)pow(a, n) + (int)pow(b, n) + (int)pow(c, n) + (int)pow(d, n) + (int)pow(e, n);
			break;
		default:
			break;
		}
		if (sum == i) {
			printf("%d ", i);
		}
		n = 0;
		sum = 0;
	}
}

int d1206p6(void) {
	flowerNumber();
	system("pause");
	return 0;
}