/* Link-list: Add at the end*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node_t;

Node_t* CreateLL_AddEnd(Node_t **head, int n)
{
	Node_t *tail ;
	for(int i=1; i <= n; i++) {
		Node_t *temp = (Node_t *)malloc(sizeof (Node_t *));
		temp->data = i;
		if(*head == NULL) {
			*head = temp;
			tail = *head;
		} else {
			tail->next = temp;
			tail = tail->next;
		}
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
	CreateLL_AddEnd(&head, n);
	PrintLL(head);
	printf("\n");
	
}
