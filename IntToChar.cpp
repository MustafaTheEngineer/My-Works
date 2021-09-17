#include <stdio.h> 

int main() 
{ 

    int number=345;
    char *p,dizi[10];
    
    sprintf(dizi,"%d",number);
    p=dizi;
    printf("%s",dizi);
    
    return 0; 
} 
