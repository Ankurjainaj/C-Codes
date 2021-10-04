#include<stdio.h>
#include<stdlib.h>
BinarySearch(int *a,int l,int h,int x)
{
	int m;
	if(l==h)
	{
		if(a[l]==x)
			return(l);
	}
	else
	{
		m=((l+h)/2);
		if(a[m]==x)
			return m;
		else if(a[m]>x)
			return(BinarySearch(a,l,m-1,x));
		else
			return (BinarySearch(a,m+1,h,x));
	}
	return 1;
}
void main()
{
	int n,i,x,p;
	int *a;
	printf("Enter the size of the array");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched:");
	scanf("%d",&x);
	p=BinarySearch(a,0,n,x);
	if(p==-1)
		printf("Element not found");
	else
		printf("Element found at: %d",p);
}
