#include<stdio.h>
typedef struct node 
{
	int data;
	struct node *next;
}Node;

typedef struct queue {
	Node *stack1;
	Node *stack2;
}Queue;


int main()
{
Queue *q = createQueue();


}
