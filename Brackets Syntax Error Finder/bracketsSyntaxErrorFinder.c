#include <stdio.h>
#include <stdlib.h>

struct stack{
	struct node *top;
	int cnt;
};

struct node{
	char ch;
	int line;
	struct node *next;
};


void initialize(struct stack *);
void search(struct stack *,char,char,int);
void push(struct stack *,char,int);
void pop(struct stack *);
void show(struct stack *);
void freeRAM(struct stack *);

int main(void){
	struct stack Stack;
	FILE *file;
	char ch;
	char brackets[] = "()[]{}";
	int i,line=1;
	
	initialize(&Stack);
	
	if((file = fopen("../ASCII.c","r")) == NULL){
		printf("ERROR! File couldn't be found.");
	}
	
	while((ch = getc(file)) != EOF){
		if(ch == '\n')
			++line;
		for(i = 0 ; i < 6 ; ++i){
			if(ch == brackets[i]){
				if(i % 2 == 0)
					search(&Stack,brackets[i],brackets[i+1],line);
				else
					search(&Stack,brackets[i],brackets[i-1],line);
					
				break;
			}
		}
	}
	
	show(&Stack);
	
	if(fclose(file) == EOF){
		printf("ERROR! File couldn't be closed properly.");
	}
	
	freeRAM(&Stack);
	
	return 0;
}

void initialize(struct stack *stk){
	stk->cnt = 0;
	stk->top = NULL;
}

void search(struct stack *stk,char newBr,char isThere,int line){
	int control = 0;
	if(stk->top == NULL){
		push(stk,newBr,line);
	}
	else if(stk->top->ch == isThere)
		pop(stk);
	else{
		struct node *prev = stk->top;
		struct node *temp = stk->top->next;
		while(temp != NULL){
			if(temp->ch == isThere){
				control = 1;
				prev->next = temp->next;
				free(temp);
				break;
			}
			prev = temp;
			temp = temp->next;
		}
		if(!control)
			push(stk,newBr,line);
	}
}

void push(struct stack *stk,char value,int line){
	struct node *add = (struct node *) calloc(1,sizeof(struct node));
	add->ch = value;
	add->line = line;
	add->next = NULL;
	
	if(stk->cnt == 0){
		stk->top = add;
		stk->top->next = NULL;
	}
	else{
		add->next = stk->top;
		stk->top = add;
	}
	++stk->cnt;
}

void pop(struct stack *stk){
	struct node *temp;
	if(stk->cnt <= 0)
		printf("Stack is empty");
	else{
		temp = stk->top->next;
		free(stk->top);
		stk->top = temp;
		--stk->cnt;
	}
}

void show(struct stack *stk){
	struct node *temp = stk->top;
	while(temp != NULL){
		printf("Missing %c - line %d\n",temp->ch,temp->line);
		temp = temp->next; 
	}
}

void freeRAM(struct stack *stk){
	struct node *temp =stk->top;
	struct node *temp2;
	
	while(temp != NULL){
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
	
}






