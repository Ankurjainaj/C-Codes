#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
int partition(int *a, int l, int h)
{
	int pivot=a[l];
	int i=l-1;
	int j=h+1;
	while(1)
	{
		do 
		{
			i++;
		} while(a[i]<pivot);
		do 
		{
			j--;
		} while(a[j]>pivot);
		if(i>=j)
			return j;
		swap(&a[i],&a[j]);
	}
}
void QuickSort(int *a,int l,int h)
{
	int j;
	if(l<h)
	{
		j=partition(a,l,h);
		QuickSort(a,l,j);
		QuickSort(a,j+1,h);
	}
}
void main()
{
	int n,i;
	int *a;
	printf("Enter the size of the array");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	QuickSort(a,0,n);
	printf("The array elements after sorting are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
}


