#include <stdio.h>
#include <math.h>

void Armstrong(void);

int main(){
	
	Armstrong();
	
	
}

void Armstrong(void){
	int entry1,transfer,counter=0,sum=0;
	printf("The Program That Show Whether A Number Typed is An Armstrong Number or Not\n");
	printf("Please Type A Number: ");
	scanf("%d",&entry1);
	transfer=entry1;
	while(entry1!=0){
		entry1/=10;
		++counter;
		
	}
	entry1=transfer;
	while(transfer!=0){
		sum+=pow(transfer%10,counter);
		transfer/=10;
	}
	if(sum==entry1){
		printf("%d is an Armstrong number.",entry1);
	}
	else{
		printf("%d is not an Armstrong number.",entry1);
	}
}
