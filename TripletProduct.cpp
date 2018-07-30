#include<iostream>
#include<algorithm>
using namespace std;

int productTriplet(int arr[], int n)
{
	if(n < 3)
		return -1;
	sort(arr, arr+n);
	return max((arr[0]* arr[1]* arr[n-1]), (arr[n-1]*arr[n-2]*arr[n-3]));
}

int main()
{
	int arr[] = {-11, 6, 4, 7, -10, 3};
	int size = sizeof(arr)/ sizeof (arr[0]);
	int res = productTriplet(arr, size);
	cout << "Maximum triplet product found : "<<res<<endl;
	return 0;
}
