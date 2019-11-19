#include <stdio.h>
#include <stdlib.h>

int BubbleSort(int arr[], int size) {
	//bound表示的是边界坐标
	//[ 0 ,bound )表示已经排序的区间
	//[bound , size-1)表示未排序区间
	//每次找一个最小值放到前面去,也就一位置已排序区间多一个元素,
	//待排序区间少一个元素
	for (int bound = 0; bound < size; bound++) {
		//再来一重循环用来遍历数组
		//按照升序来排列,最大元素在最后面
		//这重循环用来完成:找到当前待排序区间中的最小值,并放在bound位置上

		for (int cur = size - 1; cur > bound; cur--) {
			//判断相邻元素,如果不符合升序规则,就交换两个元素
			if (arr[cur - 1] > arr[cur]) {
				int temp = 0;
				temp = arr[cur - 1];
				arr[cur - 1] = arr[cur];
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