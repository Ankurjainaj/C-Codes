#include<stdio.h>
#include<stdlib.h>
int heapsizeA;

int left(int i)
{
	return (2*i);
}

int right(int i)
{
	return (left(i)+1);
}

void exchange(int *x,int *y)
{
		int temp=*x;
		*x=*y;
		*y=temp;
}
void maxheapify(int* A,int i){
	int largest;
	int l;
	l=left(i);
	int r;
	r=right(i);
	if(l<=heapsizeA && A[l]>A[i]){
			 largest=l;		
		}
	else
		largest=i;
	if(r<=heapsizeA && A[r]>A[largest]){
		largest=r;	
	}
	if(largest!=i){
		exchange((A+i),(A+largest));
		maxheapify(A,largest);
	}
		
}
void Buildmaxheap(int* A,int n)
{
	int i;
    heapsizeA=n;
	for(i=n/2;i>=1;i--)
		maxheapify(A,i);
}
void heapsort(int* A,int n)
{
	int i;
	Buildmaxheap(A,n);
	for(i=n;i>=2;i--)
	{
		exchange(A+1,A+i);
		heapsizeA=heapsizeA-1;
		maxheapify(A,1);	
	}
}
void main()
{
	int n,i;
	int* A;
	printf("enter the size of the array:");
	scanf("%d",&n);
	A=(int*)malloc(sizeof(int)*n);
	printf("Enter the array elements:\n");
	for(i=1;i<n+1;i++)
	{
		scanf("%d",&A[i]);
	}
	A[0]=0;
	heapsort(A,n);
	printf("The array elements after sorting are:\n");
	for(i=1;i<=n;i++)
	{
		printf("%d, ",*(A+i));
	}		
}








