#include<iostream>
#include<algorithm>
using namespace std;

int countArray(int arr[], int n, int k)
{
	int count = 0;
	sort(arr, arr+n);
	int l = 0;
	int r = 0;
	while(r<n) {
		if(arr[r] - arr[l] == k){
			count++;
			r++;
			l++;
		} else if(arr[r] - arr[l] > k)
			l++;
		else
			r++;
	}
	return count;
}

int main()
{
int arr[] = {5, 1, 2, 7, 3, 8, 9, 11};
int size = sizeof (arr)/sizeof (arr[0]);
int k = 4;
cout << "count of difference of element:-" << countArray(arr, size, k);
cout << endl;
return 0;
}
