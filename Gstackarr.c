#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
	int top;
	unsigned capacity;
	int *array;
}Stack;

Stack *createStack(unsigned capacity)
{
	Stack *s = (Stack *)malloc(sizeof (Stack));
	s->capacity = capacity;
	s->top = -1;
	s->array = (int *)malloc(s->capacity * sizeof (int));
	return s;
}

int Isempty(Stack *s)
{
	return s->top == -1;
}

int Full(Stack *s)
{
	return s->top == s->capacity -1;
}

void push(Stack *s, int ele)
{
	if(Full(s)) {
		printf("stack overflow\n");
		return;
	}
	s->array[++(s->top)] = ele;
	printf("%d pushed to the stack\n", ele);
}

int pop (Stack *s)
{
	if(Isempty(s)) {
		printf("stack underflow\n");
		return 0;
	}
	return s->array[(s->top)--];
}

int main()
{
	Stack  *s = createStack(100);
	push(s, 10);
	push(s, 20);
	push(s, 30);
	push(s, 40);
	printf("Popped element is %d\n", pop(s));
}
