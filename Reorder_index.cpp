/* Arrange Array according to given indexex */
#include<iostream>
using namespace std;

void Reorder_Array(int arr[], int index[], int n)
{
	int oldI, newI;

	for(int i = 0; i < n; i++) {
		while(index[i] != i) {
			oldI = index[index[i]];
			newI = arr[index[i]];

			arr[index[i]] = arr[i];
			index[index[i]] = index[i];

			index[i] = oldI;
			arr[i] = newI;
		}
	}
}

void PrintArray(int arr[], int n)
{
	for(int i = 0; i < n; i++) 
		cout << arr[i] << "  ";
	cout << endl;
}

int main()
{
	int arr[] = {50, 40, 10, 30, 20};
	int index[] = {4, 3, 0, 2, 1};
	int n = sizeof (arr)/ sizeof (arr[0]);

	cout << "Print Array before Rearranging" << endl;
	PrintArray(arr, n);

	Reorder_Array(arr, index, n);

	cout << "Print Array After Rearranging" << endl;
	PrintArray(arr, n);
}
