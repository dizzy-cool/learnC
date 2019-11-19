#include <stdio.h>
#include <stdlib.h>

int BubbleSort(int arr[], int size) {
	//bound��ʾ���Ǳ߽�����
	//[ 0 ,bound )��ʾ�Ѿ����������
	//[bound , size-1)��ʾδ��������
	//ÿ����һ����Сֵ�ŵ�ǰ��ȥ,Ҳ��һλ�������������һ��Ԫ��,
	//������������һ��Ԫ��
	for (int bound = 0; bound < size; bound++) {
		//����һ��ѭ��������������
		//��������������,���Ԫ���������
		//����ѭ���������:�ҵ���ǰ�����������е���Сֵ,������boundλ����

		for (int cur = size - 1; cur > bound; cur--) {
			//�ж�����Ԫ��,����������������,�ͽ�������Ԫ��
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