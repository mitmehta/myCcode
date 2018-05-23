/* Reverse the Linked-list */
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

int CountLL(Node_t *head)
{
	int count = 0;
	while(head) {
		head = head->next;
		count++;
	}
	return count;
}

Node_t ReverseLL(Node_t **head)
{
	int count = CountLL(*head);
	int iter;
	Node_t **Pnode = (Node_t **)malloc(count * sizeof(Node_t *));
	Node_t *temp = *head;
	for(iter=0; iter<count ; iter++, temp = temp->next) {
		Pnode[iter] = temp;
	}
	Pnode[0]->next = 0;
	for(iter=1; iter<count; iter++) {
		Pnode[iter]->next = Pnode[iter-1];
	}
	*head = Pnode[count-1];
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
	int Vcount;
	char ch;
	do{
		CreateLL_AddMiddle(&head);
		printf("Do you want to add extra node\n");
		scanf(" %c", &ch);
	} while((ch == 'Y') || (ch == 'y'));
	PrintLL(head);
	printf("\n");
	Vcount = CountLL(head);
	printf("Count is %d\n", Vcount);
	ReverseLL(&head);
	printf("Reverse Linked list is....\n");
	PrintLL(head);
	printf("\n");
}
