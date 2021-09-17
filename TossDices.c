#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void toss_dice(int,int,int);
void elek(void);
int control(int,short int,const char*);

int main(void){
	while(1){
		int sets,sides,dice;
		char n;
    	puts("Enter the number of sets; enter q to stop : ");
    	sets=control(sets,1,"Sides must be least 2\n");
    	printf("How many sides?: ");
    	sides=control(sides,2,"Sides must be least 1\n");
    	printf("How many dice?: ");
    	dice=control(dice,1,"Dices must be least 1\n");
    	toss_dice(sets,sides,dice);
	}
    return 0;
}

void toss_dice(int sets,int sides,int dice){
	int i,k,sum;
	srand((unsigned int) time(0));
	for(i = 0 ; i < sets ; ++i){
		for(k = 0 ; k < dice ; ++k){
			sum+=(rand()%sides + 1);
		}
	printf(" %d ",sum);
	sum=0;
	}
	printf("\n\n");	    
}

int control(int controlled,short int limit,const char *message){
	char quit;
	
    while(1){
    	while(scanf("%d",&controlled) != 1){
	    	if(scanf("%c",&quit) == 1 && quit == 'q' || quit == 'Q')
	    	    exit(EXIT_SUCCESS);
	    	printf("\nPlease enter a valid number.\n");
    		elek();
    	}
    	if(controlled < limit){
	    	puts(message);
	    	continue;
		}
		else 
			break;
	}
	
	return controlled;   	
}

void elek(void){
	while(getchar() != '\n')
    	continue;
}

