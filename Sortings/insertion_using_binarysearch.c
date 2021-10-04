#include<stdio.h>
#include<stdlib.h>
BinarySearch(int *a,int l,int h,int x)
{
	int m;
	if(h<=l)
		return(x>a[l])? (l+1):l;
	m=(l+h/2);
	if(x==a[m])
		return m+1;
	if(x>a[m])
		return(BinarySearch(a,m+1,h,x));
	return(BinarySearch(a,l,m-1,x));
}
Insertion_sort(int *a,int n)
{
	int j,key,i,l;
	for(i=1;i<n;i++)
	{
		j=i-1;
		key=a[i];
		l=BinarySearch(a,0,j,key);
		while(j>=l)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
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
