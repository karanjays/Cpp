#include<stdio.h>
#include<stdlib.h>

struct stack{
	char *k;
	int size;
	int top;
};

int menu(){
	int n;
	printf("\n\t\t\t\t    MENU");
	printf("\n\t\t\t\t1.  Push");
	printf("\n\t\t\t\t2.  Pop");
	printf("\n\t\t\t\t3.  Peek");
	printf("\n\t\t\t\t4.  Isfull");
	printf("\n\t\t\t\t5.  IsEmpty");
	printf("\n\t\t\t\t0. Exit.");
	printf("\n\nEnter your choice:- \n");
	scanf("%d",&n);
	return n;
}

int isfull(struct stack m){
	if(m.top==m.size)
		return 1;
	else
		return 0;
}

int isempty(struct stack m){
	if(m.top<1)
		return 1;
	else
		return 0;
}

void pop(struct stack*m){
	if(m->top<1)
		printf("It is Empty\n");
	else{
		printf("%c Is pop out\n",m->k[m->top--]);
	}
}

void peek(struct stack*m){
	if(m->top<1)
		printf("It is Empty\n");
	printf("%c\n",m->k[m->top]);
}

void push(struct stack *m,char *z){
	if(m->top==m->size){
		printf("Stack Is Full\n");
	}
	else{
	m->k[++m->top]=z;
	printf("%c is pushed in stack\n");
}
}
int main(){
	int i,j;
	char z;
	struct stack m;
	m.top=0;
	printf("Enter the size of Stack:-\n");
	scanf("%d",&m.size);
	m.k=(char*)malloc(m.size*sizeof(char));
	while(1){
	system("cls");
	switch(menu()){
		case 1:
			printf("Enter the value to push\n");
			getchar();
			z=getchar();	
			push(&m,z);
			break;
		case 2:
			pop(&m);
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
			i>0?printf("True\n"):printf("False\n");
			break;
		case 0:
			exit(0);
		default:
			printf("\nPlz Enter Valid choice...!!!...\n");
	}
	system("pause");
	}
}
