#include<stdio.h>
#include<process.h>
#include<stdlib.h>
int f=-1;
int r=-1;
void enqueue(int *Q,int n,int x)
{
	if(r==n-1)
	{
		printf("Overflow");
		exit(1);
	}
	Q[++r]=x;
	if(f==-1)
		f=0;
}
int dequeue(int *Q, int n)
{
	int y;
	if(f==-1)
	{
		printf("Underflow");
		exit(1);
	}
	y=Q[f];
	if(f==r)
		f=r=-1;
	else
		f+=1;
	return(y);
}
void main()
{
	int k,x;
	int *Q;
	int n,i;
	printf("Enter the size of the queue:");
	scanf("%d",&n);
	Q=(int *)malloc(n*sizeof(int));
	printf("Enter the elements of the queue:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		enqueue(Q,n,x);
	}
	k=dequeue(Q,n);
	printf("The dequeued element is: %d",k);
}
