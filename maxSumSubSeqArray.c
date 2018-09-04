#include<stdio.h>

int subSeqSumArray(int arr[], int n)
{
	int sArr[n];
	int i, j, max = 0;
	for(i=0; i < n; i++)
		sArr[i] = arr[i];

	for(i = 1; i < n; i++) {
		for(j = 0; j < i; j++) {
			if((arr[i] > arr[j]) && sArr[i] < sArr[j] + arr[i])
				sArr[i] = sArr[j] + arr[i];
		}
	}

	for(i=0; i < n; i++)
		if(max < sArr[i])
			max = sArr[i];

	return max;
}

int main()
{
	int arr[] = {1, 101, 2, 3, 100, 4, 5};
	int size = sizeof (arr)/ sizeof (arr[0]);
	int Result = subSeqSumArray(arr, size);
	printf("sum of subseqArray:- %d\n", Result);
}
