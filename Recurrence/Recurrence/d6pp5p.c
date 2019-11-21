#include <stdio.h>
#include <stdlib.h>

//非递归函数实现strlen
int StrLenT(char* string) {
	static int  count = 0;
	while (*string != '\0') {
		count++;
		string++;
	}
	return count;
}

int d6pp5p(void) {

	printf("%d \n", StrLenT("abcdffff"));
	system("pause");
	return 0;
}