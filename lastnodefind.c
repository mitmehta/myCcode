#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

Node *createNode(int data)
{
	Node *temp = (Node *)malloc(sizeof (Node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

Node *findnNodeEnd(Node *head, int n)
{
	Node *temp = head;
	Node *ref = head;
	if(head == NULL)
		return 0;
	int count = 0;
	while(count < n) {
		if(temp == NULL) {
			printf("%d is not present\n", n);
			return 0;
		}
		temp = temp->next;
		count++;
	}
	while(temp != NULL) {
		ref = ref->next;
		temp = temp->next;
	}
	return ref;
}

void push(Node **head, int data)
{
	Node *temp = createNode(data);
	if(temp == NULL) {
		printf("Linked list is empty\n");
		return;
	}
	temp->next = (*head);
	(*head) = temp;
}

void printNode(Node *head) 
{
	if(head == NULL)
		return;
	printf("%d\t", head->data);
	printNode(head->next);
}

int main()
{
	Node *head = NULL;
	push(&head, 10);
	push(&head, 20);
	push(&head, 30);
	push(&head, 40);
	push(&head, 50);

	printNode(head);
	printf("\n");
	int n;
	scanf("%d", &n);
	Node *res;
	res = findnNodeEnd(head, n);
	printf("res- %d\n", res->data);
}
