#include <stdio.h>
#include <stdlib.h>

struct StudentInfo{
	char Name[50],MiddleName[50];
	char Surname[50];
	int Age;
}*ptr;

int main()
{
	int counter1;
	int StudentNumber;
	printf("How many students will you save?: ");
	scanf("%d",&StudentNumber);
	ptr=(struct StudentInfo*) malloc(StudentNumber * sizeof(struct StudentInfo));
	for(counter1=0;counter1<StudentNumber;++counter1){
		printf("------------------------------");
		printf("\nFirst Name: ");
		scanf("%s",&(ptr+counter1)->Name);
		printf("Last Name: ");
		scanf("%s",&(ptr+counter1)->Surname);
		printf("Age: ");
		scanf("%d",&(ptr+counter1)->Age);
	}
	printf("\nThe List of Students\n");
	for(counter1=0;counter1<StudentNumber;++counter1){
		printf("-------------------------------\n");
		printf("Name: %s %s\n",(ptr+counter1)->Name,(ptr+counter1)->MiddleName);
		printf("Surname: %s \n",(ptr+counter1)->Surname);
		printf("Age: %d \n",(ptr+counter1)->Age);
	}
	

   return 0;
}
