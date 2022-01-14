#include <stdio.h>
#include <stdlib.h>
#define SIZE 11

typedef struct priorityQueue{
	int array[SIZE];
	int index;
}pQ;

pQ *init(void);
void insertToMax(pQ *,int);
int deleteMax(pQ *);
void swap(int *,int *);
void show(pQ *);

int main(void){
	pQ *list = init();
	
	insertToMax(list,3);
	show(list);
	
	insertToMax(list,6);
	show(list);
	
	insertToMax(list,9);
	show(list);
	
	insertToMax(list,7);
	show(list);
	
	deleteMax(list);
	show(list);
	
	return 0;
}

pQ *init(){
	pQ *newQ = (pQ *) calloc(1,sizeof(pQ));
	newQ->index = 1;
	int i;
	for(i=1;i<SIZE;++i)
		newQ->array[i] = 0;
	
	return newQ;
}

void insertToMax(pQ *list,int data){
	if(list->index == SIZE)
		printf("Heap is full");
	else{
		int index = list->index;
		list->array[index] = data;
		while(index != 1 && 
		list->array[index / 2] < list->array[index]){
			swap(&list->array[index/2],&list->array[index]);
			index /= 2;
		}
		
		++list->index;
	}
}

int deleteMax(pQ *list){
	int max = 0;
	if(list->index == 1)
		printf("Heap is empty.");
	else{
		int i=1;
		max = list->array[list->index - 1];
		list->array[list->index - 1] = 0;
		list->array[i] = max;
		while(list->array[i] < list->array[i*2] ||
		list->array[i] < list->array[i*2 + 1]){
			if(list->array[2*i] < list->array[2*i + 1]){
				swap(&list->array[i],&list->array[2*i + 1]);
				i = 2*i;
			}
			else{
				swap(&list->array[i],&list->array[2*i]);
				i = 2*i + 1;
			}
		}
	}
	
	return max;
}

void swap(int *little,int *big){
	int temp = *little;
	*little = *big;
	*big = temp;
}

void show(pQ *list){
	int i;
	for(i=1 ; i < SIZE/2 ; ++i){
		printf("%d - left:%d --- right: %d\n",
		list->array[i],list->array[2*i],list->array[2*i + 1]);
	}
	putchar('\n');
	putchar('\n');
}
