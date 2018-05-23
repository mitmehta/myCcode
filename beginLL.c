/* Link-list: Add at the begining*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node_t;

Node_t* CreateLL_AddBegin(Node_t **head, int n)
{
	for(int i=1; i <= n; i++) {
		Node_t *temp = (Node_t *)malloc(sizeof (Node_t *));
		temp->data = i;
		temp->next = *head;
		*head = temp;
	}
}

void PrintLL(Node_t *head) {
	if(head == NULL)
		return;
	while(head) {
		printf("%d ", head->data);
		return (PrintLL(head->next));
	}
}

int main()
{
	Node_t *head  = NULL;
	int n = 7;
	CreateLL_AddBegin(&head, n);
	PrintLL(head);
	printf("\n");
}
