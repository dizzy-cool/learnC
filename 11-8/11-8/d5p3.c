#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int d5p3(void){
	
	int key = 123;
	int i = 1;
	int a = 0;
	printf("请输入3位密码:");
	scanf("%d", &a);
	if (a == key) {
		printf("登陆成功!\n");
	}
	else while(a != key){
		printf("您的输错%d次!请重新输入3位密码:\n" , i);
		scanf("%d", &a);
		if (a == key) {
			printf("登陆成功!\n");
			break;
		}
		i++;
		if (i > 2)
			break;
	}
	

	system("pause");
	return 0;
}