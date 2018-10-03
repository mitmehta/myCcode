#include<iostream>
using namespace std;

void ArrayRotate(int arr[], int n)
{
	int temp = arr[n-1];

	for(int i = n-1; i > 0; i--)
		arr[i] = arr[i-1];

	arr[0] = temp;
}


void printArray(int arr[], int n)
{
	for(int i=0;i<n;i++) 
		cout << arr[i]<<"  ";
	cout<<endl;
}
int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<"Print Array before Rotation" << endl;
	printArray(arr, n);
	ArrayRotate(arr, n);
	cout<<"Print Array after Rotation" << endl;
	printArray(arr, n);
}
