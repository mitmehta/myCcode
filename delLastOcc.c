#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}Node;

Node *createNode(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	return(temp);
}

void push(Node **head, int data)
{
	Node *temp = createNode(data);
	Node *tail;
	if((*head) == NULL) {
		(*head) = temp;
		tail = (*head);
	} else {
		tail->next = temp;
		tail = tail->next;
	}
}

void delLastOcc(Node *head, int key)
{
	Node *curr = head;
	Node *nsave;
	while(curr) {
		if(curr->data == key)
			nsave = curr;
		curr = curr->next;
	}
	if(nsave != NULL && nsave->next == NULL) {
		curr = head;
		while(curr->next != nsave)
			curr = curr->next;
		curr->next = NULL;
	}
	Node *temp;
	if(nsave != NULL && nsave->next != NULL) {
		nsave->data = nsave->next->data;
		temp = nsave->next;
		nsave->next = nsave->next->next;
		free(temp);
	}
}

void printLL(Node *head)
{
	if(head == NULL)
		return;
	printf("%d\t", head->data);
	printLL(head->next);
}

int main()
{
	Node *head = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 2);
	push(&head, 4);
	push(&head, 2);
	push(&head, 5);

	printLL(head);
	printf("\n");
	delLastOcc(head, 2);
	printLL(head);
	printf("\n");
	return 0;
}
