#include<iostream>
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHARS = 26;

string findMissingPangram(string str)
{
	bool Result[MAX_CHARS] = {false};	

	for(int i=0; i<str.length(); i++){
		if(str[i] >= 'A' && str[i] <= 'Z')
			Result[str[i] - 'A'] = true;

		else if(str[i] >= 'a' && str[i] <='z')
			Result[str[i] - 'a'] = true;
	}

	string ele = "";
	for(int i = 0; i < MAX_CHARS; i++)
	{
		if(Result[i] == false)
			ele.push_back((char)(i+'a'));
	}
	return ele;
}

int main()
{
	string str="the quick brwn fx jumps ver the lazy";
	cout << findMissingPangram(str);
	cout << endl;
	return 0;
}

