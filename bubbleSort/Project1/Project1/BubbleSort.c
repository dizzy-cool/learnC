#include <stdio.h>
#include <stdlib.h>

int BubbleSort(int arr[], int size) {
	//bound表示的是边界坐标
	//[ 0 ,bound )表示已经排序的区间
	//( bound , size-1]表示未排序区间
	for (int bound = 0; bound < size; bound++) {
		//再来一重循环用来遍历数组
		//按照升序来排列,最大元素在最后面
		for (int cur = size - 1; cur > bound; cur--) {
			//判断调换,将不符合升序规则的元素调换位置
			if (arr[bound] > arr[cur]) {
				int temp = 0;
				temp = arr[bound];
				arr[bound] = arr[cur];
				arr[cur] = temp;
			}
		}
	}
}
void PrintArr(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
}

int main(void){
	int arr[] = { 9, 5, 2, 7, 3, 6, 10, 8 };
	int size = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr , size);
	PrintArr(arr , size);

	system("pause");
	return 0;
}