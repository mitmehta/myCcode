#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct queue {
	int front, rear, size;
	unsigned capacity;
	int *array;
} Queue;

Queue *createQueue(unsigned capacity)
{
	Queue *node = (Queue *)malloc(sizeof (Queue));
	node->capacity = capacity;
	node->front = node->size = 0;
	node->rear = capacity - 1;
	node->array = (int *)malloc(node->capacity * sizeof (node));
	return node;
}

int IsFull(Queue *node) {
	return (node->size == node->capacity);
}

int IsEmpty(Queue *node) {
	return (node->size == 0);
}

void enqueue(Queue *node, int item)
{
	if(IsFull(node))
		return;
	node->rear = (node->rear + 1)%node->capacity;
	node->array[node->rear] = item;
	node->size = node-> size + 1;
	printf("%d is enqueued  in the queue\n", item);
}

int dequeue(Queue *node)
{
	if(IsEmpty(node))
		return 0;
	int item = node->array[node->front];
	node->front = (node->front + 1) % node->capacity;
	node->size = node->size -1;
	return item;
}

int front(Queue *node) {
if(IsEmpty(node))
	return INT_MIN;
return node->array[node->front];
}

int rear(Queue *node) {
	if(IsEmpty(node))
		return INT_MIN;
	return node->array[node->rear];
}

int main()
{
	Queue *node = createQueue(1000);

	enqueue(node, 10);
	enqueue(node, 20);
	enqueue(node, 30);
	enqueue(node, 40);
	enqueue(node, 50);

	printf("%d dequeue from the queue\n", dequeue(node));
	printf("Front item is %d\n", front(node));
	printf("Rear item is %d\n", rear(node));

	return 0;
}
