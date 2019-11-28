#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double increase(double r, int year) {
	double p = pow(1.0 + r, year);
	return p;
}

void dispostion(double money, int year) {
	switch (year) {
	case 5:
		money = money * pow((1 + 0.0585),5);
		printf("money = %lf\n", money);
		break;
	case 2:
		money = money * pow((1 + 0.0468), 2);
		money = money * pow((1 + 0.0540), 3);
		printf("money = %lf\n", money);
		break;
	}
	return ;
}
int main(void){
	dispostion(1000.0, 5);
	 
	//printf("%lf ", increase(0.10, 10));
	system("pause");
	return 0;
}