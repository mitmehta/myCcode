#include<stdio.h>

void findLeaderArray(int arr[], int size)
{
	int right = arr[size-1];
	int i;
	printf("Leader of this array are following\n%d\t", right);
	for(i = size-2; i>=0; i--) {
		if(right < arr[i]) {
			right = arr[i];
			printf("%d\t", right);
		}
	}
	printf("\n\n");
}


int main()
{
	int arr[] = {1, 2, 9, 3, 7, 5, 4};
	int size = sizeof(arr)/sizeof(arr[0]);
	findLeaderArray(arr, size);
	return 0;
}
