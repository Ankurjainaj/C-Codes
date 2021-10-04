#include<stdio.h>
#include<stdlib.h>
#include<process.h>
int f=-1;
int r=-1;
CQ_enqueue(int *Q,int n,int x)
{
	if((r==n-1&&f==0)||(r==f-1))
	{
		printf("Overflow");
		exit(1);
	}
	if(r==n-1)
		r=0;
	else
		r=r+1;
	Q[r]=x;
	if(f==-1)
		f=0;
}
CQ_dequeue(int *Q,int n)
{
	int y;
	if(f==-1)
	{
		printf("Queue is empty");
		exit(1);
	}
	y=Q[f];
	if(f==r)
		f=r=-1;
	else if(f==n-1)
		f=0;
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
		CQ_enqueue(Q,n,x);
	}
	k=CQ_dequeue(Q,n);
	printf("The dequeued element is: %d",k);
}
