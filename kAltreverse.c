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

void push(Node **head, int data)
{
	Node *temp = createNode(data);
	Node *tail;
	if(*head == NULL) {
		*head = temp;
		tail = *head;
	} else {
		tail->next = temp;
		tail = tail->next;
	}
}

Node *kAltreverse(Node *head, int key)
{
	Node *next;
	Node *current = head;
	Node *prev = NULL;
	int count = 0;

	while(current != NULL && count < key)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}
	if(next != NULL)
		head->next = kAltreverse(next, key);
	return prev;
}

void printLL(Node *head)
{
	if(head == NULL)
		return;
	printf("%d-->",head->data );
	printLL(head->next);

}

int main()
{
	Node *head = NULL;
	int i;
	for(i = 1; i <= 15; i++)
		push(&head, i);
	printLL(head);
	int k;
	scanf("%d", &k);
	head = kAltreverse(head, k);
	printLL(head);
	printf("\n");
}
