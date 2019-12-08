#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*************×Ö·û´®ÄæÖÃ*****************/
void reverseWord(char* start, char* end) {
	int i = 0;
	int len = end - start;
	int j = 0;

	char temp = '0';
	for (i = 0, j = len - 1; i < j; i++, j--) {
		temp = start[i];
		start[i] = start[j];
		start[j] = temp;
	}
}
/*******************************************
**	 Íê³É×Ö·û´®°´ÕÕ¿Õ¸ñÄæÐò
**	 student a am i
**   tneduts a ma i 
**	 i am a student
*******************************************/
void reverse(char* src) {
	int i = 0;
	char* start = src;
	char* end;
	for (i = 0; src[i]; i++) {
		if (src[i] == ' ') {
			end = src + i;
			reverseWord(start, end);
			start = end + 1;
		}
	}
	reverseWord(start, src + i);
	reverseWord(src, src + i);
}

int d1206P7(void){
	char src[] = "student a am i";
	//scanf("%[^\n]", src);
	reverse(src);
	
	printf("%s", src);

	system("pause");
	return 0;
}