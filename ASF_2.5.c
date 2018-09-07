#include <stdio.h>
#include <malloc.h>
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
} NODE;
typedef NODE *tree;
int sum = 0;
tree givetree(int data){
	tree q = (tree)malloc(sizeof(NODE));
	q->right = NULL;
	q->left = NULL;
	q->data = data;
	return q;
}
int getLeaf(tree p){
	if(p->right ==NULL && p->left == NULL)sum++;
	if(p->right!=NULL)getLeaf(p->left);
	if(p->left!=NULL)getLeaf(p->right);
	return sum;
}
int main(void){
/*	           *
	          / \
	         *   *
	            / \
	           *   *
	          / \
	         *   *

*/
	tree head = givetree(1);
	head->right = givetree(2);
	head->left = givetree(3);
	head->right->left = givetree(4);
	head->right->right = givetree(5);
	head->right->left->left = givetree(4);
	head->right->left->right = givetree(4);
	if(head==NULL){
		printf("There is not any tree.");
	}
	if(head->right==NULL&&head->left==NULL){
		printf("There is no leaf only root.");
	}
	if(getLeaf(head) == 1){
		printf("There is only one leaf in tree");
	}
	sum=0;
	printf("There are %d leaves in tree : ", getLeaf(head));
	return 0;
}
