#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *left;
	struct node* right;
}Node;

Node *newnode(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void printNode(Node *root)
{
	if(root == NULL)
		return;
	(printNode(root->left));
	(printNode(root->right));
	printf("%d\t", root->data);
}

int main()
{
	Node *root = newnode(1);
	root->left = newnode(2);
	root->right = newnode(3);
	root->left->left = newnode(4);
	root->left->right = newnode(5);
	root->right->right= newnode(6);
	root->right->left = newnode(7);
	printNode(root);
	printf("\n");
	return 0;
}
