#include <stdio.h>
#include <stdlib.h>


int d5p4(void){
	int ch = '0';
	while (1) {
		ch = getchar();
		if ( ch >= 'a' && ch <= 'z') {
			printf("%c", ch - 32);
		}
		else if(ch >= 'A' && ch <= 'Z') {
			printf("%c", ch + 32);
		}
		else if (ch >= '0' && ch <= '9') {
			continue;
		}

	}

	system("pause");
	return 0;
}