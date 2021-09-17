#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void BinarySet(int);

int main(void){
	BinarySet(128);
	BinarySet(129);
	BinarySet(135);
	BinarySet(141);
	BinarySet(148);
	BinarySet(152);
	BinarySet(153);
	BinarySet(154);
	BinarySet(158);
	BinarySet(159);
	BinarySet(166);
	BinarySet(167);
	BinarySet('Ç');
	printf("%d",'Ç');
	
	return 0;
}

void BinarySet(int value){
	int i;
	unsigned char binary[sizeof(value)*8 + sizeof(value) + 1];
	binary[sizeof(binary) - 1] = '\0';
	
	for(i = sizeof(binary) - 2 ; i >= 0 ; --i,value>>=1){
		if(i % 9 == 0)
			binary[i] = ' ';
		else
			binary[i] = '0' + (01 & value);
	}
	
	puts(binary);
}
