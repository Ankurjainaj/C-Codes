#include<stdio.h>
#include<stdlib.h>
#include<process.h>
struct node
{
	int data;
	struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x)
{
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	if(t==NULL)
		printf("Queue is FUll\n");
	else
	{
		t->data=x;
		t->next=NULL;
		if(front==NULL)
			front=rear=t;
		else
		{
			rear->next=t;
			rear=t;
		}
	}
}

int dequeue()
{
	int x=-1;
	struct node* t;
	if(front==NULL)
		printf("Queue is Empty\n");
	else
	{
		x=front->data;
		t=front;
		front=front->next;
		free(t);
	}
	return x;
}

void Display()
{
	struct node *p=front;
	while(p)
	{
		printf("%d ",p->data);	
		p=p->next;
	}
	printf("\n");
}

void main()
{
	int n,i,x;
	printf("Enter the size of the queue:");
	scanf("%d",&n);
	printf("Enter the elements of the queue:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		enqueue(x);
	}
	Display();
	printf("The dequeued element is: %d ",dequeue());
}
