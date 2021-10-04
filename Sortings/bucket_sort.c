#include <stdio.h>
#include<stdlib.h>
int findMax(int *a,int n)
{
	int max=0;
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}
Bucket_sort(int *a,int n) 
{
	int *aux;
	int i,j,m;
	m=findMax(a,n);
	aux=(int*)malloc(m*sizeof(int));
	for(i=0;i<=m;i++) 
	{
		aux[i]=0;
	}
	for(i=0;i<n;i++) 
	{
		aux[a[i]]++;
	}
	for(i=0,j=0;i<=m;i++)
	{
		for(;aux[i]>0;(aux[i])--) 
		{
			a[j]=i;
			j++;
		}
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
	Bucket_sort(a,n);
	printf("The array elements after sorting are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
}
