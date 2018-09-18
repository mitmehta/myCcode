#include<iostream>
using namespace std;

int max_sum_subarray(int arr[], int size)
{
	int max_so_far = arr[0];
	int curr_max = arr[0];
	for(int i = 1; i < size; i++) {
		curr_max = max(arr[i], curr_max + arr[i]);
		max_so_far = max(max_so_far, curr_max);
	}
}

int main()
{
	int arr[] = {-2, -3, 4, -1, -2, 5, -3};
	int size = sizeof (arr)/ sizeof(arr[0]);
	int max_sum = max_sum_subarray(arr, size);
	cout << "max_sum"  << " "<< max_sum << endl;
	return 0;
}

