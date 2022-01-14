#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

typedef struct {
	Node *top;
	int cnt;
}Stack;

Stack *initStack(void);
void push(Stack *,int data);
void show(Stack *);
int pop(Stack *);

int main(void){
	Stack *stack = initStack();
	
	push(stack,5);
	push(stack,6);
	push(stack,7);
	
	pop(stack);
	
	show(stack);
	
	return 0;
}

Stack *initStack(){
	Stack *stack = (Stack *) calloc(1,sizeof(Stack));
	stack->cnt = 0;
	stack->top = NULL;
	
	return stack;
}

void push(Stack *stack,int data){
	Node *newNode = (Node *) calloc(1,sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	
	if(stack->cnt == 0){
		newNode->next = NULL;
		stack->top = newNode;
		
	}else{
		newNode->next = stack->top;
		stack->top = newNode;
	}
	++(stack->cnt);
}

int pop(Stack *stack){
	if(stack->cnt == 0){
		printf("Stack is empty.");
		return;
	}
	Node *temp = stack->top->next;
	int x = stack->top->data;
	free(stack->top);
	stack->top = temp;
	--stack->cnt;
	
	return x;
}

void show(Stack *stack){
	Node *temp = stack->top;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
		
}
