#include <stdio.h>
#define SIZE 8
int main(void)
{
char ch;
int i,k,m;

printf("Type a character: ");
scanf("%c",&ch);

for(i=0;i<=4;++i){
	for(k=4;k>=i+1;--k){
		printf(" ");
	}
	for(m=0;m<=i;++m){
		printf("%c",ch+m);
	}
	for(m=0;m<i;++m){
		printf("%c",ch+i-m-1);
	}
		
	printf("\n");
}

return 0;
}
