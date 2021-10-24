#include <stdio.h>
#include <stdlib.h>

struct stack{
	struct node *top;
	int cnt;
};

struct node{
	int number;
	struct node *next;
};


void initialize(struct stack *stk);
void push(struct stack *stk,int value);
void pop(struct stack *stk);
void freeRAM(struct stack *stk);

int main(void){
	struct stack Stack;
	initialize(&Stack);
	
	push(&Stack,5);
	push(&Stack,7);
	push(&Stack,9);
	pop(&Stack);
	pop(&Stack);
	
	printf("%d\n",Stack.top->number);
	printf("%d\n",Stack.top->next->number);
	printf("%d\n",Stack.top->next->next->number);
	
	freeRAM(&Stack);
	
	return 0;
}

void initialize(struct stack *stk){
	stk->cnt = 0;
	stk->top = NULL;
}

void push(struct stack *stk,int value){
	struct node *add = (struct node *) calloc(1,sizeof(struct node));
	add->number = value;
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

void freeRAM(struct stack *stk){
	struct node *temp =stk->top;
	struct node *temp2;
	
	while(temp != NULL){
		temp2 = temp;
		temp = temp->next;
		free(temp2);
	}
	
}






