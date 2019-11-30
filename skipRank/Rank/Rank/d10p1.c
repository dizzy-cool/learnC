#include <stdio.h>
#include <stdlib.h>

#define PEOPLE_NUM 5

void skipRank(void) {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= PEOPLE_NUM; a++) {
		for (b = 1; b <= PEOPLE_NUM; b++) {
			for (c = 1; c <= PEOPLE_NUM; c++){
				for (d = 1; d <= PEOPLE_NUM; d++) {
					for (e = 1; e <= PEOPLE_NUM; e++) {
						if ((a == 3 && b != 2) || (a != 3 && b == 2)) {
							if ((b == 2 && e != 4) || (b != 2 && e == 4)) {
								if ((c == 1 && d != 2) || (c != 1 && d == 2)) {
									if ((d == 3 && c != 5) || (d != 3 && c == 5)) {
										if ((a == 1 && e != 4) || (a != 1 && e == 4)) {
											//筛选唯一符合的顺序
											if (a != b && a != c && a != d && a != e
												&& b != c && b != d && b != e
												&& c != d && c != e
												&& d != e) {
												printf("名次排名如下: a = %d ,b = %d ,c = %d ,d = %d , e = %d\n", a, b, c, d, e);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

int d10p1(void){
	
	skipRank();
	system("pause");
	return 0;
}