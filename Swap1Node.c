#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *next;
}Node;

Node *createNode(int data)
{
	Node *temp = (Node *)malloc(sizeof (Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void swapNode(Node **head, int x, int y)
{
	if(x==y)
		return;
	Node *prevX = NULL;
	Node *currX = *head;
	while(currX && currX->data != x)
	{
		prevX = currX;
		currX= currX->next;
	}

	Node *prevY = NULL;
	Node *currY = *head;
	while(currY && currY->data != y)
	{
		prevY = currY;
		currY = currY->next;
	}

	if(currX == NULL && currY == NULL)
		return;

	if(prevX != NULL)
		prevX->next = currY;
	else
		*head = currY;
	if(prevY != NULL)
		prevY->next = currX;
	else
		*head = currX;
	Node *temp = currX->next;
	currX->next = currY->next;
	currY->next = temp;
}

void push(Node **head, int data)
{
	Node *temp = createNode(data);
	Node *tail;
	if((*head) == NULL) {
		(*head) = temp;
		tail = (*head);
	}else {
		tail->next = temp;
		tail = tail->next;
	}
}

void printLL(Node *head)
{
	if(head == NULL)
		return;
	printf("%d\t", head->data);
	printLL(head->next);
}

int main()
{
Node *head = NULL;
push(&head, 1);
push(&head, 2);
push(&head, 3);
push(&head, 4);
push(&head, 5);
push(&head, 6);
printf("Printing list before swapping\n");
printLL(head);
swapNode(&head, 1, 6);
printf("\nPrinting list after swapping\n");
printLL(head);
printf("\n");
}
