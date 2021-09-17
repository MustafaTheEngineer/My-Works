#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int main(void){
	
	char piece1[] = "<!DOCTYPE html>\n<html lang=\"en\">\n\n<head>\n\
    <meta charset=\"UTF-8\">\n	<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n \
   <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n \
   <title>";
	char piece2[] = "</title>\n</head>\n\n<body>\n	<script src=\"";
	char piece3[] = "\" type=\"text/javascript\"></script>\
	\n</body>\n\n</html>";
    
	int i;
	char fileName[50],html[130]="..\\..\\JavaScript\\EXERCISES\\";
	char js[130]="..\\..\\JavaScript\\EXERCISES\\";
	char mkdir[135] = "mkdir ";
	FILE *file1,*file2;
	
	printf("File name: ");
	fgets(fileName,50,stdin);
	
	while(1){
		if(fileName[0] == '\n'){ 
			printf("\nFile name: ");
			fgets(fileName,100,stdin);
		}else
			break;
	} 
	*strchr(fileName,'\n') = '\0';
	fileName[0] = toupper(fileName[0]);

	strcat(html,fileName);
	
	strcat(mkdir,"\"");
	strcat(mkdir,html);
	strcat(mkdir,"\"");
	
	strcat(html,"\\");
	strcat(html,fileName);
		
	strcat(js,fileName);
	strcat(js,"\\");
	strcat(js,fileName); 
	
	if(system(mkdir) != 1){
		if(strchr(fileName,'.') == NULL){
			strcat(html,".html");
			strcat(js,".js");
		}
		
		printf("%s\n",html);
	
		if((file1 = fopen(html,"w")) == NULL){
			fprintf(stderr,"Error while creating html file.");
		} 
	
		if((file2 = fopen(js,"w")) == NULL){
			fprintf(stderr,"Error while creating js file.");
		}
	
		fprintf(file1,piece1);
		fprintf(file1,fileName);
		fprintf(file1,piece2);
		fprintf(file1,strrchr(js,'\\') + 1);
		fprintf(file1,piece3);
	
		if(fclose(file1) == EOF){
			fprintf(stderr,"Error while closing html file.");
		}
		if(fclose(file2) == EOF){
			fprintf(stderr,"Error while closing js file.");
		}
	}
	printf("Done.");
	getch();
	
	return 0;
}
