#include <stdio.h>

int main(void){
	
	char ch;
	int word_length = 0,counter,counter2,most = 0;
	int data[11;
	
	for(counter = 0 ; counter < 11 ; ++counter)
		data[counter] = 0;
	
	while((ch = getchar()) != EOF){
		if(ch != ' ' && ch != '\n')
			++word_length;
		else{
			if(word_length <= 10){
				++data[word_length - 1];
				word_length = 0;
			}
			else
				++data[10];
		}
	}
	
	for(counter = 0 ; counter < 11 ; ++counter)
		if(data[counter] > most)
			most = data[counter];

	for(counter = 0 ; counter < 11 , most >= 1; ++counter){
		for(counter2 = 0 ; counter2 < 11 ; ++counter2){
			printf("   ");
			if(data[counter2] >= most)
				putchar('|');
			else
				putchar(' ');
		}
		putchar('\n');
		--most;
	}
	for(counter = 0 ; counter < 11 ; ++counter){
		if(counter == 0)
			printf("  ");
		else
			printf(" ");
		printf("---");
	}
	putchar('\n');
	
	for(counter = 0 ; counter < 11 ; ++counter){
		if(counter == 0)
			printf("  ");
		else
			printf("   ");
		if(counter == 10)
			printf("%d+",counter +1);
		else
			printf("%d",counter +1);
	}
	
	return 0;
}


