/* linear search */
#include<stdio.h>

int linearSearchArray(int arr[], int size, int key)
{
	int i;
	for(i = 0; i<size; i++) {
		if(arr[i] == key)
			return i;
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
	int arr[] = {1, 5, 7, 8, 9, 14, 15, 21, 18};
	int size = sizeof (arr)/ sizeof(arr[0]);
	int key;
	printArray(arr, size);
	printf("\n\nEnter the key to search\n");
	scanf("%d", &key);
	int pos = linearSearchArray(arr, size, key);
	printf("Position of the element in an array is %d\n", pos);
}
