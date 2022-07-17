#include<stdio.h>
#include<stdlib.h>

struct stdv{
	int roll_no,total_mark;
	char name[20];
	char address[60];
	long int mobile_no;
	float cgpa;
};
struct Array{
	struct stdv *k;
	int l;
	int s;
};

int i,j;
int menu(){
	int n;
	printf("\a\n\t\t\t\t    MENU");
	printf("\n\t\t\t\t1.  Insert");
	printf("\n\t\t\t\t2.  Delet");
	printf("\n\t\t\t\t3.  Search");
	printf("\n\t\t\t\t4.  Traverse");
	printf("\n\t\t\t\t5.  Update");
	printf("\n\t\t\t\t0. Exit.");
	printf("\n\nEnter your choice:- \n");
	scanf("%d",&n);
	return n;
}

void Insert(struct Array *ar,int n){
	int i;
	if(ar->l<ar->s && n>=0 && n<=ar->l)
	{
		for(i=ar->l;i>n;i--)
			ar->k[i]=ar->k[i-1];
		getchar();
		printf("Enter Name of student:-\n");
		scanf("%[^\n]%*c",ar->k[n].name);
		printf("Enter Address of student:-\n");
		scanf("%[^\n]%*c",ar->k[n].address);
		printf("Enter Roll.no:-\nU19CS");
		scanf("%d",&ar->k[n].roll_no);
		printf("Enter Total Marks:-\n");
		scanf("%d",&ar->k[n].total_mark);
		printf("Enter CGPA:-\n");
		scanf("%f",&ar->k[n].cgpa);
		ar->l++;
	}
	else
		printf("dont have enough space.\n");
}

void Delet(struct Array *ar,int n){
	int i;
	if(n>=0 && n<ar->l)
	{
		for(i=n;i<ar->l;i++)
			ar->k[i]=ar->k[i+1];
		ar->l--;
	}
	else
		printf("invalid place.\n");
}


void Update(struct Array *ar,int n){
	int i;
	if(n>=0 && n<ar->l)
	{
		getchar();
		printf("Enter Name of student:-\n");
		scanf("%[^\n]%*c",ar->k[n].name);
		printf("Enter Address of student:-\n");
		scanf("%[^\n]%*c",ar->k[n].address);
		printf("Enter Roll.no:-\nU19CS");
		scanf("%d",&ar->k[n].roll_no);
		printf("Enter Total Marks:-\n");
		scanf("%d",&ar->k[n].total_mark);
		printf("Enter CGPA:-\n");
		scanf("%f",&ar->k[n].cgpa);
	}
	else
		printf("Invalid index!!!\n");
}

void Search(struct Array ar,int x){
	int m;
	i=0;
	j=ar.l-1;
	while(i<=j){
		m=(i+j)/2;
		if(x>ar.k[m].roll_no)
			i=m+1;
		else if(x<ar.k[m].roll_no)
			j=m-1;
		else{
			printf("The student found at index %d",m+1);
			break;
			}
	}
	if(i>j)
		printf("Any of the student doesn't have such roll_no");
}

void Display(struct Array ar){
	int i;
	for(i=0;i<ar.l;i++){
		printf("\tName of student is \t%s\n\t",ar.k[i].name);
		printf("Address of student is \t%s \n\t",ar.k[i].address);
		printf("Roll.no is \tU19CS%0.3d\n\t",ar.k[i].roll_no);
		printf("Total Marks is \t%d\n\t",ar.k[i].total_mark);
		printf("CGPA is \t%0.2f\n\t\n",ar.k[i].cgpa);
	}
}

void main(){
	struct Array ar;
	printf("Enter the size of Array.\n");
	scanf("%d",&ar.s);
	printf("Enter the length of Array.\n");
	scanf("%d",&ar.l);
	ar.k=(struct stdv*)malloc(ar.s*sizeof(struct stdv));
	printf("Enter the elements of Array.\n");
	for(i=0;i<ar.l;i++)
	{
		getchar();
		printf("Enter Name of student:-\n");
		scanf("%[^\n]%*c",ar.k[i].name);
		printf("Enter Address of student:-\n");
		scanf("%[^\n]%*c",ar.k[i].address);
		printf("Enter Roll.no:-\nU19CS");
		scanf("%d",&ar.k[i].roll_no);
		printf("Enter Total Marks:-\n");
		scanf("%d",&ar.k[i].total_mark);
		printf("Enter CGPA:-\n");
		scanf("%f",&ar.k[i].cgpa);
	}
	while(1)
	{
		system("cls");
		switch(menu())
		{
			case 1:
				printf("Element to insert at index (element and index)\n");
				scanf("%d",&i);
				Insert(&ar,i-1);
				printf("\n");
				Display(ar);
				break;
			case 2:
				printf("Element to delet at index\n");
				scanf("%d",&i);
				Delet(&ar,i-1);
				printf("\n");
				Display(ar);
				break;
			case 3:
				printf("Enter Roll_no to search\nU19CS");
				scanf("%d",&i);
				Search(ar,i);
				printf("\n");
				Display(ar);
				break;
			case 4:
				Display(ar);
				break;
			case 5:
				printf("Update Element(element and index)\n");
				scanf("%d%d",&i,&j);
				Update(&ar,i-1);
				printf("\n");
				Display(ar);
				break;
			case 0:
				exit(0);
			default:
				printf("\nPlz Enter Valid choice...!!!...\n");
		}
		system("pause");
	}
}
