#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct terms{
	int c;
	int e;
};

struct poly{
	int n;
	struct terms *t;
};


void create(struct poly *s){
	int i=0;
	printf("Enter the no. of non zero:-\n");
	scanf("%d",&s->n);
	s->t=(struct terms*)malloc(s->n*sizeof(struct terms));
	printf("Enter the no. of coff. and exponcial:-\n");
	for(i=0;i<s->n;i++){
		printf("the %d terms is :-\n\t",i+1);
		scanf("%d%d",&s->t[i].c,&s->t[i].e);
	}
}

void display(struct poly s){
	int i;
	for(i=0;i<s.n;i++){
		printf("%dx%d + ",s.t[i].c,s.t[i].e);
	}
}

struct poly *add(struct poly *s1,struct poly *s2){
	int i,j,r,k=0;
	r=s1->n+s2->n;
	struct poly *sum;
	sum=(struct poly*)malloc(sizeof(struct poly));
	sum->t=(struct terms*)malloc(r*sizeof(struct terms));
	i=j=k=0;
	while(i<s1->n && j<s2->n)
	{
		if(s1->t[i].e==s2->t[j].e){
			sum->t[k].e=s1->t[i].e;			
			sum->t[k++].c=s1->t[i++].c+s2->t[j++].c;
		}
		else if(s1->t[i].e<s2->t[j].e)
			sum->t[k++]=s2->t[j++];
		else
			sum->t[k++]=s1->t[i++];
	}
	for(;i<s1->n;i++)sum->t[k++]=s1->t[i];
	for(;j<s2->n;j++)sum->t[k++]=s2->t[j];
	sum->n=k;
	return sum;
}

int main(){
	struct poly p1;
	struct poly p2;
	struct poly *p3;
	create(&p1);
	create(&p2);
	p3=add(&p1,&p2);
	printf("\n\n");
	display(p1);
	printf("\n\n");
	display(p2);
	printf("\n\n");
	display(*p3);
	return 0;
}

