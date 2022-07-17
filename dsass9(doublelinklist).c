#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct node
{
 struct node *prev;
 struct node *next;
 int data;
};

struct node *head;
void insert();
void delete();
void display();
void search();
void min_max();
void main ()
{
int choice =0;
 while(choice != 9)
 {
 	
		system("cls");
 printf("\n\t\t\t\tMENU\n");
 printf("\n\t\t\t\t1.Insert");
 printf("\n\t\t\t\t2.Delete");
 printf("\n\t\t\t\t3.Search");
 printf("\n\t\t\t\t4.Display");
 printf("\n\t\t\t\t5.Display Maximum and Minimum value");
 printf("\n\t\t\t\t6.Exit\n");
 printf("\nEnter your choice: ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 insert();
 break;
 case 2:
 delete();
 break;
 case 3:
 search();
 break;
 case 4:
 display();
 break;
 case 5:
 min_max();
 break;
 case 6:
 exit(0);
 break;
 default:
 printf("Please enter valid choice...");
 }
		system("pause");
 }
}
void insert()
{
 struct node *ptr; 
 int item;
 int loc;
 ptr = (struct node *)malloc(sizeof(struct node));
 if(ptr == NULL)
 {
 printf("\nOVERFLOW");
 }
 else
 {
 printf("\nEnter Position (0 for inserting at the beginning): ");
 scanf("%d",&loc);
 printf("\nEnter node value: ");
 scanf("%d",&item);
 if(head==NULL)
 {
 ptr->next = NULL;
 ptr->prev=NULL;
 ptr->data=item;
 head=ptr;
 }
 else
 {
 if(loc==0)
 {
 ptr->data=item;
 ptr->prev=NULL;
 ptr->next = head;
 head->prev=ptr;
 head=ptr;
 }
 else
 {
 struct node *temp;
 temp=head;
 while(--loc && temp->next!=NULL)
 temp=temp->next;
 if(loc!=0 || temp->next==NULL)
 {
 ptr->data=item;
 ptr->next=NULL;
 ptr->prev=temp;
 temp->next=ptr;
 }
 else
 {
 ptr->data=item;
 ptr->next=temp->next;
 ptr->prev=temp;
 temp->next->prev=ptr;
 temp->next=ptr;
 }
 }

 }
 printf("\nNode inserted\n");
}

}
void delete()
{
 struct node *ptr,*temp;
 if(head == NULL)
 {
 printf("\n UNDERFLOW");
 }
 else if(head->next == NULL)
 {
 head = NULL;
 free(head);
 printf("\nnode deleted\n");
 }
 int loc;
 printf("\nEnter Position to be deleted (0 for inserting at the beginning -1 for ending): ");
 scanf("%d",&loc);
 if(loc==0)
 {
 ptr = head;
 head = head -> next;
 head -> prev = NULL;
 free(ptr);
 printf("\nNode deleted\n");
 }
 else if(loc==-1)
 {
 ptr = head;
 while(ptr->next!=NULL)
 ptr=ptr->next;
 ptr->prev->next=NULL;
 free(ptr);
 printf("\nNode deleted\n");
 }
 else
 {
 ptr = head;
 while(--loc && ptr->next!=NULL)
 ptr=ptr->next;
 temp=ptr->next;
 ptr->next=temp->next;
 temp->next->prev=ptr;
 free(temp);
 printf("\nNode deleted\n");
 }

}
void display()
{
 struct node *ptr;
 printf("\n printing values...\n");
 ptr = head;
 printf("NULL");
 while(ptr != NULL)
 {
 printf("<-> %d ",ptr->data);
 ptr=ptr->next;
 }
 printf("<-> NULL");
}
void search()
{
 struct node *ptr;
 int item,i=0,flag; 
 ptr = head;
 if(ptr == NULL)
 {
 printf("\nEmpty List\n");
 }
 else
 {
 printf("\nEnter item which you want to search: ");

 scanf("%d",&item);
 while (ptr!=NULL)
 {
 if(ptr->data == item)
 {
 printf("\nitem found at: %d ",i+1);
 flag=0;
 break;
 }
 else
 {
 flag=1;
 }
 i++;
 ptr = ptr -> next;
 }
 if(flag==1)
 {
 printf("\nItem not found\n");
 }
 }
 
}
void min_max()
{
 int max=INT_MIN;
 int min=INT_MAX;
 struct node *ptr;
 ptr = head;
 while (ptr!=NULL)
 {
 if(ptr->data<min)
 min=ptr->data;
 if(ptr->data>max)
 max=ptr->data;
 ptr=ptr->next;
 }
 printf("\nMinimum Value: %d",min);
 printf("\nMaximum Value: %d",max);
}
