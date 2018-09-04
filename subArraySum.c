#include<stdio.h>

int sum_subArray(int arr[], int n, int sum)
{
	int i, carrySum=arr[0], start=0;
	for(i=1; i<=n; i++) {
		while(carrySum > sum && start < i-1)
		{
			carrySum = carrySum - arr[start];
			start++;
		}
		if(carrySum == sum) {
			printf("sum found between the index %d and %d...!!!\n", start, i-1);
			return 1;
		}
		if(i<n)
			carrySum = carrySum + arr[i];
	}
	printf("No Sub array found..!!\n");
}

int main()
{
	int arr[]= {10, 2, 5, 11, 5, 19};
	int size = sizeof(arr)/sizeof (arr[0]);
	int sum = 23;
	sum_subArray(arr, size, sum);
	return 0;
}
