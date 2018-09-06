#include<iostream>
using namespace std;

void reverseRecursive(int arr[], int n, int k)
{
	for(int i=0; i<n; i+=k)
	{
		int left = i;
		int right = min(i+k-1, n-1);
		while(left < right)
			swap(arr[left++], arr[right--]);
	}
}

void printArray(int arr[], int n)
{
	for(int i=0; i<n; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof (arr)/ sizeof (arr[0]);
	int k =3;
	cout<<"Print Array before reverse....!!!\n" << endl;
	printArray(arr, n);
	reverseRecursive(arr, n, k);
	cout<<"Print Array after reverse....!!!\n" << endl;
	printArray(arr, n);
	return 0;
}

