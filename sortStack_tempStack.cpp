#include<iostream>
#include<bits/stdc++.h>
using namespace std;
stack<int> sortStack(stack<int> &rs)
{
	stack<int> st;
	while(!(rs.empty())) {
		int temp = rs.top();
		rs.pop();
		while(!(st.empty()) && st.top() > temp) {
			rs.push(st.top());
			st.pop();
		}
		st.push(temp);
	}
	return st;
}

void printStack(stack<int> rs)
{
	while(!(rs.empty())) {
		cout << rs.top() << "-->" << endl;
		rs.pop();
	}
}

int main()
{
	stack <int> rs;
	rs.push(11);
	rs.push(34);
	rs.push(22);
	rs.push(51);
	rs.push(9);
	rs.push(19);
	printStack(rs);

	stack <int> ts = sortStack(rs);
	cout << "after sorting, STack is" << endl;
	printStack(ts);
}
