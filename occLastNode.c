/* Delete last occurance of a linked list */

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
	if(*head == NULL) {
		temp->next = *head;
		*head = temp;
	} else {
		Node_t *last = *head;
		while(last->next != NULL)
			last = last->next;
		temp->next = last->next;
		last->next = temp;
	}
}

void DelLastOcc(Node_t *head, int key)
{
	Node_t *temp = head, *present = NULL;
	while(temp) {
		if(temp->data == key)
			present = temp;
		temp = temp->next;
	}
	//if data present in the last node
	if(present != NULL && present->next == NULL) {
		temp = head;
		while(temp->next != present)
			temp = temp->next;
		temp->next = NULL;
	}
	// if data is not present in the last node
	if(present != NULL && present->next != NULL) {
		present->data = present->next->data;
		Node_t *var = present->next;
		present->next = present->next->next;
		free(var);
		var = NULL;
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
	int key;
	printf("Enter the digit\n");
	scanf("%d", &key);
	DelLastOcc(head, key);
	printf("After deletion\n");
	PrintLL(head);
	printf("\n");
}
