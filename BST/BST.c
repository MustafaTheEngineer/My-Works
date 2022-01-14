#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}Node;

Node *init(void);
Node *newNode(int);
Node *addNode(Node *root,int data);
Node *delNode(Node *root,int data);
Node *findPlace(Node *root,Node *move);
void show(Node *);

int main(void){
	Node *bstRoot = init();
	
	bstRoot = addNode(bstRoot,70);
	bstRoot = addNode(bstRoot,30);
	bstRoot = addNode(bstRoot,100);
	bstRoot = addNode(bstRoot,20);
	bstRoot = addNode(bstRoot,60);
	bstRoot = addNode(bstRoot,50);
	bstRoot = addNode(bstRoot,62);
	
	bstRoot = delNode(bstRoot,30);
	
	show(bstRoot);
	
	return 0;
}

Node *init(void){
	return NULL;
}

Node *newNode(int data){
	Node *n = (Node *) calloc(1,sizeof(Node));
	n->left = NULL;
	n->right = NULL;
	n->data = data;
	
	return n;
}

Node *addNode(Node *root,int data){
	
	if(root == NULL)
		return newNode(data);
	
	Node *temp = root;
	
	while(1){
		if(data < temp->data){
			if(temp->left == NULL){
				temp->left = newNode(data);
				break;
			}
			temp = temp->left;
		}
		else if(data > temp->data){
			if(temp->right == NULL){
				temp->right = newNode(data);
				break;
			}
			temp = temp->right;
		}
		else
			return root;
	}
	
	return root;
}

Node *delNode(Node *root,int data){
	
	Node *temp = root;
	Node *prev=temp;
	
	while(temp != NULL){
		if(data < temp->data){
			prev = temp;
			temp = temp->left;
		}
			
		else if(data > temp->data){
			prev = temp;
			temp = temp->right;
		}
		else{
			if(temp->left != NULL && temp->right != NULL){
				if(prev->data < temp->data)
					findPlace(temp->left,temp->right->left);
				else
					findPlace(temp->right,temp->left->right);
			}
			else if(temp->left == NULL && temp->right != NULL)
				prev->right = temp->right;
			else if(temp->left != NULL && temp->right == NULL)
				prev->right = temp->left;
			
			free(temp);
			break;
		}
	}
	
	return root;
}

Node *findPlace(Node *root,Node *move){
	
	Node *temp = root;
	printf("%d",move->data);
	while(1){
		if(move->data < temp->data){
			if(temp->left == NULL){
				temp->left = move;
				break;
			}
			temp = temp->left;
		}
		else if(move->data > temp->data){
			if(temp->right == NULL){
				temp->right = move;
				break;
			}
			temp = temp->right;
		}
	}
}

void show(Node *root){
	if(root != NULL){
		printf("%d ",root->data);
		show(root->left);
		show(root->right);
	}
	
}
