#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *prev;
	struct node *next;
}Node;


Node * NodeAddBegin(Node **head_ref)
{
	Node *temp;
	temp = (Node *)malloc(sizeof (Node));
	printf("Enter the data\n");
	scanf("%d", &temp->data);
	temp->next = *head_ref;
	temp->prev = 0;
	if(*head_ref!=NULL)
		(*head_ref)->prev = *head_ref;
	*head_ref = temp;
}

void PrintLL(Node *head_ref)
{
	if(head_ref == NULL)
		return;
	printf("%d ", head_ref->data);
	return (PrintLL(head_ref->next));
}

int main()
{
	Node *head_ref = NULL;
	char ch;
	do {
		NodeAddBegin(&head_ref);
		printf("Do u want to add another node\n");
		scanf(" %c", &ch);
	} while((ch == 'y') || (ch == 'Y'));
	PrintLL(head_ref);
	printf("\n");
}
