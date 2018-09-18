#include<stdio.h>

void findRepeatNum(int arr[], int size)
{
	int xor = arr[0];
	int set_bit;
	int i;
	int n = size-2;
	for(i=1; i<size; i++)
		xor =xor^arr[i];
	for(i=1; i<=n; i++)
		xor = xor^i;
	set_bit = xor & ~(xor-1);
	printf("%d\n", set_bit);
	int x=0, y=0;
	for(i=0; i<size; i++) {
		if(arr[i] & set_bit)
			x = x^arr[i];
		else
			y = y^arr[i];
	}

	for(i=1; i<=n; i++) {
		if(i & set_bit)
			x = x^i;
		else
			y = y^i;
	}
	printf("%d\t%d is the repeating number\n", x, y);
}

int main()
{
	int arr[] = {4 ,5 ,3, 1, 6, 4, 2, 6};
	int size = sizeof(arr)/ sizeof (arr[0]);

	findRepeatNum(arr, size);
	return 0;
}

