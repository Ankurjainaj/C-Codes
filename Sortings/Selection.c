#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
Selection_sort(int *a ,int n)
{
	int i,j,k;
	for(i=0;i<n-1;i++)
	{	
		for(j=k=i;j<n;j++)
		{
			if(a[j]<a[k])
				k=j;	
		}
		swap(&a[i],&a[k]);
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
	Selection_sort(a,n);
	printf("The array elements after sorting are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
}
