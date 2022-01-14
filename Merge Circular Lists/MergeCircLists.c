#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
	struct node *previous;
}Node;

Node *createList(void);
Node *addNode(Node *,int);
Node *merge(Node *,Node *);
void printList(Node *);
void freeList(Node *);

int main(void){
	
	Node *list1;
	Node *list2;
	
	list1 = createList();
	list2 = createList();
	
	list1 = addNode(list1,1);
	list1 = addNode(list1,2);
	list1 = addNode(list1,3);
	list1 = addNode(list1,4);
	list1 = addNode(list1,5);
	
	list2 = addNode(list2,6);
	list2 = addNode(list2,7);
	list2 = addNode(list2,8);
	list2 = addNode(list2,9);
	list2 = addNode(list2,10);
	
	printList(list1);
	printList(list2);
	
	list1 = merge(list1,list2);
	
	printList(list1);
	
	freeList(list1);
	
	return 0;
}

Node *createList(void){
	return NULL;
}

Node *addNode(Node *head,int newData){
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->data = newData;
	
	if(head == NULL){
		head = newNode;
		head->next = head;
		head->previous = head;
	}
	else{
		Node *temp = head;
		do{
			temp = temp->next;
		}while(temp->next != head);
		temp->next = newNode;
		newNode->next = head;
	}
	return head;
}

Node *merge(Node *circularHead,Node *circularTail){
	Node *tempHead = circularHead;
	Node *tempTail = circularTail;
	
	do{
		tempHead = tempHead->next;
	}while(tempHead->next != circularHead);
	
	do{
		tempTail = tempTail->next;
	}while(tempTail->next!= circularTail);
	
	tempHead->next = circularTail;
	tempTail->next = circularHead;
	
	return circularHead;
}

void freeList(Node *head){
	Node *temp1=head->next;
	Node *temp2 = temp1->next;
	
	while(temp2->next != head){
		free(temp1);
		temp1 = temp2;
		temp2 = temp2->next;
	}
	free(temp2->next);
	free(temp2);
}

void printList(Node *head){
	Node *temp = head;
	
	if(head != NULL){
		do{
			printf("%d ",temp->data);
			temp = temp->next;
		}while(temp->next != head);
		printf("%d\n",temp->data);
	}
}
