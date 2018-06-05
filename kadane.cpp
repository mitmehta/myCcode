/* kadane Algorithm:
 * largest sum contigous array
 * */

#include<iostream>
#include<climits>

using namespace std;

int maxSumArray(int arr[], int n)
{
	int max_so_far = INT_MIN, max_ending_here = 0;
	for(int i =0; i<n; i++)
	{
		max_ending_here = max_ending_here + arr[i];
		if(max_so_far < max_ending_here)
			max_so_far = max_ending_here;

		if(max_ending_here < 0)
			max_ending_here = 0;

	}
		return max_so_far;
}
int main()
{
	int arr[] = {-3, -2, 4, 1, 5, -4, 1};
	int n = sizeof (arr)/ sizeof (arr[0]);

	int max_sum = maxSumArray(arr, n);
	cout << "summation of sub array: " << max_sum << endl;
	return 0;
}
