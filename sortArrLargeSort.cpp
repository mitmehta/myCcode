#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int arrangeArray(int arr[], int size)
{
	sort(arr, arr+size);
	int tempArr[size];
	int ArrIdx = 0;
	for(int i = 0, j = size-1 ; i<size/2 || j > size/2; i++, j--) {
		tempArr[ArrIdx++] = arr[i];
		tempArr[ArrIdx++] = arr[j];
	}

	for(int i = 0; i<size; i++)
		arr[i] = tempArr[i];
}

int main()
{
	int arr[] = {5, 1, 3, 2, 8, 9, 7, 6};
	int size = sizeof (arr)/ sizeof (arr[0]);

	arrangeArray(arr, size);

	for(int i = 0; i<size; i++)
		cout << arr[i] << "  ";
	cout << endl;
}
