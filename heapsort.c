/* Heap sort algorithm for sorting */
#include<stdio.h>
void swap(int *a, int *b)
{
int temp =*a;
*a = *b;
*b = temp;
}

void heapify(int arr[], int size, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l<size && arr[l] > arr[largest])
		largest = l;

	if(r<size && arr[r] > arr[largest])
		largest = r;

	if(largest != i) {
		swap(&arr[i], &arr[largest]);
		heapify(arr, size, largest);
	}
}

void sortarray(int arr[], int size)
{
	int i;
	for(i = size/2 -1; i >= 0; i--)
		heapify(arr, size, i);
	for(i = size-1 ; i>=0; i--) {
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int size)
{
	for(int i=0; i<size; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {6, 3, 20, 11, 14, 15, 9, 17};
	int size = sizeof (arr)/ sizeof (arr[0]);
	printf("size of an array - %d\n", size);
	printf("Before sorting\n");
	printArray(arr, size);
	sortarray(arr, size);
	printf("After sorting\n");
	printArray(arr, size);

	return 0;
}
