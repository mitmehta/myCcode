#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
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

void push(Node **head, int data)
{
	Node *temp = createNode(data);
	Node *tail;

	if(temp == NULL) {
		printf("linked list is mot present\n");
		return;
	}

	if((*head) == NULL) {
		temp->next = (*head);
		(*head) = temp;
		tail = (*head);
	} else {
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

Node *mergesortedLL(Node *head1, Node *head2)
{
	Node *res = NULL;
	if(head1 == NULL)
		return (head2);
	else if(head2 == NULL)
		return (head1);

	if(head1->data <= head2->data)
	{
		res = head1;
		res->next = mergesortedLL(head1->next, head2);
	} else {
		res = head2;
		res->next = mergesortedLL(head1, head2->next);
	}
	return (res);
}

int main()
{
	Node *head1 = NULL;
	push(&head1, 12);
	push(&head1, 15);
	push(&head1, 25);
	push(&head1, 35);

	Node *head2 = NULL;
	push(&head2, 10);
	push(&head2, 20);
	push(&head2, 30);
	push(&head2, 40);
	printf("Printing first link list\n");
	printLL(head1);
	printf("\n");
	printf("\nPrinting second link list\n");
	printLL(head2);
	printf("\n");
	Node *res = mergesortedLL(head1, head2);
	printf("\nPrinting merged link list\n");
	printLL(res);
	printf("\n\n");
	return 0;
}
