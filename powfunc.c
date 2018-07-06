#include<stdio.h>
int powerFunction(int x, int y)
{
	int temp;
	if(y == 0)
		return 1;
	temp = powerFunction(x, y/2);
	if(y%2 == 0)
		return temp*temp;
	else
		return x*temp*temp;
}

int main()
{
	int x = 2;
	unsigned int y = 4;

	printf("Power - %d\n", powerFunction(x, y));
	return 0;
}

