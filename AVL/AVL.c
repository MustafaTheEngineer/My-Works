#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	int height;
	struct node *left;
	struct node *right;
}Node;

Node *newNode(int);
Node *insert(Node *,int);
int max(int,int);
int height(Node *);
int getBalance(Node *);
Node *rightRotate(Node *);
void preOrder(Node *);
Node *leftRotate(Node *);

int main(void){
	
	Node *root = NULL;
	
	root = insert(root,10);
	preOrder(root);
	printf("\n");
	
	root = insert(root,12);
	preOrder(root);
	printf("\n");
	
	root = insert(root,14);
	preOrder(root);
	printf("\n");
	
	return 0;
}

Node *newNode(int data){
	Node *node = (Node *) calloc(1,sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	
	return node;
}

Node *insert(Node *node,int data){
	
	if(node == NULL)
		return newNode(data);
		
	if(data < node->data)
		node->left = insert(node->left, data);
	else if(data > node->data)
		node->right = insert(node->right, data);
	else
		return node;
		
	node->height = 1 + max(height(node->left),height(node->right));
	
	int balance = getBalance(node);
	
	if(balance > 1 && data < node->left->data)
		return rightRotate(node);
	if(balance < -1 && data > node->right->data)
		return leftRotate(node);
	if(balance < -1 && data < node->right->data){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	if(balance > 1 && data < node->left->data){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
		
	return node;
}

int height(Node *node){
	if(node == NULL)
		return 0;
	
	return node->height;
}

int max(int a,int b){
	return (a > b) ? a : b;
}

int getBalance(Node *node){
	if(node == NULL)
		return 0;
	
	return height(node->left) - height(node->right);
}

Node *rightRotate(Node *z){
	Node *y = z->left;
    Node *T3 = y->right;

    y->right = z;
    z->left = T3;
 
    z->height = max(height(z->left), height(z->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

Node *leftRotate(Node *z){
	Node *y = z->right;
    Node *T2 = y->left;
 
    y->left = z;
    z->right = T2;
 
    z->height = max(height(z->left), height(z->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    return y;
}

void preOrder(Node *root){
	if(root != NULL){
		printf("%d ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}





