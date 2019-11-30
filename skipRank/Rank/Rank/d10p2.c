#include <stdio.h>
#include <stdlib.h>

void suspect(void) {
	int sus = 0;
	//假设凶手是A 
	for (sus = 'A'; sus <= 'D'; sus++) {
		if ((sus != 'A') + (sus == 'C') + (sus == 'D') + (sus != 'D') == 3) { //是凶手是满足的条件
			printf("凶手是 %c\n", sus);
		}
	}
}

int d10P2(void){
	
	suspect();
	system("pause");
	return 0;
}