/* Delete the node from the Linked-list */

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

void  DeleteNode(Node_t **head, int DelNode)
{
	Node_t *temp =*head, *prevNode;
	if(*head == NULL) {
		printf("Linked list is empty\n");
		return;
	}
	while(temp) {
		if(temp->data == DelNode) {
			if(temp == *head) {
				*head = (*head)->next;
				free(temp);
				temp = NULL;
				return;
			} else {
				prevNode->next = temp->next;
				free(temp);
				temp = NULL;
				return;
			}
		}
		prevNode = temp;
		temp = temp->next;
	}
	printf("Data is not present to delete\n");
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
	int DelNode;
	char ch;
	do{
		CreateLL_AddMiddle(&head);
		printf("Do you want to add extra node\n");
		scanf(" %c", &ch);
	} while((ch == 'Y') || (ch == 'y'));
	PrintLL(head);
	printf("\n");
	printf("Enter which node you want to delete\n");
	scanf("%d", &DelNode);
	DeleteNode(&head, DelNode);
	printf("After deleting the Node, List is\n");
	PrintLL(head);
	printf("\n");
}
