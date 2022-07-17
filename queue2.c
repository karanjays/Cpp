#include<stdio.h>
#include<stdlib.h>

struct queue{
	int *k;
	int size;
	int front,rear;
};

int menu(){
	int n;
	printf("\n\t\t\t\t    DEQUEUE MENU");
	printf("\n\t\t\t\t1.  Enter queue data from 1st:-");
	printf("\n\t\t\t\t2.  Enter queue data from last:-");
	printf("\n\t\t\t\t3.  Delete queue data from 1st:-");
	printf("\n\t\t\t\t4.  Delete queue data from last:-");
	printf("\n\t\t\t\t5.  Peek queue data from 1st");
	printf("\n\t\t\t\t6.  Peek queue data from last");
	printf("\n\t\t\t\t7.  Isfull");
	printf("\n\t\t\t\t8.  IsEmpty");
	printf("\n\t\t\t\t0. Exit.");
	printf("\n\nEnter your choice:- \n");
	scanf("%d",&n);
	return n;
}

int isfull(struct queue m){
	return ((m.rear+1)%m.size==m.front);
}

int isempty(struct queue m){
	return (m.front<0);
}

void fdequeue(struct queue*m){
	if(isempty(*m))
		printf("It is Empty\n");
	else{
		printf("The delet is from frontend and element  is %d\n",m->k[m->front]);
		if(m->front==m->rear)
			m->front=m->rear=-1;
		else
			m->front=(m->front+1)%m->size;
	}
}

void dequeue(struct queue*m){
	if(isempty(*m))
		printf("It is Empty\n");
	else{
		printf("The delet is from rearend and element  is %d\n",m->k[m->rear]);
		if(m->front==m->rear)
			m->front=m->rear=-1;
		else
			m->rear=(m->size+m->rear-1)%m->size;
	}
}

void fpeek(struct queue*m){
	if(isempty(*m))
		printf("It is Empty\n");
	else
		printf("The peek is from frontend and element  is %d\n",m->k[m->front]);
}

void peek(struct queue*m){
	if(isempty(*m))
		printf("It is Empty\n");
	else
		printf("The peek is from rearend and  element  is %d\n",m->k[m->rear]);
}

void enqueue(struct queue *m,int z){
	if(isfull(*m))
		printf("queue Is Full\n");
	else{
	m->rear=(m->rear+1)%m->size;
	m->k[m->rear]=z;
	if(m->front==-1)
		m->front=m->rear;
	printf("%d is pushed in queue from last.\n",z);
	}
}

void fenqueue(struct queue *m,int z){
	if(isfull(*m))
		printf("queue Is Full\n");
	else{
		if(m->front==-1){
			m->front=m->rear=0;
			m->k[m->front]=z;}
		else{
		m->front=(m->size+m->front-1)%m->size;
		m->k[m->front]=z;
		}
		printf("%d is pushed in queue from 1st\n",z);
	}
}
void display(struct queue m){
	int i,j;
	printf("\n");
	if(isempty(m))
		printf("It is empty.\n");
	else if(m.rear>=m.front)
		for(i=m.front;i<=m.rear;i++)
			printf("%d==%d\n",i+1,m.k[i]);
	else{
		for(i=m.front;i<m.size;i++)
			printf("%d==%d\n",i+1,m.k[i]);
		for(i=0;i<=m.rear;i++)
			printf("%d==%d\n",i+1,m.k[i]);
	}
}

int main(){
	int i,j,z;
	struct queue m;
	m.rear=m.front=-1;
	printf("Enter the size of queue:-\n");
	scanf("%d",&m.size);
	m.k=(int*)malloc(m.size*sizeof(int));
	while(1){
	system("cls");
	switch(menu()){
		case 1:
			printf("Enter the value to insert\n");
			scanf("%d",&z);	
			fenqueue(&m,z);
			display(m);
			break;
		case 2:
			printf("Enter the value to insert\n");
			scanf("%d",&z);	
			enqueue(&m,z);
			display(m);
			break;
		case 3:
			fdequeue(&m);
			display(m);
			break;
		case 4:
			dequeue(&m);
			display(m);
			break;
		case 5:
			fpeek(&m);
			display(m);
			break;
		case 6:
			peek(&m);
			display(m);
			break;
		case 7:
			i=isfull(m);
			i>0?printf("True\n"):printf("False\n");
			display(m);
			break;
		case 8:			
			i=isempty(m);
			i>0?printf("IsEmpty\n"):printf("IsNot Empty\n");
			break;
		case 9:			
			display(m);
			break;
		case 0:
			exit(0);
		default:
			printf("\nPlz Enter Valid choice...!!!...\n");
	}
	system("pause");
	}
}
