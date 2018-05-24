/* Link-list Add at the middle */

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

int countNode(Node_t *head)
{
	int c=0;
	while(head){
		head = head->next;
		c++;
	}
	return c;
}

void findMiddle(Node_t *head)
{
int iter, count = countNode(head);
Node_t *temp = head;
printf("\ncount - %d\n", count);
for(iter = 1; iter < (count/2); iter++, temp=temp->next);
if((count/2) == 0) {
printf("%d\n",  temp->data);
} else {
	printf("%d\n", temp->next->data);
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
	findMiddle(head);
	printf("\n");
}
