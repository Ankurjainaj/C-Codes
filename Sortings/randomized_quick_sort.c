#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
void QuickSort(int *a,int l,int h)
{
    if(l<h) 
	{
        int pivot=l;
    	pivot=rand()%(h-l)+l;
    	pivot=partition(a,l,h,pivot);
        QuickSort(a,l,pivot);
        QuickSort(a,pivot+1,h);
    }
}      
int partition(int *a,int l,int h,int pivot)
{
    int i,t,next,next1;
    t=a[pivot];
    a[pivot]=a[l]; 
    a[l]=t;
    pivot=l;
    next=l+1;
    while(next<=h)
	{
        if(a[next]>a[pivot])
		{
            t = a[next];
        	next1=next;
        	while(next1!=pivot+1)
			{
                a[next1]=a[next1-1];
                next1--;
            }
            a[next1]=a[pivot];
            a[pivot]=t;
            pivot++;
        }
            next++;
    }
return pivot;   
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
	QuickSort(a,0,n);
	printf("The array elements after sorting are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
}
