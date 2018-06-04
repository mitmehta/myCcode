/*queue implementation using Link List */

#include<stdio.h>
#include<stdlib.h>

typedef struct qnode
{
	int data;
	struct qnode *next;
}Qnode;

typedef struct queue
{
	Qnode *front, *rear;
}Queue;

Queue *createQueue()
{
	Queue *q = (Queue *)malloc(sizeof (Queue));
	q->front = q->rear = NULL;
	return q;
}

Qnode *newnode(int key)
{
	Qnode *temp = (Qnode *)malloc(sizeof(Qnode));
	temp->data = key;
	temp->next = NULL;
	return temp;
}

void enqueue(Queue *q, int data)
{
	//Create a new Link List node
	Qnode *temp = newnode(data);

	//If queue is empty, then newnode is both front and rear
	if(q->rear == NULL) {
		q->front = q->rear = temp;
		printf("%d is the queued\n", data);
		return;
	}

	//Add node at the end of the queue.
	q->rear->next = temp;
	printf("%d is the queued\n", data);
}

Qnode *dequeue(Queue *q)
{
	//If front is NULL, then return
	if(q->front == NULL)
		return 0;

	Qnode *temp = q->front;
	q->front = q->front->next;

	//If front become NULL, change rear also as NULL
	if(q->front == NULL)
		q->rear = NULL;
	return temp;
}

int main()
{
	Queue *q = createQueue();

	enqueue(q, 10);
	enqueue(q, 20);
	enqueue(q, 30);
	enqueue(q, 40);
	enqueue(q, 50);
	Qnode *delnode = dequeue(q);

	if(delnode != NULL) {
		printf("dequeued item is %d\n", delnode->data);
		return 0;
	}
}
