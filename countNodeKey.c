/* count the particular from the whole linked list*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *next;
}Node;

Node * add_end(Node **head)
{
	Node *temp = (Node *)malloc(sizeof (Node *)), *tail = *head;
	printf("Enter the data\n");
	scanf("%d", &temp->data);
	if(*head == NULL) {
		temp->next = *head;
		*head = temp;
	} else {
		temp->next = tail->next;
		tail->next = temp;
		tail=tail->next;
	}
}

int countKey(Node *head, int key)
{
	int count = 0;
	if(head == 0) {
		printf("linked list is empty\n");
		return -1;
	}
	while(head) {
		if(head->data == key) {
			count++;
		}
		head = head->next;
	}
	return count;
}


void print(Node *head)
{
	if(head == NULL){
		printf("Node deleted\n");
		return;
	}
	while(head) {
		printf("%d ", head->data);
	//	return (print(head->next));
		head= head->next;
	}
}

int main()
{
	Node *head= NULL;
	char ch;
	do {
		add_end(&head);
		printf("Do you want to add another node\n");
		scanf(" %c", &ch);
	} while(ch == 'y' ||  ch == 'Y');
	print(head);
	int key, count;
	printf("which key you want to count\n");
	scanf("%d", &key);
	count = countKey(head, key);
	printf("%d is the count\n", count);
	printf("\n");
}

