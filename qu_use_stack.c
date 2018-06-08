#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next;
}Node;

typedef struct queue {
	Node *stack1;
	Node *stack2;
}Queue;

int pop(Node **top);
void push(Node **top, int data);

Queue *createQueue()
{
	Queue *temp = (Queue *)malloc(sizeof (Queue));
	temp->stack1 = 0;
	temp->stack2 = 0;
	return temp;
}

void enqueue(Queue *q, int data)
{
	push(&q->stack1, data);
}

int dequeue(Queue *q) {
	if((q->stack1 == NULL) && (q->stack2 == NULL)) {
		printf("queue is empty\n");
		return -1;
	}
	if(q->stack2 == NULL) {
		while(q->stack1 != NULL) {
			int temp = pop(&q->stack1);
			push(&q->stack2, temp);
		}
	}
	int x = pop(&q->stack2);
	return x;
}

Node *createNode(int data)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->next = NULL;
	temp->data = data;
	return temp;
}

void push(Node **top, int data)
{
	Node *temp = createNode(data);

	if(temp == NULL){
		printf("Stack overflow\n");
		return;
	}
	temp->next = *top;
	*top = temp;

}

int pop(Node **top)
{
	int res;
	Node *temp;
	if(temp == NULL) {
		printf("stack underflow\n");
		return -1;
	} else {
		temp = *top;
		res = (*top)->data;
		*top = (*top)->next;
		free(temp);
		return res;
	}
}

int main()
{
	Queue *q = createQueue();
	enqueue(q, 10);
	enqueue(q, 20);
	enqueue(q, 30);
	enqueue(q, 40);
	enqueue(q, 50);
	printf("dequeue item is %d\n",dequeue(q));
	printf("dequeue item is %d\n",dequeue(q));
	enqueue(q, 60);
}
