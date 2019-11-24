#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double increase(double r, int year) {
	double p = pow(1.0 + r, year);
	return p;
}

int main(void){
	
	 
	printf("%lf ", increase(0.10, 10));
	system("pause");
	return 0;
}