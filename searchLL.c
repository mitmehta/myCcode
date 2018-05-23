/* Search any node from the given linked-list */

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

int SearchLL(Node_t **head, int Snode)
{
	Node_t *temp =*head;
	while(temp) {
		if(temp->data == Snode) {
			return 1;
		}
		temp = temp->next;
	}
	return 0;
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
	char ch;
	int Snode, result = 0;
	do{
		CreateLL_AddMiddle(&head);
		printf("Do you want to add extra node\n");
		scanf(" %c", &ch);
	} while((ch == 'Y') || (ch == 'y'));
	PrintLL(head);
	printf("\n");
	printf("Enter the node you want to search\n");
	scanf("%d", &Snode);
	result = SearchLL(&head, Snode);
	if(result == 1) {
		printf("true, Data is present\n");
	} else {
		printf("False, Data is not present\n");
	}
}
