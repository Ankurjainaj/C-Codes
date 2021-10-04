#include<stdio.h>
#include<stdlib.h>
int getMax(int a[],int n) 
{ 
	int i;
    int m=a[0]; 
    for (i=1;i<n;i++) 
    {
        if (a[i]>m) 
            m=a[i]; 
	}
    return m; 
} 
void countSort(int *a,int n,int e) 
{ 
    int out[n]; 
    int i,count[10]={0}; 
    for(i=0;i<n;i++) 
    {
        count[(a[i]/e)%10]++; 
	}
    for(i=1;i<10;i++) 
    {
        count[i]+=count[i-1]; 
	}
    for(i=n-1;i>=0;i--) 
    { 
        out[count[(a[i]/e)%10]-1]=a[i]; 
        count[(a[i]/e)%10]--; 
    } 
    for(i=0;i<n;i++)
	{ 
       a[i]=out[i];
	}
} 
   
void Radix_sort(int *a,int n) 
{ 
    int m=getMax(a,n);
	int e; 
    for(e=1;m/e>0;e*=10)
	{
        countSort(a,n,e);
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
	Radix_sort(a,n);
	printf("The array elements after sorting are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d,",a[i]);
	}
}
