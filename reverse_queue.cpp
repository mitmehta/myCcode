#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print_queue(queue<int> &que)
{
	while(! que.empty()) {
		cout << que.front() << " ";
		que.pop();
	}
}

void reverse_queue(queue<int> &que)
{
	stack<int> s;
	while(! que.empty()) {
		s.push(que.front());
		que.pop();
	}
	while(! s.empty()) {
		que.push(s.top());
		s.pop();
	}
}

int main()
{
	queue<int> que;
	que.push(10);
	que.push(20);
	que.push(30);
	que.push(40);
	que.push(50);
	que.push(60);
	
	cout << "queue after reversing" << endl;
	reverse_queue(que);
	print_queue(que);
	cout << endl;
}
