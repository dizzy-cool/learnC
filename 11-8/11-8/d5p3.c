#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int d5p3(void){
	
	int key = 123;
	int i = 1;
	int a = 0;
	printf("������3λ����:");
	scanf("%d", &a);
	if (a == key) {
		printf("��½�ɹ�!\n");
	}
	else while(a != key){
		printf("�������%d��!����������3λ����:\n" , i);
		scanf("%d", &a);
		if (a == key) {
			printf("��½�ɹ�!\n");
			break;
		}
		i++;
		if (i > 2)
			break;
	}
	

	system("pause");
	return 0;
}