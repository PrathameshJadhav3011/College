#include<stdio.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int arr[],int low,int high)
{
	int pivot=arr[high],j;
	int i=(low-1);
	for(j=low;j<=high-1;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
			
		}
	}
	swap(&arr[i+1],&arr[high]);
	return(i+1);
}
void quicksort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pi=partition(arr,low,high);
		quicksort(arr,low,pi-1);
		quicksort(arr,pi+1,high);
	}
}
void insert(int array[],int sizearr)
{
	int i;
	for(i=0;i<sizearr;i++)
	{
		printf("Arr[%d]:",i);
		scanf("%d",&array[i]);
	}
}
void display(int array[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i==n-1)
		{
			printf("%d",array[i]);
		}
		else
		{
			printf("%d",array[i]);
		}
	}
}
int main()
{
	int arr[100],size_arr;
	printf("***Quick sort***\n\n");
	printf("Enter size of array:");
	do
	{
		scanf("%d",&size_arr);
		if(size_arr<=0)
		{
			printf("(invalid)Enter a non-zero NUMBER:");
		}
	}
	while(size_arr<=0);
	printf("\nEnter Data of the following elements:\n");
	insert(arr,size_arr);
	printf("\nOriginal array:");
	display(arr,size_arr);
	quicksort(arr,0,size_arr-1);
	printf("\nSorted array:");
	display(arr,size_arr);
	return 0;
}
