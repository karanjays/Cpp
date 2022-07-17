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

void ispalindrome(struct stack*m,char s[]){
	int j,i=strlen(s)/2;
	char z;
	for(j=0;j<i;j++)
		push(m,s[j]);
	strlen(s)%2==1?i++:1;
	while(i<strlen(s)){
		z=pop(m);
		if(z!=s[i++]){
			printf("IS Not A Palidrom\n");
			break;}
	}
	if(i==strlen(s))
		printf("IS A Palidrom\n");		
}

int main(){
	char z,x[15];
	printf("Enter the word to check ispalindrome or not\n");
	scanf("%s",&x);
	struct stack m;
	m.top=-1;
	m.size=strlen(x);
	m.k=(char*)malloc(m.size*sizeof(char));
	ispalindrome(&m,x);
	}
