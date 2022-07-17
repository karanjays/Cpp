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
char peek(struct stack m){
	return m.k[m.top];
}

int isempty(struct stack m){
	if(m.top<1)
		return 1;
	return 0;
}

void push(struct stack *m,char z){
	m->k[++m->top]=z;
}
int isAlpha(char c)
{
    if ( (c > 64 && c < 91) || (c > 47 && c < 58) || ( c > 96 && c < 123 ))
		return 1;
    return 0;
}

int pty(char c){
	switch(c){
		case '+':
		case '-':
			return 1;
		
		case '*':
		case '/':
			return 2;
		
		case '^':
			return 3;
	}
	return -1;
}
void infixtopostfix(char c[]){
	int i,k=0,l=strlen(c);
	char r[50];
	struct stack m;
	m.top=0;
	m.size=l;
	m.k=(char*)malloc(m.size*sizeof(char));
	
	
	for(i=0;i<l;i++)
	{
		if(isAlpha(c[i]))
			r[k++]=c[i];
						
		else if(c[i] == '(' )
			push(&m,c[i]);
			
		else if(c[i]==')'){
			while(peek(m)!='('){
				r[k++]=pop(&m);
			}
			pop(&m);
		}
		else
		{
			while(!isempty(m) && pty(c[i])<=pty(peek(m)) && pty(peek(m))!=3 ){
					r[k++]=pop(&m);
			}
			push(&m,c[i]);
		}
	}	
	while(!isempty(m))
		r[k++]=pop(&m);
	r[k]='\0';
	printf("The POSTFIX exp is\n\t\t%s",r);
}

int main(){
	char c[50];
	printf("Infix to postfix:-\n\t\t");
	scanf("%s",c);
	infixtopostfix(c);
}
