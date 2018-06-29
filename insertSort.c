/* Insertion Sorting */

#include<stdio.h>

void insertSort(int arr[], int size)
{
	int i, j , key;
	for(i = 1; i < size ; i++) {
		key = arr[i];
		j = i-1;
		while(j>=0 && key < arr[j]) {
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
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
	insertSort(arr, size);

	printf("\n\nAfter sorting, the array is\n");
	printArray(arr, size);
	printf("\n");
	return 0;
}

