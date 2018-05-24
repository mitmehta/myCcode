/* Swapping of two given node without swapping the data*/

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

void SwapNode(Node_t **head, int NodeX, int NodeY)
{
	if(NodeX == NodeY) {
		printf("Both Node are same\n");
		return;
	}

	Node_t *tempX = *head, *PrevX;
	while(tempX != NULL && tempX->data != NodeX) {
		PrevX = tempX;
		tempX = tempX->next;
	}

	Node_t *tempY = *head, *PrevY;
	while(tempY != NULL && tempY->data != NodeY) {
		PrevY = tempY;
		tempY = tempY->next;
	}

	if(tempX == NULL || tempY == NULL)
		return;

	if(PrevX != NULL)
		PrevX->next = tempY;
	else
		*head = tempY;

	if(PrevY !=NULL)
		PrevY->next = tempX;
	else
		*head = tempX;

	Node_t *temp = tempY->next;
	tempY->next = tempX->next;
	tempX->next = temp;
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
	int NodeX, NodeY;
	do{
		CreateLL_AddMiddle(&head);
		printf("Do you want to add extra node\n");
		scanf(" %c", &ch);
		fflush(stdin);
	} while((ch == 'Y') || (ch == 'y'));
	PrintLL(head);
	printf("Enter the two node for swappingn");
	scanf("%d%*c",&NodeX);
	fflush(stdin);
	scanf("%d%*c",&NodeY);
	printf("x-%d y-%d\n", NodeX, NodeY);
	SwapNode(&head, NodeX, NodeY);
	printf("after swapping\n");
	PrintLL(head);
	printf("\n");
}
