#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int d5p3(void){
	
	char key[10] = {0};
	int i = 0;
	char* p = "asdfgh";
	

	for (i = 0; i < 3; i++) {
		printf("����������:\n");
		scanf("%s", key);

		if (strcmp(key, p) == 0) {

			printf("��½�ɹ�\n");
			break;
		}
		else {
			printf("�������\n");
		}
		if (i == 3) {
			printf("�������3��,�˳�����!\n");

		}

	}
	

	

	system("pause");
	return 0;
}