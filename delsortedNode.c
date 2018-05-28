/* Delete sorted & unsorted Node(Both) of a link-list */

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

void DelSortedNode(Node_t *head)
{
	Node_t *temp = head, *prev;
	if(temp == NULL)
		return;
	while(temp->next != NULL) {
		if(temp->data == temp->next->data) {
			prev = temp->next->next;
			free(temp->next);
			temp->next = prev;
		} else {
			temp = temp->next;
		}
	}
}

void PrintLL(Node_t *head) {
	if(head == NULL)
		return;
		printf("%d ", head->data);
		return (PrintLL(head->next));
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
	DelSortedNode(head);
	printf("\nAfter deletion\n");
	PrintLL(head);
	printf("\n");
}
