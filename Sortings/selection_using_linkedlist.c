#include<stdio.h>
#include<stdlib.h>
struct node { 
    int data; 
    struct node* next; 
}; 
void swapNodes(struct node**head_ref,struct node*currX,struct node*currY,struct node*prevY) 
{  
    *head_ref=currY; 
    prevY->next=currX;  
    struct node* t=currY->next; 
    currY->next=currX->next; 
    currX->next=t; 
} 
struct node* recurSelectionSort(struct node* head) 
{ 
    if(head->next==NULL) 
        return head;  
    struct node* min=head;  
    struct node* beforeMin=NULL; 
    struct node* ptr; 
    for(ptr = head;ptr->next!=NULL;ptr=ptr->next) 
	{ 
        if(ptr->next->data<min->data) 
		{ 
            min=ptr->next; 
            beforeMin=ptr; 
        } 
    } 
    if(min!=head) 
        swapNodes(&head,head,min,beforeMin); 
    head->next=recurSelectionSort(head->next); 
    return head; 
}  
void sort(struct node** head_ref) 
{ 
    if((*head_ref)==NULL) 
        return;  
    *head_ref=recurSelectionSort(*head_ref); 
}  
void push(struct Node** head_ref,int new_data) 
{ 
    struct node* new_node=(struct node*)malloc(sizeof(struct node)); 
    new_node->data=new_data;  
    new_node->next=(*head_ref); 
    (*head_ref)=new_node; 
} 
void printList(struct node* head) 
{ 
    while (head != NULL) 
	{ 
        printf("%d ",head->data); 
        head=head->next; 
    } 
} 
void main() 
{ 
    struct node* head=NULL; 
    push(&head, 6); 
    push(&head, 4); 
    push(&head, 8); 
    push(&head, 12); 
    push(&head, 10); 
  
    printf("Linked list before sorting:\n"); 
    printList(head);  
    sort(&head); 
    printf("\nLinked list after sorting:\n"); 
    printList(head); 
    return 0; 
} 
