#include<iostream>
#include<map>
#include<string>
using namespace std;

void printticket(map<string, string> dataset )
{
	map<string, string> reversemap;
	map<string, string>::iterator it;

	for(it = dataset.begin(); it != dataset.end(); it++)
		reversemap[it->second] = it->first;

	string start;
	for(it = dataset.begin(); it != dataset.end(); it++)
	{
		if(reversemap.find(it->first) == reversemap.end())
		{
			start = it->first;
			break;
		}
	}

	if(start.empty())
	{
		cout << "Invalid input" << endl;
		return;
	}
	it = dataset.find(start);
	while(it != dataset.end())
	{
		cout << it->first << "->" << it->second << endl;
		it = dataset.find(it->second);
	}
}

int main()
{
	map<string, string> dataset;
	dataset["chennai"] = "bangalore";
	dataset["bombay"] = "Delhi";
	dataset["goa"] = "chennai";
	dataset["Delhi"] = "goa";

	printticket(dataset);
	return 0;
}
