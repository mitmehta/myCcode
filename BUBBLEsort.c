/* Bubble Sorting */

#include<stdio.h>

void swap(int *arr1, int *arr2)
{
int temp = *arr1;
*arr1 = *arr2;
*arr2 = temp;
}

void bubbleSort(int arr[], int size)
{
	int i, j;
	for(i = 0; i < size; i++) {
		for(j = 0; j < size-i-1; j++) {
			if(arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
		}
	}
}

void printArray(int arr[], int size)
{
	int i;
	for(i = 0; i < size ; i++)
		printf("%d\t", arr[i]);

}

int main()
{
	int arr[] = {2, 4, 3, 5, 7, 9, 8, 1};

	int size = sizeof (arr)/sizeof (arr[0]);
	printf("Befor sorting, the array is\n");
	printArray(arr, size);
	bubbleSort(arr, size);

	printf("\n\nAfter sorting, the array is\n");
	printArray(arr, size);
	printf("\n");
	return 0;
}

