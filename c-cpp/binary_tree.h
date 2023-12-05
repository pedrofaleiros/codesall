#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node *left;
	struct Node *right;
} Node;

Node *alloc_node(){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->value = 0;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void show(Node *root){
	if (root != NULL){
		printf("%d ", root->value);
		show(root->left);
		show(root->right);
	}
}

void insert(Node **root, int num){

	if(*root == NULL){
		*root = alloc_node();
		(*root)->value = num;
	}else{
		if(num < (*root)->value){
			insert(&(*root)->left, num);
		}else{
			insert(&(*root)->right, num);
		}
	}
}


