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

void rotateLL(Node_t **head, int key)
{
	Node_t *temp = *head, *prev;
	int x=1;
	while(x<key && temp->next != NULL) {
		temp = temp->next;
		x++;
	}
	prev=temp;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = *head;
	*head = prev->next;
	prev->next = NULL;
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
	int n = 7, key;
	CreateLL_AddEnd(&head, n);
	PrintLL(head);
	printf("\n");
	printf("Enter the no of rotation\n");
	scanf("%d", &key);
	rotateLL(&head, key);
	printf("After the rotation\n");
	PrintLL(head);
	printf("\n");
}
