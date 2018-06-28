#include<stdio.h>
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void rearrange(int arr[], int size)
{
	int pivot = 0;
	int i=-1, j;
	for(j= 0; j<size; j++) {
		if(arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	int neg = 0;
	int pos = i+1;
	while(neg < pos && pos < size && arr[neg] < 0) {
		swap(&arr[neg], &arr[pos]);
		pos = pos+1;
		neg = neg+2;
	}
}
void printarr(int arr[], int size)
{
	int i;
for(i = 0; i < size; i++)
	printf("%d\t", arr[i]);

}

int main()
{
	int arr[] = {3, 1, -2, -4, 5, -6, 7, -1, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	printarr(arr, n);
	rearrange(arr, n);
	printf("\n");
	printarr(arr, n);
	printf("\n");
}
