/* Detect loop in the given linked list*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *next;
}Node;

Node * add_end(Node **head)
{
	Node *temp = (Node *)malloc(sizeof (Node *)), *tail = *head;
	printf("Enter the data\n");
	scanf("%d", &temp->data);
	if(*head == NULL) {
		temp->next = *head;
		*head = temp;
	} else {
		temp->next = tail->next;
		tail->next = temp;
		tail=tail->next;
	}

}

int detectLoop(Node *head)
{
	Node *fastP = head, *slowP = head;
	while(slowP && fastP && fastP->next) {
		slowP = slowP->next;
		fastP = fastP->next->next;
		if(slowP == fastP) {
			printf("Loop Found\n");
			return 1;
		}
	}
	printf("Loop not found\n");
	return 0;
}


void print(Node *head)
{
	if(head == NULL){
		return;
	}
	while(head) {
		printf("%d ", head->data);
		return (print(head->next));
	}
}

int main()
{
	Node *head= NULL;
	char ch;
	do {
		add_end(&head);
		printf("Do you want to add another node\n");
		scanf(" %c", &ch);
	} while(ch == 'y' ||  ch == 'Y');
	print(head);
	head->next->next = head;
	printf("\n");
	detectLoop(head);
}

