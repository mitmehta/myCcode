#include<stdio.h>

void reversearr(int arr[], int start, int end)
{
if(start >= end)
	return;
int temp = arr[start];
arr[start ] = arr[end];
arr[end] = temp;

reversearr(arr, start+1, end-1);
}


void printArray(int arr[], int size)
{
	int i;
	for(i = 0; i<size; i++)
		printf("%d\t", arr[i]);

}


int main()
{
int arr[] = {1, 2, 3, 4, 5, 6};
int size = sizeof(arr)/sizeof(arr[0]);
printArray(arr, size);
printf("\n\n");
reversearr(arr, 0, size-1);
printArray(arr, size);
printf("\n");
}
