#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
	int data;
	struct Node *next;
} Node_t;

Node_t *add_end(Node_t **head)
{
	Node_t *temp, *tail;
	temp = (Node_t *)malloc(sizeof(Node_t *));
	printf("Enter the data\n");
	scanf("%d", &temp->data);
	if(*head == NULL){
		temp->next = *head;
		*head = temp;
		tail = temp;
	} else {
		temp->next = tail->next;
		tail->next = temp;
		tail=tail->next;
	}
}

void printLL(Node_t *head)
{
	Node_t *temp = head;
	if(temp == NULL)
		return;
	while(temp) {
		printf("%d ", temp->data);
		return (printLL(temp->next));
	}
}

int main()
{
	Node_t *head = NULL;
	char ch;
	do {
		add_end(&head);
		printf("Do u want to add another node\n");
		scanf(" %c", &ch);
	} while(( ch == 'y') || (ch == 'Y'));
	printLL(head);
}

