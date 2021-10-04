#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*top=NULL;
void push(int x)
{
	struct node*t;
	t=(struct node*)malloc(sizeof(struct node));
	if(t==NULL)
		printf("stack is full\n");
	else
	{
		t->data=x;
		t->next=top;
		top=t;
	}
}
int pop()
{
	struct node *t;
	int x=-1;
	if(top==NULL)
		printf("Stack is Empty\n");
	else
	{
		t=top;
		top=top->next;
		x=t->data;
		free(t);
	}
	return x;
}
void Display()
{
	struct node *p;
	p=top;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void main()
{
	int n,i,a;
	printf("Enter the size of the stack:\n");
	scanf("%d",&n);
	printf("Enter the elements for the stack:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		push(a);
	}
	Display();
	printf("%d ",pop());
}
