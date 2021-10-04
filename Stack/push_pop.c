#include<stdio.h>
#include<process.h>
#include<stdlib.h>
int top=-1;
push(int *s,int x,int n)
{
	if(top==n-1)
	{
		printf("Stack overflow");
		exit(1);
	}
	top=top+1;
	s[top]=x;
}
int pop(int *s)
{
	int a;
	if(top==-1)
	{
		printf("Stack underflow");
		exit(1);
	}
	a=s[top];
	top=top-1;
	return(a);
}
void main()
{
	int n,x,i;
	int *s;
	printf("Enter the size of the stack to be created:");
	scanf("%d",&n);
	s=(int*)malloc(n*sizeof(int));
	printf("Enter the elements of the stack:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		push(s,x,n);
	}
	printf("The elements of the stack are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",pop(s));
	}
}
