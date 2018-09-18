#include<bits/stdc++.h>
#include<map>
#include<iterator>
using namespace std;

void findFreqEle(int arr[], int size)
{
	map <int, int> hm;
	for(int i=0; i<size; i++)
		hm[arr[i]]++;
	for(auto x : hm)
		cout << "frequence of " << x.first << "-->"
			<< x.second << endl;
}

int main()
{
	int arr[] = {2, 1, 3, 2, 1, 5, 4, 3, 5, 4, 4, 1, 0, 2};
	int size = sizeof (arr)/ sizeof (arr[0]);

	findFreqEle(arr, size);
	return 0;
}
