/*Bismillahirrahmanirrahim*/
#include <stdio.h>
#define MAX 100
#define KEY 4

int main(void){
	char key1[]={'a',-115,'o','u'},key2[]={'e','i',-108,-127};
	char entry[MAX];
	int i,k,control=1,count=0;
	
	printf("Enter a sentence(max %d character.)\n",MAX);
	gets(entry);
	
	for(i=0;entry[i]!='\0';++i){
		if(control){
			for(k=0;k<KEY;++k){
				if(entry[i] == key1[k]){
					(control==3) ? (control=0) : (control=2);				
					break;
				}
				else if(entry[i]== key2[k]){
					(control==2) ? (control=0) : (control=3);
					break;
				}
			}
		}
		if(entry[i]==' ' || entry[i+1]=='\0'){
			if(control==2 || control==3)
				++count;
			control=1;
		}	
	}
	printf("There is(are) %d word that fits great vowel harmony",count);
	
	return 0;
}

/*Elhamdülillah*/


