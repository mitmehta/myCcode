#include<iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
	int i, j, k;
	int n1 = mid-start +1;
	int n2 = end - mid;

	int leftA[n1], rightA[n2];

	for(i=0; i<n1; i++)
		leftA[i] = arr[start + i];
	for(j = 0; j<n2; j++)
		rightA[j] = arr[mid+1 + j];
	i =0;
	j = 0;
	k = start;

	while(i<n1 && j<n2)
	{
		if(leftA[i] <= rightA[j]) {
			arr[k] = leftA[i];
			i++;
		} else {
			arr[k] = rightA[j];
			j++;
		}
		k++;
	}

	while(i < n1) {
		arr[k] = leftA[i];
		i++;
		k++;
	}
	while(j < n2) {
		arr[k] = rightA[j];
		j++;
		k++;
	}

}

void mergesort(int arr[], int start, int end)
{
	if(start < end) {
		int mid = start + (end-start)/2;
		mergesort(arr, start, mid);
		mergesort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int main()
{
int arr[] = {10, 24, 13, 31, 22, 15};
int size = sizeof (arr)/sizeof (arr[0]);

cout << "Before sorting, element is : " <<endl;
for(int i = 0; i<size; i++)
	cout << arr[i] << "  ";
cout << endl;

mergesort(arr, 0, size-1);
cout << "After sorting, element is : " <<endl;
for(int j = 0; j<size; j++)
	cout << arr[j] << "  ";
cout << endl;
}
