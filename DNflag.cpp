#include<iostream>
using namespace std;
void swap(int *a, int *b)
{
	int temp = *a;
	*a =*b;
	*b = temp;
}

void sort012(int arr[], int size)
{
	int low =0;
	int mid = 0;
	int high = size-1;
	while(mid <= high) {
		switch (arr[mid]) {
		case 0:
			swap(&arr[low], &arr[mid]);
			low++, mid++;
			break;

		case 1:
			mid++;
			break;

		case 2:
			swap(&arr[mid], &arr[high]);
			high--;
			break;
		}
	}
}

int main()
{
	int arr[] = {0, 1, 1, 2, 0, 2, 1, 0, 0, 0, 1, 2, 1, 1, 0};
	int size = sizeof(arr)/sizeof(arr[0]);


	cout << "Before Arranging\n" ;
	for(int i =0; i<size; i++)
		cout << arr[i] << "  ";
	cout << endl;

	sort012(arr, size);

	cout << "Before Arranging\n" ;
	for(int j =0; j<size; j++)
		cout << arr[j] << "  ";
	cout << endl;
}
