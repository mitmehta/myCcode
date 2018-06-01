/* Delete the whole linked list*/
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
void deleteLL(Node **head)
{
	Node *temp = *head, *newNext;
	while(temp != NULL) {
		newNext = temp->next;
		free(temp);
		temp=NULL;
		temp = newNext;
	}
	*head = NULL;
}
void print(Node *head)
{
	if(head == NULL){
		return;
	}
	while(head) {
		printf("%d ", head->data);
	//	return (print(head->next));
		head= head->next;
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
	printf("\n");
	deleteLL(&head);
	printf("Node deleted\n");
	print(head);
}

