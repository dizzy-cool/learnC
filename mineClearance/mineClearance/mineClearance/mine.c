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
	printf("欢迎来到扫雷游戏!\n");
	printf("开始游戏: 1\n");
	printf("退出游戏: 0\n");
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
			printf("您的输入有误,请重新输入:\n");
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
	printf("请输入坐标:");
	
	while (1) {
		scanf("%d %d", roww, coll);
		if (*roww < 0 || *roww >= MAX_ROW || *coll < 0 || *coll >= MAX_COL) {
			printf("您的输入有误!请重新输入: ");
			continue;
		}
																							///////////////重复BUG////////////////////////////
		if (showMap[*roww][*coll] != '*') {
			printf("您的输入有误!请重新输入:");
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

	//1.定义地图,创建两个地图mineMap和showMap,完成初始化
	//   a)针对showMap初始化全是*
	//   b)针对mineMap初始化10个地雷(根据随机位置来摆放)
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
		//2.打印地图showMap
		//printMap(mineMap); ///测试
		printf("========================================\n");
		printMap(showMap);
		
		//3.提示玩家输入坐标,并进行校验
		InputNum(mineMap, showMap, &r, &c);

		//4.判定当前位置是否是雷,如果是雷,则游戏结束
		int checkResult = check(mineMap, showMap, &r, &c);
		if (checkResult == 1) {
			printf("你踩到雷了!    gameover\n");
			printMap(mineMap);
			break;
		}

		//5.如果当前位置是最后一个"不是雷的格子"那么游戏胜利
		int checkLastResult = checkLastGrid(mineMap, showMap, &countMined);
		if (checkLastResult == 1) {
			printf("扫雷成功!恭喜你!你真厉害!\n");
			break;
		}

		//6.如果不是雷,就把showMap中对应位置*修改为一个具体的数字,
		//   这个数组要根据当前周围的8个格子中雷的数目来决定
		update(mineMap, showMap, &r, &c);
		//7.返回2继续游戏.


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