#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define MAX_ROW 3
#define MAX_COL 3


int menu() {
	printf("============================\n");
	printf("欢迎来到三子棋游戏\n");
	printf("开始游戏: 1\n");
	printf("结束游戏: 0\n");
	printf("============================\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void printBoard(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf("| %c | %c | %c |\n", chessBoard[row][0], chessBoard[row][1], chessBoard[row][2]);
		printf("+---+---+---+\n");
	}
}

void player(char chessBoard[MAX_ROW][MAX_COL]) {
	printf("轮到玩家落子:");
	while (1) {
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);

		if (row < 0 || row > MAX_ROW - 1 
			|| col < 0 || col > MAX_COL - 1 
			|| chessBoard[row][col] == 'x' 
			|| chessBoard[row][col] == 'o') {
			printf("您的输入有误!请重新输入:\n");
			continue;
		}
		else {
			chessBoard[row][col] = 'x';
		//	printBoard(chessBoard);
			break;
		}
	}
	
}

char check(char chessBoard[MAX_ROW][MAX_COL]) {
	//检查行
	for (int row = 0; row < MAX_ROW; row++) {
		if (chessBoard[row][0] != ' '
			&& chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2]
			&& chessBoard[row][0] == 'x') {
			return 'x';
		}
		else if (chessBoard[row][0] != ' '
			&& chessBoard[row][0] == chessBoard[row][1]
			&& chessBoard[row][0] == chessBoard[row][2]
			&& chessBoard[row][0] == 'o') {
			return 'o';
		}
	}
	//检查列
	for (int col = 0; col < MAX_COL; col++) {
		if (chessBoard[0][col] != ' '
			&& chessBoard[0][col] == chessBoard[1][col]
			&& chessBoard[0][col] == chessBoard[2][col]) {
			if (chessBoard[0][col] == 'x') {
				return 'x';
			}
			else if (chessBoard[0][col] == 'o') {
				return 'o';
			}
		}	
	}
	//检查对角线
	for (int row = 0; row < MAX_ROW; row++) {
		if (chessBoard[row][0] != ' '
			&& chessBoard[0][0] == chessBoard[1][1]
			&& chessBoard[0][0] == chessBoard[2][2]) {
			if (chessBoard[0][0] == 'o') {
				return 'o';
			}
			else if (chessBoard[0][0] == 'x') {
				return 'x';
			}
		}
		else if (chessBoard[row][0] != ' '
			&& chessBoard[0][2] == chessBoard[1][1]
			&& chessBoard[0][2] == chessBoard[2][0]) {
				if (chessBoard[1][1] == 'o') {
					return 'o';
				}
				else if (chessBoard[1][1] == 'x') {
					return 'x';
				}
		}
	}
	//检查棋盘还有空否?
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chessBoard[row][col] == ' ') {
				return ' ';
			}
		}
	}
	//和局
	return '*';
	
}

void computerPlayer(char chessBoard[MAX_ROW][MAX_COL]) {
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;


		if (row < 0 || row > MAX_ROW - 1 || col < 0 || col > MAX_COL || chessBoard[row][col] != ' ') {
			continue;
		}
		else {
			chessBoard[row][col] = 'o';
			//printBoard(chessBoard);
			break;
		}
	}
}

void game(char chessBoard[MAX_ROW][MAX_COL]) {
	
	//2. 先打印一下棋盘,(第一次为空棋盘)
		//  X 表示玩家落子
		//  O 表示电脑落子
	printBoard(chessBoard);
	while (1) {
		

		//3. 提示玩家落子
		player(chessBoard);


		//4. 检查游戏是否结束
		char checkReturn = check(chessBoard);
		if (checkReturn == 'x') {
			printf("恭喜你赢了!\n");
			break;
		}
		else if (checkReturn == 'o') {
			printf("你真菜,电脑都下不过\n");
			break;
		}
		else if (checkReturn == '*') {
			printf("你真菜,跟电脑五五开\n");
			break;
		}

		//5.电脑落子
		computerPlayer(chessBoard);

		printBoard(chessBoard);
		//6.检查游戏是否结束
		checkReturn = check(chessBoard);
		if (checkReturn == 'x') {
			printf("恭喜你赢了!\n");
			break;
		}
		else if (checkReturn == 'o') {
			printf("你真菜,电脑都下不过\n");
			break;
		}
		else if (checkReturn == '*') {
			printf("你真菜,跟电脑五五开\n");
			break;
		}
		//7.循环(回到2继续执行)

	}
}



int main(void){
	//种子
	srand((unsigned int)time(NULL));

	//1.表示棋盘,二维数组,char数组
	//	初始情况下,二维数组应全设置为空格
	char chessBoard[MAX_ROW][MAX_COL] = { ' ' };
	memset(chessBoard, ' ', MAX_ROW * MAX_COL);

	int choice = menu();
	if (choice == 1) {
		game(chessBoard);
	}
	else if (choice == 0) {
		printf("GoodBye!\n");
	}
	else {
		printf("您的输入有误!\n");
	}

	system("pause");
	return 0;
}