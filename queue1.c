#include<stdio.h>
#include<stdlib.h>

struct queue{
	int *k;
	int size;
	int front,rear;
};

int menu(){
	int n;
	printf("\n\t\t\t\t    MENU");
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

void enqueue(struct queue *m,int z){
	if(isfull(*m))
		printf("queue Is Full\n");
	else{
	m->rear=(m->rear+1)%m->size;
	m->k[m->rear]=z;
	if(m->front==-1)
		m->front=m->rear;
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
			break;
		case 2:
			dequeue(&m);
			break;
		case 3:
			peek(&m);
			break;
		case 4:
			i=isfull(m);
			i>0?printf("True\n"):printf("False\n");
			break;
		case 5:			
			i=isempty(m);
			i>0?printf("IsEmpty\n"):printf("IsNot Empty\n");
			break;
		case 0:
			exit(0);
		default:
			printf("\nPlz Enter Valid choice...!!!...\n");
	}
	system("pause");
	}
}
