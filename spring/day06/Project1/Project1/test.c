#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * reverseOnlyLetters(char * S);

int main(void) {
	char S[] = "-S2,_";
	char YUQI[] = "-S2,_";
	printf("\t%s ", S);
	printf("\n");
	printf("yuqi \t%s ", YUQI);
	printf("\n");

	int i = 0;
	char* ret ;
	ret = reverseOnlyLetters(S);
	printf("\t");

	for (i = 0; S[i] != '\0'; i++) {
		printf("%c", ret[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
char * reverseOnlyLetters(char * S) {
	int length = strlen(S);
	int i = 0, j = length - 1;
	char temp = ' ';
	while (i <= j) {
		//排除非字母
		//排除最后面的
		if (!(((S[j] <= 'Z') && (S[j] >= 'A')) || ((S[j] <= 'z') && (S[j] >= 'a')))) { //运算符优先级不熟练
			j--;
			continue;
		}
		if (((S[i] <= 'Z') && (S[i] >= 'A')) || ((S[i] <= 'z') && (S[i] >= 'a'))) {
			temp = S[i];
			S[i] = S[j];
			S[j] = temp;

			j--;
		}
		i++;
	}
	return S;
}