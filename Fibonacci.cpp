#include <stdio.h>
#include <ctype.h>

int main(){
	int entry1,entry2=0,entry3=1,entry4;
	while(entry1<=100){
		entry1=entry2 + entry3;
		entry3=entry2;
		printf("%d,",entry1);
		if(entry1%10==0 && entry1!=0){
			printf("\n");
		}
		entry2=entry1;
		
		
	}
	return 0;
}

