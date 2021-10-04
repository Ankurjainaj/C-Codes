#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
void Merge(int a[],int l,int m,int h)
{
	int i=l,j=m+1,k=l;
	int b[100];
	while(i<=m && j<=h)
	{
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	for(;i<=m;i++)
	{
		b[k++]=a[i];
	}
	for(;j<=h;j++)
	{
		b[k++]=a[j];
	}
	for(i=l;i<=h;i++)
	{
		a[i]=b[i];
	}
}

void MergeSort(int *a,int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		MergeSort(a,l,m);
		MergeSort(a,m+1,h);
		Merge(a,l,m,h);
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
	MergeSort(a,0,n);
	printf("The array elements after sorting are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
}
