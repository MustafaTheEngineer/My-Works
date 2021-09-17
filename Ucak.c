/*Bismillahirrahmanirrahim*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 30

struct plane{
	int ident,marker;
	char f_name[MAX];
	char l_name[MAX];
};

void top_menu(void);
void sec_menu(void);
void show_empties(const struct plane *);
void list_empties(const struct plane *);
void alphabetical(const struct plane *,int);
void assign_cust(struct plane *);
void del_assign(struct plane *);
void newlineless(int);
void send_data(const struct plane *);
int get_data(struct plane *);
void err_msg(char *);

static flight,pep;

int main(void){
	
	top_menu();
	
	return 0;
}

void top_menu(void){
	char ch;
	
	do{
		puts("Choose a flight:\n\n");
		printf("a)102  b)311  c)444  d)519  e)exit\n");
		ch =getchar();
		if(ch!='\n')
			newlineless(1);
		system("cls");
	}while(ch < 'a' || ch > 'e');

	switch(ch){
		case 'a':
			flight=102;
			break;
		case 'b':
			flight=311;
			break;
		case 'c':
			flight=444;
			break;
		case 'd':
			flight=519;
			break;
		case 'e':
			exit(EXIT_SUCCESS);
	}
	sec_menu();
}

void sec_menu(void){
	struct plane people[12];
	pep=get_data(people);
	char ch;
	system("cls");
	
	do{
		printf("To choose a function, enter its letter label:\n\n \
		a) Show number of empty seats\n \
		b) Show list of empty seats\n \
		c) Show alphabetical list of seats\n \
		d) Assign a customer to a seat assignment\n \
		e) Delete a seat assignment\n \
		f) Back\n\t\t");
		ch=getchar();
		if(ch != '\n')
			newlineless(1);
		system("cls");
	}while(ch < 'a' || ch > 'f');
		
		switch(ch){
			newlineless(1);
			case 'a':
				show_empties(people);
				break;
			case 'b':
				list_empties(people);
				break;
			case 'c':
				alphabetical(people,pep);
				break;
			case 'd':
				assign_cust(people);
				++pep;
				break;
			case 'e':
				del_assign(people);
				break;
			case 'f':
				system("cls");
				top_menu();
				break;
		}
		system("cls");
}

void show_empties(const struct plane *list){
	int i,k=0;
	
	for(i=0;i<12;++i){
		if(list[i].marker)
			++k;
	}
	printf("The empty seats: %d\n",k);
	getch();
	sec_menu();
}
void list_empties(const struct plane *list){
	int i,k=0;
	printf("The empty seats: \n");
	for(i=0;i<12;++i){
		if(list[i].marker)
			printf("%d ",i+1);
	}
	getch();
	sec_menu();
}
void alphabetical(const struct plane *list,int digit){
	int buffer,number[digit];
	int i,k=0,count=0;
	
	number[0]=0;
	for(i=0;i<12;++i)
		if(list[i].f_name[0] != '\0')
			number[k++] = list[i].ident;
			
	if(number[0]){
		for(i=0;i<digit-1;++i){
			printf("naber");
			for(k=0;k<digit-1;++k){
				if(list[number[k]].f_name[0] > list[number[k+1]].f_name[0]){
					buffer = number[k];
					number[k] = number[k+1];
					number[k+1] = buffer;
				}
			}
		}
		printf("Alphabetical list of seat owners:\n\n");
		for(i=0;i<digit;++i){
			printf("%s %s at seat %d\n",list[number[i]-1].f_name,list[number[i]-1].l_name,number[i]);
		}
		puts("Done.");
	}
	else
		printf("All seats are empty.");

	getch();
	sec_menu();
}
void assign_cust(struct plane *list){
	int seat,buff1,buff2,control=1;
	FILE *file;
	char buffer1[MAX],buffer2[MAX];
	
	printf("Please enter the seat number(1-12): ");
	while(scanf("%d",&seat) != 1 && seat < 1 || seat > 12){
		printf("Error! Wrong entry.\nTry again: ");
		newlineless(0);
	}
	newlineless(0);
	printf("First name of customer: ");
	fgets(list[seat-1].f_name,40,stdin);
	printf("\nLast name of customer: ");
	fgets(list[seat-1].l_name,40,stdin);
	
	*strrchr(list[seat-1].f_name,'\n') ='\0';
	list[seat-1].f_name[0] = toupper(list[seat-1].f_name[0]);
	*strrchr(list[seat-1].l_name,'\n') ='\0';
	list[seat-1].l_name[0] = toupper(list[seat-1].l_name[0]);
	
	if((file=fopen("plane.txt","r")) == NULL)
		err_msg("File couldn't open.");
		
	while(fscanf(file,"%d%d%s%s",&buff1,&buff2,buffer1,buffer2) == 4){
		if(buff1 == flight && buff2 == seat || buff2 != seat && 
		!strcmp(buffer1,list[seat-1].f_name) && !strcmp(buffer2,list[seat-1].l_name)){
			printf("This person has already booked.");
			newlineless(0);
			control=0;
			break;
		}
	}

	if(fclose(file) == EOF)
		err_msg("File couldn't close.");
	if(control){
		list[seat-1].marker=0;
		send_data(&list[seat -1]);
		puts("Done.");
		newlineless(0);
	}
	system("cls");
	sec_menu();	
}
void del_assign(struct plane *list){
	int seat,i;
	
	printf("Please enter the seat number(1-12): ");
	while(scanf("%d",&seat) != 1 && seat < 1 || seat > 12){
		printf("Error! Wrong entry.\nTry again: ");
		newlineless(0);
	}
	for(i=0;i<30;++i){
		list[seat-1].f_name[i] = '\0';
		list[seat-1].l_name[i] = '\0';
	}
	send_data(list);
	puts("Done.");
	getch();
	sec_menu();
}

void send_data(const struct plane *list){
	FILE *file;
	int i;
	if((file = fopen("plane.txt","a")) == NULL)
		err_msg("Error!File couldn't open");
		
	fprintf(file,"%d %d %s %s\n",flight,list[i].ident,list[i].f_name,list[i].l_name);
	
	if(fclose(file) == EOF)
		err_msg("Error!File couldn't close.");
}

int get_data(struct plane *list){
	FILE *file;
	int time,nmb,digit=0,i=0;
	char buffer1[MAX],buffer2[MAX];
	
	for(i=0;i<12;++i){
		list[i].ident = i+1;
		list[i].marker = 1;
		list[i].f_name[0] ='\0';
		list[i].l_name[0] ='\0';
	}
	if((file = fopen("plane.txt","a+")) == NULL)
		err_msg("Error!File couldn't open");
		
	while(fscanf(file,"%d%d%s%s",&time,&nmb,buffer1,buffer2) == 4){
		if(time == flight){
			printf("%d",time);
			list[nmb-1].marker = 0;
			list[nmb-1].ident = nmb;
			strcpy(list[nmb-1].f_name,buffer1);
			strcpy(list[nmb-1].l_name,buffer2);
			++digit;
		}
	}

	if(fclose(file) == EOF)
		err_msg("Error!File couldn't close.");
	return digit;
}

void err_msg(char * msg){
	fprintf(stderr,msg);
	getch();
	exit(EXIT_FAILURE);
}

void newlineless(int i){
	if(i)
		system("cls");
	while(getchar() != '\n')
		continue;
}
/*Elhamdülillah*/
