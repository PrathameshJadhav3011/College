#include<stdio.h>
int swap(int*xp,int*yp)
{
	int temp=*xp;
	*xp=*yp;
	*yp=temp;
}
void selectionsort(int*arr,int n)
{
	int i,j,min_idx;
	for(i=0;i<n-1;i++)
	{
		min_idx=i;
		for(j=i+1;j<n;j++)
		if(arr[j]<arr[min_idx])
		   min_idx=j;
		swap(&arr[min_idx],&arr[i]);
	}
}
void display(int*arr,int size)
{
	int i;
    for(i=0;i<size;i++)
      printf("%d",arr[i]);
}
void insert(int*arr,int size)
{
	int i;
	printf("\nEnter data for following Elements\n");
	for(i=0;i<size;i++)
	{
		printf("Arr[%d]:",i);
		scanf("%d",&arr[i]);
	}
}
int main()
{
	int arr[50],size_arr;
	printf("***Selection sort***\n\n");
	printf("Enter size of array:");
	do
	{
		scanf("%d",&size_arr);
		if(size_arr<=0)
		{
			printf("(invalid)Enter a non-zero number:");
			
		}
		
		insert(arr,size_arr);
		printf("\nOriginal array:");
		display(arr,size_arr);
		selectionsort(arr,size_arr);
		printf("\nSorted array:");
		display(arr,size_arr);
		return 0;
	
	}while(size_arr<=0);
}
