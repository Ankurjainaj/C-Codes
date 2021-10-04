#include<stdio.h>
#include<stdlib.h>
LinearSearch(int *a,int n,int x)
{
	int i;
	for(i=0;i<n;i++)
		if(a[i]==x)
			return x;
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
	p=LinearSearch(a,n,x);
	if(p==-1)
		printf("Element not found");
	else
		printf("Element found at: %d",p);
}
