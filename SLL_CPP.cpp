#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

typedef struct node {
	int data;
	struct node *next;
}Node;

class single_llist {
public:
	Node *head = NULL;
	Node *createNode(int);
	void insert_begin();
	void display();
};

int main()
{
single_llist sl;
sl.head = NULL;
char ch;
cout << "operation on linked list......" <<endl;
cout <<"Insert at the begining "<< endl;
do{
sl.insert_begin();
cout <<endl;
cout << "Do you want to add another node" <<endl;
cin>>ch;
} while((ch =='y')||(ch =='Y'));
cout<<"displaying linked list "<<endl;
sl.display();
}

Node *single_llist::createNode(int value)
{
	Node *newnode;
	newnode = new(Node);
	if(newnode == NULL) {
		cout << "memory not allocated" <<endl;
		return 0;
	} else {
		newnode->data = value;
		newnode->next = NULL;
		return newnode;
	}
}

void single_llist::insert_begin()
{
	int value;
	Node *temp ;
	temp = createNode(value);
	if(head == NULL) {
		head = temp;
	} else {
		temp->next = head->next;
		head->next = temp;
	}
}

void single_llist::display()
{
	Node *temp;
	if (head == NULL)
	{
		cout<<"The List is Empty"<<endl;
		return;
	}
	temp = head;
	cout<<"Elements of list are: "<<endl;
	while (temp != NULL)
	{
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"NULL"<<endl;
}

