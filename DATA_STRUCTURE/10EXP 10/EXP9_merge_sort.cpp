#include<stdio.h>
void merge(int arr[],int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	 L[i]=arr[l+i];
	 for(j=0;j<n2;j++)
	  R[j]=arr[m+l+j];
	i=0;
	j=0;
	k=l;
	while(i<n1&&j<n2)
	{
		if(L[i]<=R[j])
		  arr[k++]=L[i++];
		else
		  arr[k++]=R[j++];
	}
	while(i<n1)
	  arr[k++]=L[i++];
	while(j<n2)
	  arr[k++]=R[j++];
}
void mergesort(int arr[],int left,int right)
{
	int m;
	if(left<right)
	{
		m=left+(right-left)/2;
		mergesort(arr,left,m);
		mergesort(arr,m+1,right);
		merge(arr,left,m,right);
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
void display(int*array,int n)
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
			printf("%d,",array[i]);
		}
	}
}
int main()
{
	int arr[100],i,size_arr;
	printf("****merge sort****\n\n");
	printf("Enter size of Array:");
	do
	{
		scanf("%d",&size_arr);
		if(size_arr<=0)
		{
			printf("(invalid)Enter a non-zero Number:");
			
		}
	}while(size_arr<=0);
	printf("\nEnter data for following Elements:\n");
	insert(arr,size_arr);
	printf("\nOriginal array:");
	display(arr,size_arr);
	mergesort(arr,0,size_arr-1);
	printf("\nSorted array:");
	display(arr,size_arr);
	return 0;
}
