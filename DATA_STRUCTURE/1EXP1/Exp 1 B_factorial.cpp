
#include<stdio.h>
int factorial(int n)
{
	if(n==0)
	{
		return 1;
	}
	return n*factorial(n-1);
}
int main()
{
	int n;
	printf("Enter a positive integer:");
	do
	{
		scanf("%d",&n);
		if(n<0)
		{
			printf("(invalid)Enter a positive integer:");
		}
	}
	while(n<0);
	printf("The factorial of %d is %d\n",n,factorial(n));
	return 0;
}
