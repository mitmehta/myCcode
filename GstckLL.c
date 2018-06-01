/*stack implementation using LinkList */
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct stack {
	int data;
	struct stack *next;
}stack_t;

int Isempty(stack_t *head) {
	return (head == NULL) ? 1 : 0;
}

int peek(stack_t *head) {
	if(Isempty(head))
		return INT_MIN;
	return head->data;
}

stack_t *newnode(int data)
{
	stack_t *node = (stack_t *)malloc(sizeof (stack_t));
	node->data = data;
	return node;
}

void push(stack_t **head, int data)
{
	stack_t *temp = newnode(data);
	temp->next = *head;
	*head = temp;
	printf("pushed element is %d\n", data);
}

int pop(stack_t **head)
{
	int ele;
	stack_t *temp = *head;
	*head = (*head)->next;
	ele = temp->data;
	free(temp);
	temp = NULL;
	return ele;
}

int main()
{
	stack_t *head = NULL;
	push(&head, 10);
	push(&head, 8);
	push(&head, 12);
	push(&head, 19);

	printf("%d is the popped element\n", pop(&head));
}
