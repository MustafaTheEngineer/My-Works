#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node Node;

void initializeList(Node **);
Node *addNode(Node *,int);
void freeList(Node *);
void printList(Node *);

int main(void){
	Node *head;
	
	initializeList(&head);
	
	head = addNode(head,5);
	head = addNode(head,10);
	head = addNode(head,25);
	
	printList(head);
	
	freeList(head);
	
	
	return 0;
}

void initializeList(Node **head){
	*head = NULL;
}

Node *addNode(Node *head,int data){
	Node *newNode = (Node *) malloc(sizeof(Node));
	Node *copy;
	
	newNode->data = data;
	newNode->next = NULL;
	
	if(head == NULL){
		head = newNode;
		newNode->prev = NULL;
	}
	else{
		copy = head;
		while(copy->next != NULL)
			copy = copy->next;
		copy->next = newNode;
		
		newNode->prev = copy;
	}
	
	return head;
}

void freeList(Node *head){
	Node *temp=head;
	Node *nextNode = head->next;
	
	while(nextNode != NULL){
		free(temp);
		
		temp = nextNode;
		nextNode = nextNode->next;
	}
	
}

void printList(Node *head){
	
	Node *copy=head;
	while(copy != NULL){
		printf("%d ",copy->data);
		copy = copy->next;
	}
}
