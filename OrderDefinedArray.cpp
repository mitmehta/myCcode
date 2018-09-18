#include<iostream>
#include<algorithm>
using namespace std;

void sortArray(int arr1[], int arr2[], int m, int n)
{
int temp[m], visited[m];
for(i =0; i<m; i++){
	temp[i] = arr1[i];
	visited[i] = 0;
}
sort(temp, temp+m);


}

int main()
{
int arr1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8, 1};
int arr2[] = {2, 1, 8, 3};
int m = sizeof(arr1)/ sizeof (arr1[0]);
int n = sizeof(arr2)/ sizeof(arr2[0]);

cout << "sorted array is" << endl;
sortArray(arr1, arr2, m, n);
printArray(arr1, m);
}
