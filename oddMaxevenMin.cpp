#include<iostream>
#include<algorithm>
using namespace std;

void sortArray(int arr[], int size)
{
	for(int i =0; i<size; i++)
		if(arr[i] & 1)
			arr[i] = arr[i] * (-1);
	sort(arr, arr+size);
	for(int i =0; i<size; i++)
		if(arr[i] & 1)
			arr[i] = arr[i] * (-1);

}

void printArray(int arr[], int size)
{
for(int i =0; i<size; i++)
	cout << arr[i] << "  ";
cout << endl;
}

int main()
{
	int arr[] = {8, 1, 3, 4, 5, 2, 7, 9};
	int n = sizeof (arr)/sizeof (arr[0]);

	cout << "Before sorting, array is"<< endl;
	printArray(arr, n);
	sortArray(arr, n);
	cout << "After sorting print the array" <<endl;
	printArray(arr, n);
	return 0;
}


