#include<stdio.h>
#include<stdlib.h>

typedef struct stack {
	int data;
	struct stack *next;
}Stack;

Stack *newNode(int data)
{
	Stack *temp = (Stack *)malloc(sizeof (Stack));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

int Isempty(Stack *head)
{
return (head == NULL) ? 1 : 0;
}

int top(Stack *head) 
{
return (head->data);
}

void push(Stack **head, int data)
{
	Stack *temp = newNode(data);
	if(temp == NULL) {
		printf("stack overflow\n");
		return;
	}
	temp->next = (*head);
	(*head) = temp;
}

int pop(Stack **head)
{
	Stack *temp = *head;
	int res = temp->data;
	(*head) = (*head)->next;
	free(temp);
	return res;
}

void sortedInsert(Stack **head, int data) 
{
	if((Isempty(*head)) || data > top(*head)) {
		push(head, data);
		return;
	}
	int ele = pop(head);
	sortedInsert(head, data);

	push(head, ele);
}

void sortStack(Stack **head)
{
	if(!(Isempty(*head))) {
		int data = pop(head);
		sortStack(head);

		sortedInsert(head, data);
	}
}

void print(Stack *head)
{
	if(head == NULL)
		return;
	printf("%d\t", head->data);
	return print(head->next);
}

int main()
{
	Stack *head = NULL;
	push(&head, 22);
	push(&head, 10);
	push(&head, 15);
	push(&head, 30);
	push(&head, 45);

	printf("Before sorting, Stack is...\n");
	print(head);
	printf("\n");

	sortStack(&head);
	printf("After sorting, stack is...\n");
	print(head);
	printf("\n");
}
