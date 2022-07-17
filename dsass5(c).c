#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
	char *k;
	int size;
	int top;
};

char pop(struct stack*m){
	return m->k[m->top--];
}

void push(struct stack *m,char z){
	m->k[++m->top]=z;
}
int isempty(struct stack m){
	if(m.top<1)
		return 1;
	else
		return 0;
}

int peek(struct stack*m){
	return m->k[m->top];
}

void sort(char s[]){
	struct stack m1,m2;
	m1.top=0;
	m2.top=0;
	char i;
	int k,c=strlen(s);
	k=c;
	m1.size=strlen(s);
	m2.size=m1.size;
	m1.k=(char*)malloc(m1.size*sizeof(char));
	m2.k=(char*)malloc(m2.size*sizeof(char));
	while(c--){
		push(&m1,s[c]);
	}
	while(!isempty(m1)){
		i=pop(&m1);
		while(!isempty(m2) && peek(&m2)>i){
			push(&m1,pop(&m2));
		}
		push(&m2,i);
	}
	while(k--){
		printf("%c",pop(&m2));
	}
}

int main(){
	char z,x[15];
	printf("Enter the word to sort\n");
	scanf("%s",&x);
	sort(x);
	}
