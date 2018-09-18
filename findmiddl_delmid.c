#include<stdio.h>
#include<stdlib.h>

typedef struct snode {
	int data;
	struct snode *prev;
	struct snode *next;
}Snode;

typedef struct mystack {
	Snode *head;
	Snode *mid;
	int count;
}Mystack;

Mystack *CreateMystack()
{
	Mystack *ms = (Mystack *)malloc(sizeof(Mystack));
	ms->count = 0;
	return ms;
}

Snode *createNewnode(int data)
{
	Snode *temp = (Snode *)malloc(sizeof (Snode));
	temp->data = data;
	temp->prev = temp->next = NULL;
	return temp;
}

void push(Mystack *ms, int data)
{
	Snode *temp = createNewnode(data);
	temp->next = ms->head;
	ms->count += 1;

	if(ms->count == 1) {
		ms->mid = temp;
	} else {
		ms->head->prev = temp;
		if(ms->count & 1)
			ms->mid = ms->mid->prev;
	}
	ms->head = temp;
}

int pop(Mystack *ms)
{
	if(ms->count == 0)
	{
		printf("stack is empty\n");
		return -1;
	}
	Snode *head = ms->head;
	int item = head->data;
	ms->head = head->next;

	if(ms->head != NULL)
		ms->head->prev = NULL;

	ms->count -= 1;
	if(!((ms->count) & 1))
		ms->mid = ms->mid->next;
	free(head);
	return item;
}

int findmiddle(Mystack *ms)
{
	if(ms->count == 0) {
		printf("stack is empty now..\n");
		return -1;
	}
	return ms->mid->data;
}

int main()
{
	Mystack *ms = CreateMystack();
	push(ms, 10);
	push(ms, 20);
	push(ms, 30);
	push(ms, 40);
	push(ms, 50);
	push(ms, 60);

	printf("Item popped is %d\n", pop(ms));
	printf("Item popped is %d\n", pop(ms));

	printf("Middle element is %d", findmiddle(ms));
}

