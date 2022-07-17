#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
	struct stv *k;
	int size;
	int top;
};
struct stv{
	char exp[50];
};
char* pop(struct stack*m){
	return m->k[m->top--].exp;
}
char* peek(struct stack m){
	return m.k[m.top].exp;
}

int isempty(struct stack m){
	if(m.top<1)
		return 1;
	return 0;
}

void push(struct stack *m,char z[]){
	m->top++;
	strcpy(m->k[m->top].exp,z);
}
int isAlpha(char c)
{
    if ( (c > 64 && c < 91) || ( c > 96 && c < 123 ))
		return 1;
    return 0;
}

void pti(char c[]){
	int i,k=0,l=strlen(c);
	char r[50],s1[50],s2[50],s3[2];
	struct stack m;
	m.top=0;
	m.size=l;
	m.k=(struct stv*)malloc(l*sizeof(struct stv));
	for(i=l-1;i>-1;i--)
	{
		if(isAlpha(c[i])){
			s3[0]=c[i];
			s3[1]='\0';
			push(&m,s3);
		}
		else
			{
			char s[50];
			strcpy(s1,pop(&m));
			strcpy(s2,pop(&m));
			s3[0]=c[i];
			s3[1]='\0';
			strcpy(s,s1);
			strcat(s,s2);
			strcat(s,s3);
			push(&m,s);
			}
}
	printf("The POSTFIX exp is\n\t\t%s",pop(&m));
}

int main(){
	char c[50];
	printf("Infix to prefix:-\n\t\t");
	scanf("%s",c);
	pti(c);
	}
