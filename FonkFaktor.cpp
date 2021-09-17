#include <stdio.h>

int FactorialCalculator(int entry1){
	if(entry1!=1){
		return entry1*FactorialCalculator(entry1-1);
	}
	else{
		return entry1;
	}
	
	}


int main(){
	unsigned int factorial;
	printf("Type a positive integer to find its factorial: ");
	scanf("%d",&factorial);
	int result=FactorialCalculator(factorial);
	printf("Factorial of %d: %d",factorial,result);
	
	return 0;
}
