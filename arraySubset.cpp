/* FIND THE SUBSET OF AN ARRAY */

#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int size)
{
	for(int i=0; i<size; i++)
		cout << arr[i] << "\t";
	cout << endl;
}

bool IsfindSubset(int arr1[], int arr2[], int size1, int size2)
{
	int i = 0, j = 0;
	if(size1 < size2)
		return 0;

	sort(arr1, arr1+size1);
	cout << "Printing 1st array" << endl;
	print(arr1, size1);
	sort(arr2, arr2+size2);
	cout << "Printing 2nd array" << endl;
	print(arr2, size2);
	cout << endl;

	while(j < size2 && i < size1) {
		if(arr1[i] < arr2[j])
			i++;
		else if(arr1[i] == arr2[j]) {
			i++;
			j++;
		} else
			return 0;
	}
	return (j < size2) ? 0 : 1;
}

int main()
{
	int arr1[] = {8, 7, 1, 4, 10, 5, 11};
	int arr2[] = {5, 7, 10, 8, 4};

	int size1 = sizeof(arr1)/ sizeof (arr1[0]);
	int size2 = sizeof(arr2)/ sizeof(arr2[0]);

	if(IsfindSubset(arr1, arr2, size1, size2)) {
		cout << "array2 is subset of array1" << endl;
	}	else  {
		cout << "array2 is not the subset of array1" << endl;
	}
	return 0;
}
