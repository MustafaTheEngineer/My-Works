#include <stdio.h>

int main(void){
	int entry1;
	printf("The Program That Show Whether A Number Prime Number or Not\n");
	printf("Please type a number: ");
	scanf("%d",&entry1);
	if(entry1%2==0 || entry1%3==0 || entry1%4==0 || entry1%5==0 || entry1%6==0 || entry1%7==0 ||entry1%8==0 ||entry1%9==0){
		printf("\nThe number is not a prime number.");
	}
	else{
		printf("The number is a prime number.");
	}
	return 0;
}
