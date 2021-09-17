#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

typedef struct node{
	char actual;
	char ch[3];
	int line;
	bool closed;
	struct node *next;
	struct node *prev;
}Node;

typedef struct queue{
	Node *head;
	Node *end;
}List;

void Initialize(List *);
bool IsThereSingle(List *,char);
bool AddNode(List *,const char,const int);
void show(List *);
void EmptyList(List *);

int main(void){

	FILE *file;
	List list;
	bool control;
	char *find1="([{",*find2=")]}",ch,filename[30];
	int line = 1;
	Initialize(&list);
	printf("This program finds the missing parenthesis,backets and braces.\n\
Please enter the file name: ");
	fgets(filename,30,stdin);
	filename[strlen(filename)-1]='\0';
	
	if((file=fopen(filename,"rb")) == NULL){
		fprintf(stderr,"Error!File couldn't open.");
		getch();
		exit(EXIT_FAILURE);
	}
	while((ch=getc(file)) != EOF){
		if(strchr(find1,ch) != NULL){
			if(!AddNode(&list,ch,line)) 
				printf("Error!Memory couldn't be allocated.");
		}
		else if(strchr(find2,ch) != NULL){
			if(!IsThereSingle(&list,ch))
				AddNode(&list,ch,line);
		}
		else if(ch == '\n')
			++line;
	}
	
	if(fclose(file) == EOF){
		fprintf(stderr,"Error!File couldn't close.");
		getch();
		exit(EXIT_FAILURE);
	}
	show(&list);
	getch();
	EmptyList(&list);

	return 0;
}

void Initialize(List *list){
	list->head = list->end = NULL;
}

bool IsThereSingle(List *list,char seek){
	Node *scan = list->end;
	Node *copy;
	while(scan != NULL){
		if(strchr(scan->ch,seek) != NULL){
			if(seek != (scan->actual) && !scan->closed){
				scan->closed=true;
				return true;
			}
		}
		scan = scan->prev;
	}
	return false;
}

bool AddNode(List *list,const char add,const int line){
	Node *copy;
	Node *newNode;
	char *find1="()",*find2="[]",*find3="{}";
	newNode = (Node *) malloc(sizeof(Node));
	if(newNode==NULL)
		return false;

	newNode->next=NULL;
	newNode->prev=NULL;
	newNode->line=line;
	newNode->actual=add;
	newNode->closed=false;
	if(strchr(find1,add) != NULL)
		strcpy(newNode->ch,find1);
	else if(strchr(find2,add) != NULL)
		strcpy(newNode->ch,find2);
	else if(strchr(find3,add) != NULL)
		strcpy(newNode->ch,find3);

	if(list->head == NULL){
		list->head = list->end = newNode;
		return true;
	}
	else{
		list->end->next = newNode;
		newNode->prev = list->end;
		list->end = newNode;
		return true;
	}
}

void EmptyList(List *list){
	Node *copy;
	while(list->head != NULL){
		copy = list->head->next;
		free(list->head);
		list->head = copy;
	}
	free(list->end);
}

void show(List *list){
	Node *copy = list->head;
	bool cont=false;
	while(copy != NULL){
		if(!copy->closed){
			printf("Missing character at line %d\
(or near to this line)\n",copy->line);
			cont=true;
		}
		copy = copy->next;
	}
	(!cont) ? printf("No missing character ") : printf("Done ");
}
