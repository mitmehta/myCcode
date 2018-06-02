/* Reverse the Linked-list using recursion*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node_t;

Node_t* CreateLL_AddMiddle(Node_t **head)
{
	Node_t *temp = (Node_t *)malloc(sizeof (Node_t *));
	printf("enter the data\n");
	scanf("%d", &temp->data);
	if(*head == NULL || (temp->data < (*head)->data)) {
		temp->next = *head;
		*head = temp;
	} else {
		Node_t *last = *head;

		while((last->next != NULL) && (last->next->data < temp->data))
			last = last->next;
		temp->next = last->next;
		last->next = temp;
	}
}

/*function used to reverse the link list */

void ReverseLL(Node_t **head) {
	Node_t *first = *head;
	Node_t *second = first->next;
	if(head == NULL || second == NULL)
		return;
	ReverseLL(&second);
	first->next->next = first;
	first->next = NULL;
	*head = second;
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
	int Vcount;
	char ch;
	do{
		CreateLL_AddMiddle(&head);
		printf("Do you want to add extra node\n");
		scanf(" %c", &ch);
	} while((ch == 'Y') || (ch == 'y'));
	PrintLL(head);
	printf("\n");
	ReverseLL(&head);
	printf("Reverse Linked list is....\n");
	PrintLL(head);
	printf("\n");
}
