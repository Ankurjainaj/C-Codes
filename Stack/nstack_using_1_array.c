#include <stdio.h>
#include <stdlib.h>
int s[50],top[50],min[50],max[50];
int ns,size;
void init(void)
{ 
 	int i;
 	for(i=0;i<50;++i)
 	{ 
 		s[i]=min[i]=max[i]=0;
 		top[i]=-1;
 	}
} 
void createstack()
{ 
	int i;
	min[0]=-1;
 	max[0]=size-1;
 	top[0]=-1; 
 	for(i=1;i<ns;++i)
 	{
 		min[i]=min[i-1]+size;
 		top[i]=min[i];
	}
 	for(i=1;i<ns;++i)
 	{
 		max[i]=min[i+1];
 	}
 
}
void push(int e,int k)
{
 	if(top[k-1]==max[k-1])
 	{
 		printf("Stack no %d is overflow\n",k);
 		return;
 	}
 
 	++top[k-1];
 	s[top[k-1]]=e;
 
}
void pop(int k)
{ 
 	if(top[k-1]==min[k-1])
 	{ 
 		printf("\nStack no %d is empty i.e underflow\n",k);
 		return;
	}
 	printf("%d from stack %d is deleted:\n",s[top[k-1]],k);
	--top[k-1];
}
void display(int k)
{ 
 	int j;
 	if(top[k-1]==min[k-1])
 	{ 
 		printf("\nStack no %d is empty\n",k);
 	return;
 	}
 	printf("\nStack %d ?> ",k);
 	for(j=min[k-1]+1;j<=top[k-1];++j)
 	{ 
 		printf("%d",s[j]);
 	} 
 
}
void main() 
{
	int e,ch,skn;
	init();
	printf("\nEnter the number of Stacks\n");
	scanf("%d",&ns);
	size = 50/ns;
	createstack();
	printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
 	do
	{
		printf("\nEnter your choice : \t");	
		scanf("%d",&ch);
 		switch(ch)
 		{ 
 			case 1: 
			 	printf("\nEnter the stack no : \t");
 			 	scanf("%d",&skn);
 				printf("\nEnter the element : \t");
 				scanf("%d",&e);
 				push(e,skn);
 				break;
			case 2: 
 				printf("\nEnter the stack no to pop : \t");
 				scanf("%d",&skn);
 				pop(skn);
 				break;
			case 3: 
 				printf("\nEnter the stack no to display : \t");
 				scanf("%d",&skn);
 				display(skn);
 				break;
			case 4: 
 				printf("\nProgram Terminating");
 				break;
			default: 
				printf("\nInvalid Option\n");
		}
	}
	while(ch!=4); 
}
