#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *solution(int n);

int main(void){
	
	printf("%s",solution(4));
	
	return 0;
}

char *solution(int n) {
  int i=0;
  static char result[20];
  
  while(i++ < (n/1000))
    strcat(result,"M");
  i=0;
  n%=1000;
  if(n >= 900){
    strcat(result,"CM");
    n%=100;
  }
  else if(n >= 400 && n < 500){
    strcat(result,"CD");
    n%=100;
  }
  else{
    while(i++ < (n/500))
      strcat(result,"D");
    i=0;
    n%=500;
    while(i++ < (n/100))
      strcat(result,"C");
    i=0;
    n%=100;
  }
  if(n >= 90){
    strcat(result,"XC");
    n%=10;
  }
  else if(n >= 40 && n < 50){
    strcat(result,"XL");
    n%=10;
  }
  else{
    while(i++ < (n/50))
      strcat(result,"L");
    i=0;
    n%=50;
    while(i < (n/10))
      strcat(result,"X");
    i=0;
    n%=10;
  }
  if(n==9)
    strcat(result,"IX");
  else if(n==4)
    strcat(result,"IV");
  else{
    while(i++ < (n/5))
      strcat(result,"V");
    i=0;
    n%=5;
    while(i++ < (n/1))
      strcat(result,"I");
  }
  
  return result;
}
