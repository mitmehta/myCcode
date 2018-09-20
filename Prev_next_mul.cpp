#include<iostream>

using namespace std;

void ModifyArray(int arr[], int n)
{
	int prev = arr[0], curr;
	arr[0] = prev * arr[1];
	for(int i = 1; i < n-1 ; i++) {
		curr = arr[i];
		arr[i] = prev * arr[i+1];
		prev = curr;
	}
	arr[n-1] = prev * arr[n-1];
}

void printArray(int arr[], int n)
{
	for(int i =0; i < n; i++)
		cout << arr[i] << "  ";
	cout << endl;
}

int main()
{
	int arr[] = {2, 3, 4, 5, 6};
	int size = sizeof (arr)/sizeof (arr[0]);

	cout << "Print Element of array before Arrangement: " << endl;
	printArray(arr, size);

	ModifyArray(arr, size);

	cout << "Print Element of array After Arrangement: " << endl;
	printArray(arr, size);
	return 0;
}
