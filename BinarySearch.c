/*Bismillahirrahmanirrahim*/
#include <stdio.h>
#include <stdbool.h> 
#define MAX 65535

short int BinSearch(int [],int,int);

int main(void){
	int items[MAX];
	int i;
	for(i=0; i<MAX; ++i)
		items[i] = i;
	printf("\n%d",BinSearch(items,MAX,23935));

	return 0;
}

short int BinSearch(int array[],int max,int seek){
	int middle,sit=0,turn=2,count=1,i,narrow;
	
	while(turn < max){
		++count;
		turn *= 2;
	}
	printf("%d\n",count);
	((max % 2) == 1) ? (narrow = ( (max + 1) / 2) - 1) : (narrow = (max / 2) - 1);
	middle = narrow;
	
	for(i = 0 ; i < count ; ++i){
		printf("middle : %d value: %d\n",middle,array[middle]);
		((narrow % 2) == 1) ? (narrow = (narrow + 1) / 2) : (narrow /= 2);
		
		if(seek == array[middle]){
			sit = 1;
			break;
		}
		else if(seek < array[middle])
			middle -= narrow;
		else
			middle += narrow;
	}
	
	return sit;
}

/*Elhamdülillah*/
