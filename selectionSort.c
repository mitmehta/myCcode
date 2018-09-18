/* selection Sorting */

#include<stdio.h>

void swap(int *arr1, int *arr2)
{
int temp = *arr1;
*arr1 = *arr2;
*arr2 = temp;
}

void selectionSort(int arr[], int size)
{
	int i, j, minIdx;
	for(i=0; i < size-1; i++)
	{
		minIdx = i;
		for(j = i+1; j < size; j++)
		{
			if(arr[j] < arr[minIdx])
				minIdx = j;
			swap(&arr[minIdx], &arr[i]);
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
	selectionSort(arr, size);

	printf("\n\nAfter sorting, the array is\n");
	printArray(arr, size);
	printf("\n");
	return 0;
}

