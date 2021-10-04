#include<stdio.h>
#include<stdlib.h>
#include<process.h>
int st1[100],st2[100];
int top1=-1,top2=-1,count=0;
void create()
{
	top1=top2=-1;
}
void push1(int d)
{
	st1[++top1]=d;
}
int pop1()
{
	return(st1[top1--]);
}
void push2(int d)
{
	st2[++top2]=d;
}
int pop2()
{
	return(st2[top2--]);
}
void enqueue()
{
	int d,i;
	printf("Enter the data:");
	scanf("%d",&d);
	push1(d);
	count++;
}
int dequeue()
{
	int i,a;
	if(count==0)
	{
		printf("The queue is empty.");
		exit(0);
	}
	for(i=0;i<=count;i++)
	{
		push2(pop1());
	}
	pop2();
	count--;
	a=pop2();
	push2(a);
	for(i=0;i<=count;i++)
	{
		push1(pop2());
	}
	return a;
}
void display()
{
	int i;
	printf("The elements of the queue are:\n");
	for(i=0;i<=top1;i++)
	{
		printf("%d",st1[i]);
	}
}
void main()
{
	int c;
	create();
	while(1)
	{
		printf("\n1-Enqueue element into queue\n");
		printf("2-Dequeue element from queue\n");
		printf("3-Display the queue\n");
		printf("4-Exit\n");
		printf("Enter your choice:\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				enqueue();
				break;
			case 2:
				printf("The dequeued element is: %d",dequeue());
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Wrong choice");	
		}
	}
}
