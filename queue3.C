#include<stdio.h>
#include<stdlib.h>

struct queue{
	int *k;
	int size;
	int front,rear;
};

int menu(){
	int n;
	printf("\n\t\t\t\t    PRIORITY QUEUE MENU");
	printf("\n\t\t\t\t1.  Enter queue data:-");
	printf("\n\t\t\t\t2.  Delete queue data:-");
	printf("\n\t\t\t\t3.  Peek");
	printf("\n\t\t\t\t4.  Isfull");
	printf("\n\t\t\t\t5.  IsEmpty");
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

void dequeue(struct queue*m){
	if(isempty(*m))
		printf("It is Empty\n");
	else{
		if(m->front==m->rear)
			m->front=m->rear=-1;
		else
			m->front=(m->front+1)%m->size;
	}
}

void peek(struct queue*m){
	if(isempty(*m))
		printf("It is Empty\n");
	else
		printf("The peek element  is %d\n",m->k[m->front]);
}


static int j;
void enqueue(struct queue *m,int z){
	if(isfull(*m))
		printf("queue Is Full\n");
	else{
		int i=(j++);
		printf("i=%d,j=%d",i,j);
	while(i>0 && z>m->k[i/2]){
		m->k[i]=m->k[i/2];
		printf("i=%d,i/2=%d",m->k[i],m->k[i/2]);
		i=i/2;
	}
	m->k[i]=z;
	m->rear=(m->rear+1)%m->size;
	if(m->front==-1)
		m->front=m->rear;
	printf("r=%d,mi=%d,m.r=%d",m->rear,m->k[i],m->k[m->rear]);
	printf("%d is pushed in queue\n",z);
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
			enqueue(&m,z);
			display(m);
			break;
		case 2:
			dequeue(&m);
			display(m);
			break;
		case 3:
			peek(&m);
			display(m);
			break;
		case 4:
			i=isfull(m);
			i>0?printf("True\n"):printf("False\n");
			display(m);
			break;
		case 5:			
			i=isempty(m);
			i>0?printf("IsEmpty\n"):printf("IsNot Empty\n");
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
