#include <stdio.h>

int main(){
	
	int entry1,gosterilecek,sayac1,ust=1,i;
	printf("Type a number");
	printf("Number: ");
	scanf("%d",&entry1);
	printf("\n");
	gosterilecek=entry1;
	while(entry1!=0){
		entry1/=10;
		++sayac1;
	}
	for(i=1;i<sayac1-1;++i){
		ust*=10;
	}
	while(gosterilecek!=0){
		printf("%d",(gosterilecek/ust)*ust);
		printf("\n");
		gosterilecek%=ust;
		ust/=10;
		
	}
	return 0;
	
}
