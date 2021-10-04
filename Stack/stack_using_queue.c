#include<stdio.h>
#include<stdlib.h>
#define MAX 128
typedef struct que{
	int *a;
	int r,f,count,max;
}queue;
queue *queue_allocate(int n)
{
	queue *Q;
	Q=malloc(sizeof(queue));
	if(Q==NULL)
		return NULL;
	Q->max=n;
	Q->a=malloc(sizeof(int)*n);
	Q->r=n-1;
	Q->f=n-1;
	return Q;
}
void queue_insert(queue *Q,int v)
{
	if(Q->count==Q->max)
		return ;
	Q->r=(Q->r+1)%Q->max;
	Q->a[Q->r]=v;
	Q->count++;
}
int queue_remove(queue *Q)
{
	int r;
	if(Q->count==0)
	{
		return(0);
	}
	Q->f=(Q->f+1)%Q->max;
	r=Q->a[Q->f];
	Q->count--;
	return r;
}
int queue_is_empty(queue *Q)
{
	return (Q->count==0);
}
void queue_display(queue *Q)
{
	int i=(Q->f+1)%Q->max,elements=queue_count(Q);
	while(elements--)
	{
		printf("[%d], ",Q->a[i]);
		i=(i>=Q->max) ? 0:(i+1);
	}
}
void stack_push(queue *Q,int v)
{
	queue_insert(Q,v);
}
int stack_pop(queue *Q)
{
	int i,n=queue_count(Q);
	int removed_element;
	for(i=0;i<(n-1);i++)
	{
		removed_element=queue_remove(Q);
		queue_insert(Q,removed_element);
	}
	removed_element=queue_remove(Q);
	return removed_element;
}
int stack_count(queue *Q)
{
	return queue_count(Q);
}
int stack_is_empty(queue *Q)
{
	return queue_is_empty(Q);
}
int queue_count(queue *Q)
{
	return Q->count;
}
void main()
{
	queue *Q;
	int x,s;
	Q=queue_allocate(MAX);
	while(1)
	{
		printf("\n1-Push\n2-Pop\n3-Exit\n");
		printf("\nChoice:");
		scanf("%d ",&s);
		switch(s)
		{
			case 1:
				printf("\nEnter the value to push:");
				scanf("%d",&x);
				stack_push(Q,x);
				printf("\nCurrent Queue:\n");
				queue_display(Q);
				printf("\nPushed value was:%d",x);
				break;
			case 2:
				x=stak_pop(Q);
				printf("\nCurrent Queue:\n");
				queue_display(Q);
				printf("\nPopped value was: %d",x);
				break;
			case 3:
				exit(0);
			default:
				printf("Wrong choice");		
		}
	}
}
