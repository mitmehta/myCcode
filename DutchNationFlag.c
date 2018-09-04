#include<stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a=*b;
	*b = temp;
}

void sortArray012(int arr[], int size)
{
	int low = 0;
	int high = size-1;
	int mid = 0;
	while(mid <= high) 
	{
		switch(arr[mid]) {
			case 0:
				swap(&arr[low++], &arr[mid++]);
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(&arr[mid], &arr[high--]);
				break;
		}
	}
	return;
}

void printArray(int arr[], int n)
{
	int i;
	for(i=0; i<n; i++) 
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = {1, 0, 0, 1, 2, 1, 0, 1, 1, 2, 2, 1};
	int size = sizeof (arr)/ sizeof(arr[0]);

	printf("Print array before Resizing..!!!\n");
	printArray(arr, size);

	sortArray012(arr, size);

	printf("Print array  after Resizing..!!!\n");
	printArray(arr, size);

	return 0;
}
