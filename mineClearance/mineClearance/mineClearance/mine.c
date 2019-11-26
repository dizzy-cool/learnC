#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_ROW  9
#define MAX_COL  9
#define MINE_NUM 10

int menu(void){
	printf("===============================\n");
	printf("��ӭ����ɨ����Ϸ!\n");
	printf("��ʼ��Ϸ: 1\n");
	printf("�˳���Ϸ: 0\n");
	printf("===============================\n");
	int choice = 0;
	while (1) {
		scanf("%d", &choice);
		if (choice == 1) {
			return 1;
		}
		else if (choice == 0) {
			return 0;
		}
		else {
			printf("������������,����������:\n");
			continue;
		}
	}
}
void printMap(char showMap[MAX_ROW][MAX_COL]) {
	printf("   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf(" %d |", row);
		for (int col = 0; col < MAX_COL; col++) {
			printf(" %c  ", showMap[row][col]);
		}
		printf("\n");
	}
}
void InputNum(char mineMap[MAX_ROW][MAX_COL], char showMap[MAX_ROW][MAX_COL], int* roww, int* coll) {
	printf("����������:");
	
	while (1) {
		scanf("%d %d", roww, coll);
		if (*roww < 0 || *roww >= MAX_ROW || *coll < 0 || *coll >= MAX_COL) {
			printf("������������!����������: ");
			continue;
		}
																							///////////////�ظ�BUG////////////////////////////
		if (showMap[*roww][*coll] != '*') {
			printf("������������!����������:");
			continue;
		}
		return ;
	}
}
int check(char mineMap[MAX_ROW][MAX_COL], char showMap[MAX_ROW][MAX_COL], int* roww, int* coll) {
	if (mineMap[*roww][*coll] == '1') {
		
		showMap[*roww][*coll] = '1';
		return 1;
	}
	else {
		return 0;
	}
}
int checkLastGrid(char mineMap[MAX_ROW][MAX_COL], char showMap[MAX_ROW][MAX_COL], int* countM) {
	*countM++;
	if (*countM >= 71) {
		return 1;
	}
	return 0;
	
}
void update(char mineMap[MAX_ROW][MAX_COL], char showMap[MAX_ROW][MAX_COL], int* row, int* col) {
	int count = 0;
	int rr = 0;
	int cc = 0;
	for (rr = *row - 1; rr <= *row + 1; rr++) {
		for (cc = *col - 1; cc <= *col + 1; cc++) {
			if (rr < 0 || rr >= MAX_ROW || cc < 0 || cc >= MAX_COL) {
				continue;
			}
			if (mineMap[rr][cc] == '1') {
				count++;	
			}
		}
	}
	showMap[*row][*col] = count + '0';
}

void game(void) {
	srand((unsigned int)time(NULL));

	//1.�����ͼ,����������ͼmineMap��showMap,��ɳ�ʼ��
	//   a)���showMap��ʼ��ȫ��*
	//   b)���mineMap��ʼ��10������(�������λ�����ڷ�)
	int count = MINE_NUM;
	char mineMap[MAX_ROW][MAX_COL] = {'0'};
	int countMined = 0;
	memset(mineMap, '0', MAX_ROW * MAX_COL);
	int r = 0;
	int c = 0;
	while (count) {
		r = rand() % 9;
		c = rand() % 9;
		if (mineMap[r][c] == '1') {
			continue;
		}
		mineMap[r][c] = '1';
		count--;
	}

	char showMap[MAX_ROW][MAX_COL] = { '0' };
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			showMap[row][col] = '*';
		}
	}
	while (1) {
		//2.��ӡ��ͼshowMap
		//printMap(mineMap); ///����
		printf("========================================\n");
		printMap(showMap);
		
		//3.��ʾ�����������,������У��
		InputNum(mineMap, showMap, &r, &c);

		//4.�ж���ǰλ���Ƿ�����,�������,����Ϸ����
		int checkResult = check(mineMap, showMap, &r, &c);
		if (checkResult == 1) {
			printf("��ȵ�����!    gameover\n");
			printMap(mineMap);
			break;
		}

		//5.�����ǰλ�������һ��"�����׵ĸ���"��ô��Ϸʤ��
		int checkLastResult = checkLastGrid(mineMap, showMap, &countMined);
		if (checkLastResult == 1) {
			printf("ɨ�׳ɹ�!��ϲ��!��������!\n");
			break;
		}

		//6.���������,�Ͱ�showMap�ж�Ӧλ��*�޸�Ϊһ�����������,
		//   �������Ҫ���ݵ�ǰ��Χ��8���������׵���Ŀ������
		update(mineMap, showMap, &r, &c);
		//7.����2������Ϸ.


	}
}

int main(void){

	int choice = menu();
	if (choice == 1) {
		game();
	}
	else {
		printf("GoodBye\n");
	}
	
	system("pause");
	return 0;
}