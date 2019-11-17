#include <stdio.h>
#include <stdlib.h>

void init(int* array);
void empty(int* array);
void reverse(int* array);

int d6p4(void){
	int arr[10] = {0};
	init(arr);
	printf("数组初始化后:\n");
	for (int i = 0; i < 10; i++) {
		printf("arr[%d] = %d \n", i, arr[i]);
	}
	
	reverse(arr);
	printf("数组元素逆置后:\n");
	for (int i = 0; i < 10; i++) {
		printf("arr[%d] = %d \n", i, arr[i]);
	}
	empty(arr);
	printf("数组清空后:\n");
	for (int i = 0; i < 10; i++) {
		printf("arr[%d] = %d \n", i, arr[i]);
	}

	system("pause");
	return 0;
}
void init(int* array) {
	for (int i = 0; i < 10; i++) {
		*array = i;
		array++;
	}
}
void empty(int* array) {
	for (int i = 0; i < 10; i++) {
		*array = 0;
		array++;
	}
}
void reverse(int* array) {
	int temp = 0;
	int j = 9;
	for (int i = 0; i < 5; i++) {
		temp = *array;
		*array = *(array + j);
		*(array + j) = temp;
		array++;
		j -= 2;
	}
}