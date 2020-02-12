#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define MAX_ROW 3
#define MAX_COL 3


int menu() {
	printf("============================\n");
	printf("��ӭ������������Ϸ\n");
	printf("��ʼ��Ϸ: 1\n");
	printf("������Ϸ: 0\n");
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
	printf("�ֵ��������:");
	while (1) {
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);

		if (row < 0 || row > MAX_ROW - 1 
			|| col < 0 || col > MAX_COL - 1 
			|| chessBoard[row][col] == 'x' 
			|| chessBoard[row][col] == 'o') {
			printf("������������!����������:\n");
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
	//�����
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
	//�����
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
	//���Խ���
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
	//������̻��пշ�?
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chessBoard[row][col] == ' ') {
				return ' ';
			}
		}
	}
	//�;�
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
	
	//2. �ȴ�ӡһ������,(��һ��Ϊ������)
		//  X ��ʾ�������
		//  O ��ʾ��������
	printBoard(chessBoard);
	while (1) {
		

		//3. ��ʾ�������
		player(chessBoard);


		//4. �����Ϸ�Ƿ����
		char checkReturn = check(chessBoard);
		if (checkReturn == 'x') {
			printf("��ϲ��Ӯ��!\n");
			break;
		}
		else if (checkReturn == 'o') {
			printf("�����,���Զ��²���\n");
			break;
		}
		else if (checkReturn == '*') {
			printf("�����,���������忪\n");
			break;
		}

		//5.��������
		computerPlayer(chessBoard);

		printBoard(chessBoard);
		//6.�����Ϸ�Ƿ����
		checkReturn = check(chessBoard);
		if (checkReturn == 'x') {
			printf("��ϲ��Ӯ��!\n");
			break;
		}
		else if (checkReturn == 'o') {
			printf("�����,���Զ��²���\n");
			break;
		}
		else if (checkReturn == '*') {
			printf("�����,���������忪\n");
			break;
		}
		//7.ѭ��(�ص�2����ִ��)

	}
}



int main(void){
	//����
	srand((unsigned int)time(NULL));

	//1.��ʾ����,��ά����,char����
	//	��ʼ�����,��ά����Ӧȫ����Ϊ�ո�
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
		printf("������������!\n");
	}

	system("pause");
	return 0;
}