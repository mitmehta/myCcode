/* Delete nth node from an end in a linked list */

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
int CountNode(Node_t *head) 
{
	int c = 0;
	if(head == NULL)
		return -1;
	while(head) {
		head = head->next;
		c++;
	}
	return c;
}

void DelNode(Node_t *head, int n)
{
	Node_t *prev, *temp =head;
int i;
	int count = CountNode(head);
	printf("\n%d\n", count);
	for(i = 0; i < (count-n-1); i++, temp = temp->next) {
		prev = temp;
	}
	prev->next = temp->next;
	free(temp);
	temp = NULL;
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
	int n;
	printf("Enter the node you want to delete\n");
	scanf("%d", &n);
	DelNode(head, n);
	printf("After deletion\n");
	PrintLL(head);
	printf("\n");
}
