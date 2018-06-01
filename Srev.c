/* Reverse stack with recursion using link list*/

#include<stdio.h>
#include<stdlib.h>
#define bool int

typedef struct node {
	int data;
	struct node *next;
}Node;

bool Isempty(Node *top)
{
	return (top == NULL) ? 1 : 0;
}

Node *push(Node **head, int ele)
{
	Node *temp = (Node *)malloc(sizeof (Node));
	if(temp == NULL) {
		printf("stack underflow\n");
		return 0;
	}
	temp->data = ele;
	temp->next = *head;
	*head = temp;
}

int pop(Node **head)
{
	Node *temp;
	int res;
	if((*head) == NULL) {
		printf("stack underflow\n");
		return 0;
	}
	else {
		temp = *head;
		res = temp->data;
		*head = temp->next;
		free(temp);
		temp = NULL;
		return res;
	}
}

Node *pushbottom(Node **head, int ele)
{
	if(Isempty(*head)) {
		push(head, ele);
	} else {
		int temp = pop(head);
		pushbottom(head, ele);
		push(head, temp);
	}
}

void revstack(Node **head)
{
	if(!(Isempty(*head))) {
		int temp = pop(head);
		revstack(head);
		pushbottom(head, temp);
	}
}

void displaystack(Node *head)
{
	if(head == NULL)
		return;
	printf("%d --> ", head->data);
	return displaystack(head->next);
}

int main()
{
	Node *head = NULL;
	push(&head, 5);
	push(&head, 10);
	push(&head, 15);
	push(&head, 20);
	push(&head, 25);

	printf("Printing the stack\n");
	displaystack(head);
	revstack(&head);
	printf("\nAfter reverse, Printing the stack\n");
	displaystack(head);
	printf("\n");
}

