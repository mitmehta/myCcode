/*Delete the node at a given position in the linked list */

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

int  CountNode(Node_t *head)
{
	int count = 0;
	while(head) {
		head = head->next;
		count++;
	}
	return count;
}

void DeleteNodePos(Node_t **head, int Pos, int count)
{
	Node_t *temp = *head, *prev;
	int i;
	printf("%d %d\n", Pos, count);
	for(i=0; i<count;i++, temp = temp->next) {
		if(i==Pos) {
			if(i == 0) {
				*head =(*head)->next;
				free(temp);
				temp = NULL;
				return;
			} else {
				prev->next = temp->next;
				free(temp);
				temp = NULL;
				return;
			}
		}
		prev = temp;
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
	int count, Pos;
	do{
		CreateLL_AddMiddle(&head);
		printf("Do you want to add extra node\n");
		scanf(" %c", &ch);
	} while((ch == 'Y') || (ch == 'y'));
	PrintLL(head);
	count = CountNode(head);
	printf("Enter the position you want to delete\n");
	scanf("%d", &Pos);
	DeleteNodePos(&head, Pos, count);
	PrintLL(head);
	printf("\n");
}
