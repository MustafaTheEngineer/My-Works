#include <stdio.h>
#include <stdlib.h>

struct node {
	int number;
	struct node *next;
};

int initialize(struct node **);
void printList(struct node *);
struct node* addNode(struct node *,int);
struct node *cut_head_add_to_end(struct node *);
void DeleteList(struct node *);

int main(void){
	struct node *head=NULL;
	
	head = addNode(head,5);
	head = addNode(head,7);
	head = addNode(head,14); 
	
	printList(head);
	
	head = cut_head_add_to_end(head);
	
	printList(head);
	
	DeleteList(head); 
	
	return 0;
}

struct node* addNode(struct node *head,int value){
	struct node *newNode = (struct node *) calloc(1,sizeof(struct node));
	struct node *copy;
	
	newNode->number = value;
	newNode->next = NULL; 
	
	if(head == NULL)
		head = newNode;  
	else{
		copy = head;
		while(copy->next != NULL)
			copy = copy->next;
		copy->next = newNode;
	}
	
	return head;
}



void printList(struct node *head){
	struct node *copy = head;
	
	while(copy != NULL){
		printf("%d ",copy->number);
		copy = copy->next;
	}
	printf("\n");
}



struct node *cut_head_add_to_end(struct node *head){
	struct node *last,*copy,*newHead;
	
	copy = head;
	while(copy->next != NULL)
		copy = copy->next;
	last = copy; 
	newHead = head->next;
	head->next = NULL;
	last->next = head;
	
	return newHead;
}

void DeleteList(struct node *head){
	struct node *previous = head;
	struct node *nextNode = head->next;
	
	while(previous != NULL){
		free(previous);
		previous = nextNode;
		nextNode = nextNode->next;
	}
}

