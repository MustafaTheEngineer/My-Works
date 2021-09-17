#include <stdio.h>

int main(){
	
	int girdi,sayi1;
	printf("Bir tamsayi girin: ");
	scanf("%d",&girdi);
	
	for(sayi1=1;girdi>0;--girdi){
		sayi1*=girdi;
	}
	printf("Girdiginiz sayinin faktoriyeli: %d",sayi1);
	
	return 0;
}
