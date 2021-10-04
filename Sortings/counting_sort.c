#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
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
void Counting_sort(int *a,int n)
{
	int i,j,max,*c;
	max=findMax(a,n);
	c=(int*)malloc((max+1)*sizeof(int));
	for(i=0;i<max+1;i++)
	{
		c[i]=0;
	}
	for(i=0;i<n;i++)
	{
		c[a[i]]++;
	}
	i=0;
	j=0;
	while(j<max+1)
	{
		if(c[j]>0)
		{
			a[i++]=j;
			c[j]--;
		}
		else
			j++;
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
	Counting_sort(a,n);
	printf("The array elements after sorting are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
}
