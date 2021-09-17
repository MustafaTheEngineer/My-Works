/*This program deletes comments from a C program*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	FILE *file;
	char ch[2];
	int bol = 0;
	
	if((file = fopen("Deneme.c","r")) == NULL){
		fprintf(stderr,"Error!File couldn't open");
		exit(1);
	}
	while((ch[0] = getc(file)) != EOF){
		if(ch[0] == '/'){
			ch[1] = getc(file);
			if(ch[1] == '*')
				++bol;
			else{
				putc(ch[0],stdout);
				putc(ch[1],stdout);
			}
		}
		else if(ch[0] == '*'){
			ch[1] = getc(file);
			if(ch[1] == '/')
				++bol;
			else{
				putc(ch[0],stdout);
				putc(ch[1],stdout);
			}
		}
		else{
			if(bol != 1)
				putc(ch[0],stdout);	
			if(bol == 2)
				bol = 0;
		}
	}
	
	if(fclose(file) == EOF){
		fprintf(stderr,"Error!File couldn't open");
		exit(1);
	}
	
	return 0;
}

