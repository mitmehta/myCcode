/* Double link lst: sorting */
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *prev;
	struct node *next;
}Node;


Node * NodeAddMiddle(Node **head_ref)
{
	Node *temp;
	temp = (Node *)malloc(sizeof (Node));
	printf("Enter the data\n");
	scanf("%d", &temp->data);
	if(*head_ref == NULL || (temp->data < (*head_ref)->data)) {
		temp->next = *head_ref;
		*head_ref = temp;
	}
	else if (temp->data < (*head_ref)->data) {
		temp->prev = NULL;
		(*head_ref)->prev = temp;
		*head_ref = temp;
	}
	else {
		Node *last = *head_ref;
		while(last->next && temp->data > (last->next)->data)
			last = last->next;
		temp->next = last->next;
		temp->prev = last;
		if(last->next && temp->data < (last->next)->data)
			temp->next->prev = last;
		last->next = temp;
	}
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
		NodeAddMiddle(&head_ref);
		printf("Do u want to add another node\n");
		scanf(" %c", &ch);
	} while((ch == 'y') || (ch == 'Y'));
	PrintLL(head_ref);
	printf("\n");
}
