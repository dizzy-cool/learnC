#include <stdio.h>
#include <stdlib.h>

/****************************************
**�� �� ��: void printBinary(int val2) 
**��    ��: ��ӡ�������� 
**˵    ��: �� 
**��	��:	val2 ��int���� 
******************************************/
void printBinary(int val2){
	int k = 0;
	int i = 0;
	unsigned char *p = (unsigned char*) & val2 + 3; // �ӵ�λ����λ,�Ͷ��ֽڼ����
	
	for (k = 0; k <= 3; k++){
		int val2 = *(p-k);
		for(i = 7; i >= 0; i--){
			if (val2 & (1 << i)){
				printf("1");
			}
			else{
				printf("0");
			}
		} 
		printf(" ");		 
	}  
}

int main(){
	printBinary(-11);
	system("pause");
	return 0; 
}
