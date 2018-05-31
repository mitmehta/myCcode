/* Stack implementation using Array */
 #include<stdio.h>
int Stack[5], top = 0;
void Push();
void Pop();
void Display();

int main()
{
	int Option;
	while(1) {
		printf("please Enter the choice...1. Push   2. Pop   3. Display   4. Exit\n");
		scanf("%d", &Option);
		switch(Option) {
		case 1: Push();
			break;

		case 2: Pop();
			break;

		case 3: Display();
			break;

		case 4: return 0;
		}
	}
}

void Push()
{
	int element;
	if(top == 5) {
		printf("Stack overflow\n");
		return;
	}
	printf("enter the elemnt...\n");
	scanf("%d", &element);
	Stack[top++] = element;
}

void Pop()
{
	if(top == 0) {
		printf("Stack underflow\n");
		return;
	}
	printf("popped element is %d\n", Stack[top-1]);
	Stack[--top] = 0;
}

void Display()
{
	int i;
	if(top == 0) {
		printf("Stack is empty\n");
		return;
	}
	for(i=0; i<top; i++) {
		printf("%d --> ", Stack[i]);
	}
}



