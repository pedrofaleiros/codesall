#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int bool;
#define true 1
#define false 0

typedef struct Node
{
	int value;
	struct Node *left;
	struct Node *right;
} Node;

typedef struct Tree
{
	int count;
	struct Node *root;
} Tree;

Tree *alloc_tree()
{
	Tree *newTree = (Tree *)malloc(sizeof(Tree));
	newTree->count = 0;
	newTree->root = NULL;
	return newTree;
}

Node *alloc_node(int num)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->value = num;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void show(Node *root)
{
	if (root != NULL){
		printf("%d ", root->value);
		show(root->left);
		show(root->right);
	}
}

void show_tree(Tree *tree)
{
	show(tree->root);
}

void insert_node(Node **root, int num)
{
	if (*root == NULL){
		*root = alloc_node(num);
	}else{
		if (num < (*root)->value){
			insert_node(&((*root)->left), num);
		}else{
			insert_node(&((*root)->right), num);
		}
	}
}

void insert(Tree *tree, int num)
{
	insert_node(&(tree->root), num);
}

int main(int argc, char * argv[])
{

	Tree *tree = alloc_tree();
	
	insert(tree, 3);
	insert(tree, 1);
	insert(tree, 4);
	insert(tree, 6);

	show_tree(tree);

	return 0;
}
