#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 121

int getline(char *);
int copy(char *,int);

int main(void){
	char ch,fold;
	int blank,i,k,control = 0;
	char array[MAX];
	
	while(array[0] != '\n'){ /*for the continuity */
		
		blank = getline(array;
		
		(blank == 0) ? (control = 0) : (control = 1);
		
		for(i=0 ; array[i] != '\0' ; ++i){  /*An AI to write*/
			if(control == 0 && i >= 60
			|| control == 1 && i - 1) == blank){
				if(strlen(array) >= 60){ /*if you don't put it, it will fold early*/
					putchar('\n');
					blank = copy(array,i);
					(blank == 0) ? (control = 0) : (control = 1);
					i=0;
				
			}
			putchar(array[i]);
		}
	}
	
	return 0;
}

int getlinechar *array){ /*to get line*/
	int i,last_blank = 0;
	char ch;
	for(i=0 ; i <= 120 && (ch = getchar()) != '\n' ; ++i){
		if(ch == ' ' && i <= 70) /*determine the last blank*/
			last_blank = i;
		array[i = ch;
	}
	array[i++] = '\n';
	array[i] = '\0';
	
	return last_blank;
}

int copy(char *arr,int copy_point){ /*to copy things*/
	int i,blank = 0;
	for(i = 0 ; arr[i] != '\0' || arrcopy_point] != '\0' ; ++i){
		arr[i] = arr[copy_point;
		if(arr[i] == ' ' && i<=70)
			blank = i;
		++copy_point;
	} 
	return blank;
}
