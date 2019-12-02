#include <stdio.h>
#include <stdlib.h>

/****************************************
**函 数 名: void printBinary(int val2) 
**功    能: 打印二进制数 
**说    明: 无 
**参	数:	val2 是int型数 
******************************************/
void printBinary(int val2){
	int k = 0;
	int i = 0;
	unsigned char *p = (unsigned char*) & val2 + 3; // 从低位到高位,低端字节计算机
	
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
