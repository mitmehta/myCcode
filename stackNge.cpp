#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printNGE(int arr[], int n)
{
	stack <int> s;
	s.push(arr[0]);

	for(int i = 0; i<n; i++)
	{
		int next = arr[i];
		if(s.empty() == false) {
			int ele = s.top();
			s.pop();
			while(ele < next) {
				cout << ele << "-->" << next << endl;
				if(s.empty() == true)
					break;
				ele = s.top();
				s.pop();
			}
			if(ele > next)
				s.push(ele);
		}
		s.push(next);
	}
	while(s.empty() == false)
	{
		cout << s.top() << "-->" << -1 << endl;
		s.pop();
	}
}

int main()
{
	int arr[] = {11, 13, 4, 26, 12, 31};
	int n = sizeof (arr)/ sizeof (arr[0]);

	printNGE(arr, n);
	return 0;
}

