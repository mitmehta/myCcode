/* Implented stack using Link-list */
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

void push(Node **head)
{

	Node *temp;
	temp = (Node *)malloc(sizeof (Node));
	printf("Enter the data..\n");
	scanf("%d", &temp->data);
	if(temp == NULL)
		return;
	temp->next = *head;
	*head = temp;
}

int pop(Node **head)
{
	Node *temp = *head;
	*head = (*head)->next;
	printf("Popped elemt is %d\n", temp->data);
	free(temp);
	temp = NULL;
}

void display(Node *head)
{
	if(head == NULL)
		return;
	printf("%d --> ", head->data);
	return (display(head->next));
}

int main()
{
	Node *head = NULL;
	int option;
	while(1) {
		printf("Enter the choice..\n 1. Push \n 2. Pop\n 3. Display\n 4. Exit\n");
		scanf("%d", &option);
		switch(option) {
		case 1: push(&head);
			break;
		case 2: pop(&head);
			break;
		case 3: display(head);
			break;
		case 4: return 0;
		}
	}
}



