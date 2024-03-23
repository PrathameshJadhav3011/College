
#include<stdio.h>
#define MAX 10
void readMatrix(int n,int matrix[][MAX])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("M[%d][%d]:",i,j);
			scanf("%d",&matrix[i][j]);
			
		}
	}
}
void multiplyMatrices(int n,int A[][MAX],int B[][MAX],int C[][MAX])
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			C[i][j]=0;
			for(k=0;k<n;k++)
			{
				C[i][j]+=A[i][k]*B[k][j];
				
			}
		}
	}
}
void printMatrix(int n,int matrix[][MAX])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d",matrix[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int n, A[MAX][MAX],B[MAX][MAX],C[MAX][MAX];
	printf("Enter size of the Matrices(MAX:10):");
	do
	{
		scanf("%d",&n);
		if(n<=0)
		 printf("(invalid)Enter a non-zero number:");
	}
	while(n<=0);
	printf("\nEnter Elements for first Matrix:\n");
	readMatrix(n,A);
	printf("\nEnter Elements for second Matrix:\n");
	readMatrix(n,B);
	multiplyMatrices(n,A,B,C);
	printf("\nResult After Multiplying Two matrices:\n");
	printMatrix(n,C);
	return 0;
}
