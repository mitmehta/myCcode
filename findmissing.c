#include<stdio.h>

int findMissing(int arr[], int size)
{
	int i;
	int x = arr[0], y = 1;
	for(i = 1; i < size; i++)
		x = x^arr[i];

	for(i = 2; i <= size+1; i++)
		y = y^i;
	int res = x^y;
	return res;
}

int main()
{
	int arr[]  = {1, 2, 3, 5, 6, 8, 7};
	int size = sizeof (arr)/sizeof (arr[0]);
	int i;
	for(i=0; i<size; i++)
		printf("%d\t", arr[i]);
	int res = findMissing(arr, size);
	printf("\nMissing no is %d\n", res);
	return 0;
}
