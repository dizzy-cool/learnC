#include <stdio.h>
#include <stdlib.h>

int StrLen(char* string) {
	static int count = 0;
	if (*string != '\0') {
		StrLen(string + 1);
		count++;
	}
	return count;
}

int d6pp6(void){
	
	printf("%d \n", StrLen("abcd"));
	system("pause");
	return 0;
}