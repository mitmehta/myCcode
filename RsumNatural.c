/* sum of natural numbers */

#include<stdio.h>

int SumNatural(int num)
{
if(num == 0)
	return num;
return (num + SumNatural(num-1));
}

int main()
{
	int num, res;
	printf("Enter the number....\n");
	scanf("%d", &num);
	res = SumNatural(num);
	printf("Sum of natural number is %d\n", res);
	return 0;
}
