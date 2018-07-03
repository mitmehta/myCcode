/* Binary search elemnet*/
#include<stdio.h>

int binarySearchArray(int arr[], int start, int end, int key)
{

	if(end >= start) {
		int mid = start + (end-start)/2;
		if(arr[mid] == key)
			return mid;
		if(arr[mid] < key)
			return(binarySearchArray(arr, mid+1, end, key));
		if(arr[mid] > key)
			return(binarySearchArray(arr, start, mid-1, key));
	}
	return -1;
}

void printArray(int arr[], int size)
{
	int i;
	for(i=0; i<size; i++)
		printf("%d\t", arr[i]);
}

int main()
{
	int arr[] = {1, 5, 7, 8, 9, 14, 15, 21, 28};
	int size = sizeof (arr)/ sizeof(arr[0]);
	int key;
	printArray(arr, size);
	printf("\n\nEnter the key to search\n");
	scanf("%d", &key);
	int pos = binarySearchArray(arr, 0, size-1, key);
	printf("Position of the element in an array is %d\n", pos);
}
