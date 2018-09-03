#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkPangram(string &str)
{
	vector<bool> mark(26, false);
	int index;

	for(int i=0; i<str.length(); i++){
		if(str[i] >= 'A' && str[i] <= 'Z')
			index = str[i] - 'A';

		else if(str[i] >= 'a' && str[i] <='z')
			index = str[i] - 'a';

		mark[index] = true;
	}

	for(int i = 0; i < 26; i++)
	{
		if(mark[i] == false)
			return false;
	}
	return true;
}

int main()
{
	string str="the quick brown fox jumps over the lazy dog";
	if(checkPangram(str) == true)
	{
		printf("The given string is pangram\n");
	} else {
		printf("The given string is not pangram\n");
	}
	return 0;
}

