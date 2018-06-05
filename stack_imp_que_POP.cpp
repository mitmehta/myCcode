#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Stack
{
	queue<int> q1, q2;
	int curr_size;

public:
	Stack()
	{
		curr_size = 0;
	}

	void push(int x)
	{
		q1.push(x);
		curr_size++;
	}

	void pop()
	{
		if(q1.empty())
			return;

		while(q1.size() != 1) {
			q2.push(q1.front());
			q1.pop();
		}

		q1.pop();
		curr_size--;

		//swap the name
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
	}
	int top()
	{
		if(q1.empty())
			return -1;

		while(q1.size() != 1)
		{
			q2.push(q1.front());
			q1.pop();
		}

		int temp = q1.front();
		q1.pop();
		q2.push(temp);

		queue<int> q = q1;
		q1 = q2;
		q2 = q;
		return temp;
	}

	int size()
	{
		return curr_size;
	}
};

int main()
{
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	cout << "current size : " << s.size() << endl;
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << "current size : " << s.size() << endl;
}
