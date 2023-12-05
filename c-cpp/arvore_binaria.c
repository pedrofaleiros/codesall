#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct node {
	int value;
	struct node * right;
	struct node * left;
} node;

node * aloca_node(){
	node * new;
	new = malloc(sizeof(node));
	new->value = 0;
	new->left = NULL;
	new->right = NULL;
	return new;
}

node * insert(node * root, int num){

	if(root == NULL){
		root = aloca_node();
		root->value = num;
		return root;
	}else{
		if(num > root->value){
			root->right = insert(root->right, num);
		}else{
			root->left = insert(root->left, num);
		}
	}

	return root;
}

void show(node * root){
	if(root != NULL){
        printf(" %d", root->value);
		show(root->left);
		show(root->right);
    }
}

int calcula_altura(node * root, int value){
	if(root == NULL){
		return value;
	}else{
		value++;
		int altura_esquerda = calcula_altura(root->left, value);
		int altura_direita = calcula_altura(root->right, value);

		if(altura_direita > altura_esquerda){
			return altura_direita;
		}else{
			return altura_esquerda;
		}
	}
}

bool isBalanced(node * root) {

	if(root == NULL){
		return true;
	}else{
		if(abs(calcula_altura(root->right, 0) - calcula_altura(root->left, 0)) < 2 && isBalanced(root->left) && isBalanced(root->right)){
			return true;
		}
	}
	return false;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {

	if(p == NULL && q == NULL){
		return true;
	}

	if(p != NULL && q != NULL && p->val == q->val){
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}

	return false;
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {

	if(root != NULL && subRoot != NULL){
		bool a = isSameTree(root, subRoot);
		bool b = isSameTree(root->left, subRoot);
		bool c = isSameTree(root->right, subRoot);
		bool d = isSubtree(root->right, subRoot);
		bool e = isSubtree(root->left, subRoot);
		return a||b||c||d||e;
	}
	return false;
}

int main(){

	node * arvore = NULL;

	arvore = insert(arvore, 2);
	arvore = insert(arvore, 1);
	arvore = insert(arvore, 3);

	show(arvore);

	node * inverse = invertTree(arvore);

	printf("\n");
	show(inverse);

	return 0;
}
