/* To find greatest common factor of any two number */

#include<stdio.h>
int  GCfactor(int x, int y)
{
	if(y != 0) {
		return (GCfactor(y, x%y));
	} else {
		return x;
	}
}

int main()
{
	int num1, num2, result;
	printf("please enter two number\n");
	scanf("%d%d", &num1, &num2);
	result = GCfactor(num1, num2);
	printf("Greatest common factor for these two number is %d\n", result);
}
