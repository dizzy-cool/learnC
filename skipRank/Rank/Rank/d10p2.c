#include <stdio.h>
#include <stdlib.h>

void suspect(void) {
	int sus = 0;
	//����������A 
	for (sus = 'A'; sus <= 'D'; sus++) {
		if ((sus != 'A') + (sus == 'C') + (sus == 'D') + (sus != 'D') == 3) { //�����������������
			printf("������ %c\n", sus);
		}
	}
}

int d10P2(void){
	
	suspect();
	system("pause");
	return 0;
}