#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}

int partition(int *a,int l,int h)
{
	int pivot=a[h];
	int i=l-1,j;
	for(j=l;j<h;j++)
	{
		if(a[j]<=pivot)
		{
			i=i+1;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[h]);
	return(i+1);
}
Selection_k_smallest(int *a,int i,int j,int k)
{
	int m;
	if(i==j)
	{
		if(i==k)
			return(a[i]);
		else
			return(-1);
	}
	else
	{
		m=partition(a,i,j);
		if(k==m)
			return(a[m]);
		else if(k<m)
			return(Selection_k_smallest(a,i,m-1,k));
		else
			return(Selection_k_smallest(a,m+1,j,k));
	}
}
void main()
{
	int n,i,x,k;
	int *a;
	printf("Enter the size of the array");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the k value:");
	scanf("%d",&k);
	x=Selection_k_smallest(a,0,n,k);
	printf("The %dth biggest element is: %d",k,x);
}
