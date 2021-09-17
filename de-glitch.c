#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define ROW 30
#define COL 20 

int main(void){
	
	FILE *file;
	int sum=0,divide=0,i,k,differ=0;
	int array[COL][ROW];
	if((file=fopen("image.txt","r")) == NULL){
		fprintf(stderr,"Error!File couldn't open.");
		exit(EXIT_FAILURE);
	}
	for(i=0 ; i < COL ; ++i){
		for(k=0 ; k < ROW ; ++k){
			fscanf(file,"%d",&array[i][k]);
		}
	}
	for(i=0 ; i < COL; ++i){
		for(k=0 ; k < ROW ; ++k){
			fprintf(stdout," %d",array[i][k]);
		}
		putchar('\n');
	}
	printf("\n\n");
	
	for(i=0 ; i < COL ; ++i){
		for(k=0 ; k < ROW ; ++k){
			if((k-1) >= 0){
				if((array[i][k] - array[i][k-1]) != 0)
					++differ;
				sum+=array[i][k-1];
				++divide;
			}
			if((k+1) <= (ROW-1)){
				if((array[i][k] - array[i][k+1]) != 0)
					++differ;
				sum+=array[i][k+1];
				++divide;
			}
			if((i-1) >= 0){
				if((array[i][k] - array[i-1][k]) != 0)
					++differ;
				sum+=array[i-1][k];
				++divide;
			}
			if((i+1) <= (COL-1)){
				if((array[i][k] - array[i+1][k]) != 0)
					++differ;
				sum+=array[i+1][k];
				++divide;
			}
			if(differ > 1){
				array[i][k]=(int) round((sum/divide));
			}
			sum=differ=divide=0;
		}
	}
	
	for(i=0 ; i < COL; ++i){
		for(k=0 ; k < ROW ; ++k){
			fprintf(stdout," %d",array[i][k]);
		}
		putchar('\n');
	}
	
	
	if(fclose(file) == EOF){
		fprintf(stderr,"Error!File couldn't close.");
		exit(EXIT_FAILURE);
	}
	
	return 0;
}
