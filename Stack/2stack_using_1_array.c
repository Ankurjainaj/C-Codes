#include<stdio.h>
#include<stdlib.h>
#include<process.h>
int n,top1=-1,top2;
void push1(char *s,char x)
{
	if(top1<top2-1)
	{
		s[++top1]=x;
	}
	else
	{
		printf("Stack overflow");
		exit(1);
	}
}
void push2(char *s,char x)
{
	if(top1<top2-1)
	{
		s[--top2]=x;
	}
	else
	{
		printf("Stack overflow");
		exit(1);
	}
}
char pop1(char *s)
{
	char y;
	if(top1<=-1)
	{
		printf("Stack Underflow");
		exit(1);
	}
	else
	{
		y=s[top1--];
	}
	return y;
}
char pop2(char *s)
{
	char y;
	if(top2>=n)
	{
		printf("Stack Underflow");
		exit(1);
	}
	else
	{
		y=s[top2++];
	}
	return y;
}
void main()
{
	int n,c;
	char x;
	char *s;
	printf("Enter the size of the stack");
	scanf("%d",&n);
	top2=n;
	s=(char*)malloc(n*sizeof(char));
	while(1)
	{
		printf("Enter 1 to push in stack 1\n");
		printf("Enter 2 to push in stack 2\n");
		printf("Enter 3 to pop from stack 1\n");
		printf("Enter 4 to pop from stack 2\n");
		printf("Enter 5 to exit\n");
		printf("Enter your choice:");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Enter the element:\n");
				scanf("%c",&x);
				push1(s,x);
				break;
			case 2:
				printf("Enter the element:\n");
				scanf("%c",&x);
				push2(s,x);
				break;
			case 3:
				printf("The element is: %c",pop1(s));
				break;
			case 4:
				printf("The element is: %c",pop2(s));
				break;
			case 5:
				exit(0);
			default:
				printf("Enter a valid choice:");
				break;
		}
	}
}
