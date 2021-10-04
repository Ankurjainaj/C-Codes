#include<stdio.h>
#include<stdlib.h>
DAC_min_max(int *a,int min,int max,int i,int j)
{
	int mid=0,min1=0,max1=0;
	if(i==j)
	{
		max=min=a[i];
	}
	if(i==j-1)
	{
		if(a[i]<a[j])
		{
			max=a[j];
			min=a[i];
		}
		else
		{
			max=a[i];
			min=a[j];
		}
	}
	else
	{
		mid=(i+j)/2;
		DAC_min_max(a,min1,max1,i,mid);
		DAC_min_max(a,min,max,mid+1,j);
		if(max1>max)
			max=max1;
		if(min1<min)
			min=min1;
	}
}
void main()
{
	int n,i,min,max;
	int *a;
	printf("Enter the size of the array");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	DAC_min_max(a,min,max,1,n);
	printf("The min and max element of the array are:%d  %d",min,max);
}
