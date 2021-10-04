#include<stdio.h>
#include<stdlib.h>
Insertion_sort(int *a,int n)
{
	int j,key,i;
	for(j=1;j<n;j++)
	{
		key=a[j];
		i=j-1;
		while(i>-1 && a[i]>key)
		{
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
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
	Insertion_sort(a,n);
	printf("The array elements after sorting are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
}
