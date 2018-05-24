/* Double link list: add at the end*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *prev;
	struct node *next;
}Node;


Node * NodeAddEnd(Node **head_ref)
{
	Node *temp;
	temp = (Node *)malloc(sizeof (Node));
	printf("Enter the data\n");
	scanf("%d", &temp->data);
	if(*head_ref == NULL) {
		temp->prev = NULL;
		*head_ref = temp;
	} else {
		Node *last = *head_ref;
		while(last->next != NULL)
			last = last->next;
		last->next = temp;
		temp->prev = last;
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
		NodeAddEnd(&head_ref);
		printf("Do u want to add another node\n");
		scanf(" %c", &ch);
	} while((ch == 'y') || (ch == 'Y'));
	PrintLL(head_ref);
	printf("\n");
}
