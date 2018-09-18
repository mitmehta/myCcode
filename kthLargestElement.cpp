#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int largestElement(int arr[], int n, int k)
{
	sort(arr, arr+n, greater<int>());
	for(int i = 0; i<k; i++)
		cout << arr[i] << "  ";
	cout << endl;
}

int main()
{
	int arr[] = {7, 8, 1, 2, 14, 9, 10, 3};
	int size = sizeof(arr)/ sizeof (arr[0]);
	int k =3;

	largestElement(arr, size, k);
	return 0;
}

