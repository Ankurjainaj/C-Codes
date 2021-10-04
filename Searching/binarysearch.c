#include<stdio.h>
#include<stdlib.h>
BinarySearch(int *a,int n,int x)
{
	int l,m,h;
	l=0;
	h=n-1;
	while(l<=h)
	{
		m=(l+h/2);
		if(x==a[m])
			return m;
		else if(x<a[m])
			h=m-1;
		else
			l=m+1;
	}
	return -1;
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
	p=BinarySearch(a,n,x);
	if(p==-1)
		printf("Element not found");
	else
		printf("Element found at: %d",p);
}
