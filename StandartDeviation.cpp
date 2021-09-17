#include <stdio.h>
#include <math.h>

float Average(float array[],int count){
	int counter;
	float sum=0;
	for(counter=0;counter<count;++counter){
		sum+=array[counter];
	}
	sum/=counter;
    return sum;
}

float Deviation(float array[],float average,int counter){
	float sum=0;
	int counter1=0;
	while(counter1<counter){
		sum+=pow(array[counter1]-average,2);
		++counter1;
	}
	sum/=counter-1;
	sum=pow(sum,0.5);
	
	return sum;
}

    int main(){
    	int counter1=0,entry1;
    	char calculate;
    	printf("The program that calculate standart deviation(Type max 100 number)\n\n");
    	float array1[100];
    	while(counter1!=100){
    	printf("Type an integer(c to calculate): ");
    	scanf("%f",&array1[counter1]);
    	scanf("%c",&calculate);
    	if(calculate=='c')
    	    break;
    	++counter1;
    }
    float average=Average(array1,counter1);
    float result=Deviation(array1,average,counter1);
    
    printf("%.4f",result);
    

    return 0;
}


