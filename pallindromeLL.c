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
	if(*head == NULL) {
		temp->next = *head;
		*head = temp;
	} else {
		Node_t *last = *head;

		while(last->next != NULL) 
			last = last->next;
		temp->next = last->next;
		last->next = temp;
	}
}
Node_t reverseSecHalf(Node_t **head)
{
	Node_t *temp = *head;
	Node_t *prev = NULL;
	Node_t *next = NULL;
	while(temp != NULL) {
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}
	*head = prev;
}

int compareLL(Node_t *head, Node_t *reversePtr)
{
	Node_t *temp1 = head;
	Node_t *temp2 = reversePtr;
	while(temp1!= NULL && temp2!= NULL) {
		if(temp1->data == temp2->data) {
			temp1 = temp1->next;
			temp2 = temp2->next;
		} else
			return 0;
	}
	if(temp1 == NULL && temp2 == NULL)
		return 1;
	return 0;
}

int pallindromeLL(Node_t *head)
{
	Node_t *fastPtr = head;
	Node_t *slowPtr = head, *prev=head;
		int res = 1;
	if(head != NULL && head->next != NULL) {
		while(fastPtr != NULL && fastPtr->next != NULL) {
			fastPtr = fastPtr->next->next;
			prev = slowPtr;
			slowPtr = slowPtr->next;
		}

		Node_t *midnode = NULL;
		if(fastPtr != NULL) {
			midnode = slowPtr;
			slowPtr = slowPtr->next;
		}
		Node_t *sechalf = slowPtr;
		prev->next = NULL;
		reverseSecHalf(&sechalf);
		res = compareLL(head, sechalf);
		reverseSecHalf(&sechalf);
		if(midnode != NULL) {
			prev->next = midnode;
			midnode->next = sechalf;
		} else
			prev->next = sechalf;
	}
	return res;
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
	int Vcount, var;
	char ch;
	do{
		CreateLL_AddMiddle(&head);
		printf("Do you want to add extra node\n");
		scanf(" %c", &ch);
	} while((ch == 'Y') || (ch == 'y'));
	PrintLL(head);
	printf("\n");
	var = pallindromeLL(head);
	if(var == 1) 
		printf("linked list is pallindrom\n");
	else
		printf("Linked list is not pallindrome\n");
	PrintLL(head);
	printf("\n");
}
