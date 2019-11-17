#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int binarysearch(int arr[], int right, int Tofind);

int d5p2(void) {
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int b = 0;
	int arr_size = sizeof(arr) / sizeof(arr[0]) - 1;
	
	printf("请输入你想查找的数: \n");
	scanf("%d", &b);

	int ret = binarysearch(arr, arr_size, b);
	printf("下标是: %d\n", ret);

	system("pause");
	return 0;
}
int binarysearch(int arr[], int right, int Tofind) {
	int left = 0;
	int  mid = (left + right) / 2;
	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] == Tofind) {
			return mid;
		}
		else if (arr[mid] > Tofind) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	if (left > right) {
		return -1;
	}
}