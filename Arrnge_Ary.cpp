#include<iostream>
using namespace std;

void printArray(int arr[], int n)
{
	for(int i =0; i < n; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void arrng_Array(int arr[], int n) 
{
int x_space=0;
for(int i=0 ;i < n; i++) {
if(arr[i] != 0) {
arr[x_space++] = arr[i];
}
}
while(x_space < n) 
arr[x_space++] = 0;
}

void ModifiedArray(int arr[], int n) 
{
	int i;
	for(i=0; i < n-1; i++) {
		if(arr[i] != 0 && (arr[i] == arr[i+1])) {
			arr[i] = 2*arr[i];
			arr[i+1] = 0;
			i++;
		}
	}
	arrng_Array(arr, n);
}

int main()
{
	int arr[] = {0, 2, 2, 2, 0, 6, 6, 6, 0, 0, 8};
	int n = sizeof (arr)/ sizeof (arr[0]);

	cout << "before Arranging Array is: " << endl;
	printArray(arr, n);

	ModifiedArray(arr, n);

	cout << "After Arranging Array is: " << endl;
	printArray(arr, n);
}
