#include <stdio.h>
#include <stdlib.h>

#define MAX_ROW 10
#define MAX_COL 10

void triangle(void) {
	int pascalTriangle[MAX_ROW][MAX_COL] = { 0 };
	pascalTriangle[0][0] = 1;

	for (int row = 1; row < MAX_ROW; row++) {
		pascalTriangle[row][0] = 1;
		for (int col = 1; col < MAX_COL; col++) {
			pascalTriangle[row][col] = pascalTriangle[row - 1][col - 1] + pascalTriangle[row - 1][col];
		}
	}
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (pascalTriangle[row][col] != 0) {
				printf("%d ", pascalTriangle[row][col]);
			}
		}
		printf("\n");
	}
}

int main(void){
	
	triangle();
	system("pause");
	return 0;
}