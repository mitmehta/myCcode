/* Implement two stack using one array */
#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
	int *array;
	int top1, top2;
	int size;
}Stack;

Stack *createStack(int n)
{
	Stack *s = (Stack *)malloc(sizeof (Stack));
	s->size = n;
	s->top1 = -1;
	s->top2 = s->size;
	s->array = (int *)malloc(s->size * sizeof (int));
	return s;
}

void push1(Stack *s, int ele)
{
	if(s->top1 < s->top2-1)
	{
		s->top1++;
		s->array[s->top1] = ele;
	} else {
		printf("stack overflow\n");
		return;
	}
}

void push2(Stack *s, int ele)
{
	if(s->top1 < s->top2 - 1) {
		s->top2--;
		s->array[s->top2] = ele;
	} else {
		printf("Stack overflow\n");
		return;
	}
}

int pop1(Stack *s)
{
	if(s->top1 >= 0) {
		int x = s->array[s->top1];
		s->top1--;
		return x;
	} else {
		printf("stack underflow\n");
		return 0;
	}
}

int pop2(Stack *s)
{
	if(s->top2 < s->size) {
		int x = s->array[s->top2];
		s->top2++;
		return x;
	} else {
		printf("stack underflow\n");
		return 0;
	}
}

int main()
{

	Stack *s = createStack(100);

	push1(s, 10);
	push1(s, 20);
	push2(s, 30);
	push2(s, 40);
	printf("%d is popped\n", pop1(s));
	push2(s, 60);
	printf("%d is popped\n", pop2(s));
	return 0;
}


