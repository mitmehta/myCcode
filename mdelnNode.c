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

void printLL(Node *head)
{
	if(head == NULL)
		return;
	printf("%d\t", head->data);
	printLL(head->next);
}

void delmnNode(Node *head, int m, int n)
{
	int i;

	Node *curr = head;
	Node *t;
	while(curr) {
		for(i = 1; i < m && curr != NULL; i++) {
			curr = curr->next;
		}
		if(curr == NULL)
			return;
		t = curr->next;
		for(i = 1; i <= n && t != NULL; i++)
		{
			Node *temp = t;
			t = t->next;
			free(temp);
		}
		curr->next = t;
		curr = t;
	}
}

int main()
{
	Node *head = NULL;
	push(&head, 10);
	push(&head, 20);
	push(&head, 30);
	push(&head, 40);
	push(&head, 50);
	push(&head, 60);

	printLL(head);
	printf("\n");
	delmnNode(head, 2, 2);
	printLL(head);
	printf("\n");
	return 0;
}
