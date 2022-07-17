#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//structure for array
struct node{
	char name[15];
	int mark;
	struct node * next;
};

// start decleration
struct node *start=NULL;

//creation of node
struct node *create(){
	struct node *a;
	a=(struct node*)malloc(sizeof(struct node));
	return a;
}

//Creating linklist
void createlist(){
	struct node *t1,*t2;
	int i,j,n;
	printf("Enter the no. of element in array.\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		t1=create();
		printf("Enter the student name and mark.\n");
		scanf("%s %d",&t1->name,&t1->mark);
		t1->next=NULL;
		if(start==NULL){
			start=t1;
		}
		else{
			t2=start;
			while(t2->next!=NULL){
				t2=t2->next;
			}
			t2->next=t1;
		}	
}
}

//printing the linklist
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

// counting the no of node
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

// insert at 1st position
void insertb(){
	struct node *t1;
	t1=create();
	printf("Enter the student name and mark.\n");
	scanf("%s %d",&t1->name,&t1->mark);
	t1->next=start;
	start=t1;
}

// insert at given position
void insert(){
	struct node *t1,*t2;
	int i,k=nos();
	printf("Position to insert:-");
	scanf("%d",&i);
	if(i>k)
		printf("PLZ enter valid position");
	else
	{
		--i;
		t2=start;	
	while(--i)
		t2=t2->next;
	t1=create();
	printf("Enter the student name and mark.\n");
	scanf("%s %d",&t1->name,&t1->mark);
	t1->next=t2->next;
	t2->next=t1;	
	}
}


// insert at last position
void inserte(){
	struct node *t1,*t2;
	t1=create();
	printf("Enter the student name and mark.\n");
	scanf("%s %d",&t1->name,&t1->mark);
	t1->next=NULL;
	if(start==NULL)
		start=t1;
	else
	{
		t2=start;	
	while(t2->next!=NULL){
			t2=t2->next;
		}
	t2->next=t1;
	}
}

//delet from start
void deletb(){
	struct node *t1;
	t1=start;
	start=t1->next;
	free(t1);		
}

//delet
void delet(){
	struct node *t1,*t2;
	int i,k=nos();
	printf("Position to Delet:-");
	scanf("%d",&i);
	if(i>k || i==1)
		printf("PLZ enter valid position");
	else
	{
		--i;
		t2=start;	
	while(--i)
		t2=t2->next;
	t1=t2->next;
	t2->next=t1->next;
	free(t1);
	}
}


//menu bar
int menu(){
	int n;
	printf("\n\t\t\t\t    MENU");
	printf("\n\t\t\t\t1. Make a list of student with its mark ");
	printf("\n\t\t\t\t2. Display ");
	printf("\n\t\t\t\t3. Total no. of student");
	printf("\n\t\t\t\t4. Insert new student at.");
	printf("\n\t\t\t\t5. Delet student From.");
	printf("\n\t\t\t\t0. Exit.");
	printf("\n\nEnter your choice:-  ");
	scanf("%d",&n);
	return n;
}


//sub menu for both deletion and insertion
int mu(){
	int n;
	printf("\n\t\t\t\t1. Begining ");
	printf("\n\t\t\t\t2. Middle ");
	printf("\n\t\t\t\t3. End ");
	printf("\n\nEnter your choice:-  ");
	scanf("%d",&n);
	return n;
}

//main function
void main(){
	char k[15];
	int i;
	while(1){
		system("cls");//switch case
		switch(menu()){
			case 1:
				createlist();
				break;
			case 2:
				display();
				break;
			case 3:
				printf("The total no. of student is %d\n",nos());
				break;
			case 4:
				// nested switch case
				switch(mu()){
					case 1:
						insertb();
						break;
					case 2:
						insert();
						break;
					case 3:
						inserte();
						break;
				default :
					printf("\nPlz Enter Valid choice...!!!...\n");
				}
				break;
			case 5:
				// nested switch case
				switch(mu()){
					case 1:
						deletb();
						break;
					case 2:
					case 3:
						delet();
						break;
				default :
					printf("\nPlz Enter Valid choice...!!!...\n");
				}
				break;
			case 0:
				exit(0);
			default :
				printf("\nPlz Enter Valid choice...!!!...\n");
		}
		system("pause");
	}
}
