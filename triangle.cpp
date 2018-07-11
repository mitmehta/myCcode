#include<iostream>
#include<algorithm>
using namespace std;

bool FormTriangle(int arr[], int n)
{
	if(n<3)
		return false;
	sort(arr, arr+n);
	for(int i=0; i<n-2; i++)
		if(arr[i], arr[i+1] > arr[i+2]);
	return true;
}

int main()
{
	int arr[] = {5, 3, 4, 1, 2};
	int  n = sizeof(arr)/sizeof (arr[0]);

	if(FormTriangle(arr, n))
	{
		cout << "Yes, Triangle can b formed" << endl;
	}
	return 0;
}

