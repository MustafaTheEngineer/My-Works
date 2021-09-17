// An example of implicit conversion 
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main() 
{ 
    long l;
    char k[3];
    strcpy(k,"345");
    l=atol(k);
    printf("%s",k);
    return 0; 
} 
