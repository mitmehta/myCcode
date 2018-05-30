#include<stdio.h>
int fact(int num)
{
	if(num == 0)
		return 1;
	return(num * fact(num-1));

}

int main()
{
	int num, result;
	printf("Enter the number\n");
	scanf("%d", &num);
	result = fact(num);
	printf("factorial of num = %d\n", result);
}

