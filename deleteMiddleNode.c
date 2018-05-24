/* Delete middle node of the linked list */

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


void deleteMiddle(Node_t *head)
{
	Node_t *fastptr =head, *last;
	Node_t *slowptr = head;
	if (head == NULL)
		return;
	while(fastptr && fastptr->next) {
		last = slowptr;
		slowptr = slowptr->next;
		fastptr = fastptr->next->next;
	}
	last->next = slowptr->next;
	free(slowptr);
	slowptr = NULL;
	if(head->next == NULL){
		free(head);
		head = NULL;
		return;
	}

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
	do{
		CreateLL_AddMiddle(&head);
		printf("Do you want to add extra node\n");
		scanf(" %c", &ch);
	} while((ch == 'Y') || (ch == 'y'));
	PrintLL(head);
	deleteMiddle(head);
	printf("\n");
	PrintLL(head);
	printf("\n");
}
