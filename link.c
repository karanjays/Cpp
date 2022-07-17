#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char name[15];
	int mark;
	struct node * next;
};

struct node *start=NULL;

struct node *create(){
	struct node *a;
	a=(struct node *)malloc(sizeof(struct node));
	return a;
}

void list(){
	struct node *t1,*t2;
	int i,n;
	printf("Enter the no. of element in array.\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		t1=create();
		printf("Enter the student name and mark.\n");
		scanf("%s %d",&t1->name,&t1->mark);
		t1->next=NULL;
		if(start==NULL)
			start=t1;
		else{
			t2=start;
			while(t2->next!=NULL){
				t2=t2->next;
			}
			t2->next=t1;			
		}
	}
}

void display(){
	struct node *t1;
	if(start==0)
		printf("Empty List.\n");
	else{
		t1=start;
		while(t1!=0){
			printf("%s == %d\n",t1->name,t1->mark);
			t1=t1->next;
		}
	}	
}

void total(){
	struct node *t1;
	int s=0;
	if(start==0)
		printf("The sum is 0");
	else{
		t1=start;
		while(t1!=0){
			s=s+t1->mark;
			t1=t1->next;
		}
		printf("The sum is %d\n",s);
	}
}

int nos(){
	struct node *t1;
	int s=0;
	t1=start;
	while(t1){
		s++;
		t1=t1->next;
	}
	return s;
}

void max_min(){
	struct node *t;
	t=start;
	int max=t->mark,min=max;
	while(t){
		if(max<t->mark)
			max=t->mark;
		else if(min>t->mark)
			min=t->mark;
		t=t->next;
	}
	printf("The max is %d.\nThe min is %d.\n",max,min);
}

void search(char k[]){
	struct node *t,*p;
	t=start;
	p=start;
	while(t){
		if(strcmp(k,t->name)==0)
		{
			printf("search found\n%s == %d\n",t->name,t->mark);
			p->next=t->next;
			t->next=start;
			start=t;
			break;
		}
		p=t;	
		t=t->next;
	}
	if(t==0)
		printf("search not found\n");
}

void insert(int n){
	if(n<nos()+2){
		struct node *t,*t1;
		t=start;
		t1=create();
		printf("Enter the student name and mark.\n");
		scanf("%s %d",&t1->name,&t1->mark);
		t1->next=NULL;
		if(n==1){
			t1->next=start;
			start=t1;
		}
		else{
			n=2;
		while(n--){
			t=t->next;
		}
		t1->next=t->next;
		t->next=t1;
}
	}
	else
		printf("Invalid position!!\n");
}

int menu(){
	int n;
	printf("\n\t\t\t\t    MENU");
	printf("\n\t\t\t\t1. Make a list of student with its mark ");
	printf("\n\t\t\t\t2. Display ");
	printf("\n\t\t\t\t3. Total mark of all student ");
	printf("\n\t\t\t\t4. Total no. of student");
	printf("\n\t\t\t\t5. highest and lowest mark of student");
	printf("\n\t\t\t\t6. search the student is available or not");
	printf("\n\t\t\t\t7. Insert new student.");
	printf("\n\t\t\t\t8. Print All Mark");
	printf("\n\t\t\t\t0. Exit.");
	printf("\n\nEnter your choice:-  ");
	scanf("%d",&n);
	return n;
}

void main(){
	char k[15];
	int i;
	while(1){
		system("cls");
		switch(menu()){
			case 1:
				list();
				break;
			case 2:
				display();
				break;
			case 3:
				total();
				break;
			case 4:
				printf("The total no. of student is %d\n",nos());
				break;
			case 5:
				max_min();
				break;
			case 6:
				printf("Name of student to search:-");
				getchar();
				scanf("%[^\n]%*c",k);
				search(k);
				break;
			case 7:
				printf("Position to insert:-");
				scanf("%d",&i);
				insert(i);
				break;
			case 0:
				exit(0);
			default :
				printf("\nPlz Enter Valid choice...!!!...\n");
		}
		system("pause");
	}
}
