#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseStringFake(char* string) {
	string++;
	if (*string != '\0') {
		
		reverseStringFake(string);
	}
	string--;
	printf("%c", *string);
}

void reverseString(char* str) {
	int i = strlen(str) - 1;
	char temp = '0';
	temp = *str;
	*str = *(str + i);
	*(str + i) = '\0';

	reverseString(str+1);
	*(str + i) = temp;
}



int main(void){
	char* string = "abcd";
	reverseString(string);
	printf("\n");
	for (; *string != '\0'; string++) {
		printf("%c", *string);
	}
	
	system("pause");
	return 0;
}