//mark holder area.
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int mark;
	struct node *link;
};
struct node *start=NULL;
struct node *creat()
{
	struct node *a;
	//a=(int*)malloc(sizeof(int));
	a=(struct node*)malloc(sizeof(struct node));
	return a;
}
void append()
{
	struct node *t1,*t2;
	t1=creat();
	printf("plz enter student mark:- ");
	scanf("%d",&t1->mark);
	//t1->mark=i;
	t1->link=NULL;
	if(start==NULL)
		start=t1;
	else
	{
		t2=start;
		while(t2->link!=NULL)
			t2=t2->link;
		t2->link=t1;
	}
}
void insert()
{
	struct node *p,*t;
	p=start;
	int n,k;
	k=len();
	printf("Position to insert element.");
	scanf("%d",&n);
	if(n>k)
		printf("PLZ enter valid position");
	else
	{
		--n;
		while(--n)
			p=p->link;
		t=creat();
		printf("plz enter student mark:- ");
		scanf("%d",&t->mark);
		t->link=p->link;
		p->link=t;		
	}		
}
void delet()
{
	struct node *d;
	if(start==NULL)
		printf("list is empty");
	else
	{
		d=start;
		start=start->link;
		free(d);
	}
}
float percentage(){
	
	struct node *p;
	int a=0;
	p=start;
	while(p!=NULL)
	{
		a+=p->mark;
		p=p->link;
	}
	return a;
}
void emove()
{
	struct node *r, *q;
	int l,k;
	r=start;
	printf("position of remove: ");
	scanf("%d",&l);
	k=len();
	if(l>k)
		printf("There are only %d element in list",k);
	else
	{
		int i=0;
		while(i<l)
		{
			r=r->link;
			i++;
		}
		q=r->link;
		r->link=q->link;
		q->link=NULL;
		free(q);		
	}
}
void print()
{
	struct node *p;
	if(start==NULL)
		printf("list is empty");
	else
	{
		p=start;
		while(p!=NULL)
		{
			printf("%d ",p->mark);
			p=p->link;
		}		
	}
}
int len()
{
	struct node *p;
	int c=0;
	p=start;
		while(p!=NULL)
		{
			c++;
			p=p->link;
		}
		//printf("%d",c);
		return c;
}
void list()
{
	struct node *t1,*t2;
	int n,i=0;
	printf("no of subject in list: ");
	scanf("%d",&n);
	printf("Enter Mark: ");
	for(i=0;i<n;i++)
	{
		t1=creat();
		scanf("%d",&t1->mark);
		t1->link=NULL;
		if(start==NULL)
			start=t1;
		else
		{
			t2=start;
			while(t2->link!=NULL)
				t2=t2->link;
			t2->link=t1;
		}
	}	
}
int menu()
{
	int n;
	printf("\a\n\t\t\t\t    MENU");
	printf("\n\t\t\t\t1. Make list of Mark");
	printf("\n\t\t\t\t2. Insert new mark");
	printf("\n\t\t\t\t3. Append new mark");
	printf("\n\t\t\t\t4. Remove 1st subject mark");
	printf("\n\t\t\t\t5. Remove nth position subject mark");
	printf("\n\t\t\t\t6. Total per of student");
	printf("\n\t\t\t\t7. Total No. of sunject.");
	printf("\n\t\t\t\t8. Print All Mark");
	printf("\n\t\t\t\t9. Exit.");
	printf("\n\nEnter your choice:-  ");
	scanf("%d",&n);
	return n;
}
void main()
{
	while(1)
	{
		system("cls");
		switch(menu())
		{
			case 1:
				list();
				break;
			
			case 2:
				insert();
				break;
			case 3:
				append();
				break;
			case 4:
				delet();
				break;
			case 5:
				emove();
				break;
			case 6:
				printf("%0.2f\n",percentage()/len());
				break;
			case 7:
				printf("%d\n",len());
				break;
			case 8:
				print();
				printf("\n");
				break;
			case 9:
				exit(0);
			default:
				printf("\nPlz Enter Valid choice...!!!...\n");
		}
		system("pause");
	}
}
