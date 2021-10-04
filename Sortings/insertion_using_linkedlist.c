#include<stdio.h> 
#include<stdlib.h> 
struct node 
{ 
	int data; 
	struct node* next; 
};  
void sortedInsert(struct node**, struct node*); 
void insertionSort(struct node **head_ref) 
{ 
	struct node *sorted = NULL;  
	struct node *current = *head_ref; 
	while (current!=NULL) 
	{ 
		struct node *next=current->next; 
		sortedInsert(&sorted, current); 
		current=next; 
	} 
	*head_ref=sorted; 
} 
void sortedInsert(struct node** head_ref, struct node* new_node) 
{ 
	struct node* current; 
	if (*head_ref==NULL||(*head_ref)->data>=new_node->data) 
	{ 
		new_node->next=*head_ref; 
		*head_ref=new_node; 
	} 
	else
	{ 
		current=*head_ref; 
		while(current->next!=NULL && current->next->data<new_node->data) 
		{ 
			current=current->next; 
		} 
		new_node->next=current->next; 
		current->next=new_node; 
	} 
} 
void printList(struct node *head) 
{ 
	struct node *t=head; 
	while(t!=NULL) 
	{ 
		printf("%d ",t->data); 
		t=t->next; 
	} 
} 
void push(struct node** head_ref,int new_data) 
{ 
	struct node* new_node; 
	new_node->next=(*head_ref); 
	(*head_ref)=new_node; 
}  
void main() 
{ 
	int n,i,x;
	struct node *head=NULL; 
	printf("Enter the size of the linked list:");
	scanf("%d",&n);
	printf("Enter the elements of the list:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",x);
		struct node *new;
		new=(struct node*)malloc(sizeof(struct node));
		new->data=x;
		new->next=NULL;
		push(&new,x);
	}
	printf("Linked List before sorting \n"); 
	printList(head); 
	insertionSort(&head); 
	printf("\nLinked List after sorting \n"); 
	printList(head); 
} 

