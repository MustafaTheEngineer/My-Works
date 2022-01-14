#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

typedef struct {
	int cnt;
	Node *front;
	Node *rear;
}Queue;

Queue *init(void);
void enqueue(Queue *,int data);
int dequeue(Queue *);
void show(Queue *queue);

int main(void){
	Queue *queue;
	
	queue = init();
	
	enqueue(queue,2);
	enqueue(queue,3);
	enqueue(queue,4);
	enqueue(queue,5);
	
	dequeue(queue);
	
	show(queue);
	
	return 0;
}

Queue *init(){
	Queue *queue = (Queue *) calloc(1,sizeof(Queue));
	
	queue->front = NULL;
	queue->rear = NULL;
	queue->cnt = 0;
	
	return queue;
}

void enqueue(Queue *queue,int data){
	Node *newNode = (Node *) calloc(1,sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	
	if(queue->cnt == 0){
		queue->front = newNode;
		queue->rear = newNode;
	}else{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
	++queue->cnt;
}

int dequeue(Queue *queue){
	if(queue->cnt == 0)
		printf("Queue is empty.\n");
	else{
		Node *temp = queue->front;
		int ret = temp->data;
		queue->front = temp->next;
		free(temp);
		
		--queue->cnt;
		
		return ret;
	}
	
	return -1;
}

void show(Queue *queue){
	Node *temp = queue->front;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
