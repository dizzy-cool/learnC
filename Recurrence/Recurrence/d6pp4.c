#include <stdio.h>
#include <stdlib.h>

void reverse_string(char* string) {
	string++;
	if (*string != '\0') {
		
		reverse_string(string);
	}
	string--;
	printf("%c", *string);


}



int d6pp4(void){
	char* string = "abcdefjh";
	reverse_string(string);
	printf("\n");
	for (; *string != '\0'; string++) {
		printf("%c", *string);
	}
	
	system("pause");
	return 0;
}