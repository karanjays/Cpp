#include<string.h>
#include<stdlib.h>

struct Array{
	int *k;
	int s;
	int l;
};

struct Array *m;

int menu(){
	int n;
	printf("\a\n\t\t\t\t    MENU");
	printf("\n\t\t\t\t1.  Display");
	printf("\n\t\t\t\t2.  Append");
	printf("\n\t\t\t\t3.  Insert");
	printf("\n\t\t\t\t4.  Delet");
	printf("\n\t\t\t\t5.  Search");
	printf("\n\t\t\t\t6.  Get");
	printf("\n\t\t\t\t7.  Set");
	printf("\n\t\t\t\t8.  Maximum");
	printf("\n\t\t\t\t9.  Minimum");
	printf("\n\t\t\t\t10. Reverse");
	printf("\n\t\t\t\t11. Rotate");
	printf("\n\t\t\t\t12. shorted insert");
	printf("\n\t\t\t\t13. Issorted");
	printf("\n\t\t\t\t14. Arrange -ve at left");
	printf("\n\t\t\t\t15. Mergin");
	printf("\n\t\t\t\t16. Union");
	printf("\n\t\t\t\t17. Intersection");
	printf("\n\t\t\t\t18. Difference");
	printf("\n\t\t\t\t19. Setmembership");
	printf("\n\t\t\t\t20. Exit.");
	printf("\n\nEnter your choice:- \n ");
	scanf("%d",&n);
	return n;
}

void Display(struct Array a){
	int i;
	for(i=0;i<a.l;i++)
		printf("%d\n",a.k[i]);
}

void Append(struct Array *a,int n){
	if(a->l<a->s)
	{
		a->k[a->l++]=n;
	}
	else
		printf("dont have enough space.\n");
}

void Insert(struct Array *a,int m,int n){
	int i;
	if(a->l<a->s && n>=0 && n<a->l)
	{
		for(i=a->l;i>n;i--)
			a->k[i]=a->k[i-1];
		a->k[n]=m;
		a->l++;
	}
	else
		printf("dont have enough space.\n");
}

void Delet(struct Array *a,int n){
	int i;
	if( n>=0 && n<a->l)
	{
		for(i=n;i<a->l;i++)
			a->k[i]=a->k[i+1];
		a->l--;
	}
}

void Search(struct Array a,int n){
	int l=0,h=a.l-1,m;
	while(l<=h){
		m=(l+h)/2;
		if(n==a.k[m]){
			printf("Search sucessful at %d \n",m);
			break;
		}
		else if(a.k[m]>n){
			h=m-1;
		}
			
		else if(a.k[m]<n){
			l=m+1;
		}
	}
	if(l>h){
		printf("Search unsucessful\n");
	}
}

void Get(struct Array *a,int n){
	if(n>=0 && n<a->l)
		printf("%d",a->k[n]);
	else
		printf("Invalid index");
}

void Set(struct Array *a,int m,int n){
	if(n>=0 && n<a->l)
		a->k[n]=m;
	else
		printf("Invalid index");
}

void Max(struct Array *a){
	int i,m=0;
	for(i=0;i<a->l;i++)
	{
		if(m<a->k[i])
			m=a->k[i];
	}
	printf("%d",m);
}

void Min(struct Array *a){
	int i,m=a->k[0];
	for(i=1;i<a->l;i++)
	{
		if(m>a->k[i])
			m=a->k[i];
	}
	printf("%d",m);
}

void Reverse(struct Array *a){
	int i,t,k=a->l-1;
	for(i=0;i<a->l/2;i++){
		t=a->k[i];
		a->k[i]=a->k[k];
		a->k[k--]=t;
	}
}

void Rotate(struct Array *a){
	int i,t=a->k[a->l-1];
	for(i=a->l-1;i>0;i--){
		a->k[i]=a->k[i-1];
	}
	a->k[0]=t;
}

void sInsert(struct Array *a,int n){
	int i=a->l-1;
	if(a->l<a->s)
	{
		while(n<a->k[i]){
			a->k[i+1]=a->k[i];
			i--;
		}
			
		a->k[i+1]=n;
		a->l++;
	}
	else
		printf("dont have enough space.\n");
}

void IsSort(struct Array *a){
	int i=0;
	for(;i<a->l-1;i++){
		if(a->k[i]>a->k[i+1]){
			printf("Is not Sorted.\n");
			i--;
			break;
		}
	}	
	if(i==a->l-1)
		printf("IsSorted.\n");
}

void arr(struct Array *a){
	int i=0,j=a->l-1,t;
	while(i<j){
		while(a->k[i]<0)i++;
		while(a->k[j]>=0)j--;
		if(i<j){
			t=a->k[j];
			a->k[j]=a->k[i];
			a->k[i]=t;
		}
	}
}

void Merg(struct Array a,struct Array b,struct Array *c){
	int i,j,k;
	i=j=k=0;
	while(i<a.l && j<b.l){
		if(a.k[i]<b.k[j])
			c->k[k++]=a.k[i++];
		else
			c->k[k++]=b.k[j++];
	}
	for(;i<a.l;i++)
		c->k[k++]=a.k[i];
	for(;j<b.l;j++)
		c->k[k++]=b.k[j];
}

void Union(struct Array a,struct Array b,struct Array *c){
	int i,j,k;
	i=j=k=0;
	while(i<a.l)
		c->k[k++]=a.k[i++];
	for(;j<b.l;j++){
		for(i=0;i<a.l;i++){
			if(b.k[j]==c->k[i]){
				j++;
				break;
			}
		}
		if(i=a.l){
			c->k[k++]=b.k[j];
		}
	}
	c->l=k;
}

void Inter(struct Array a,struct Array b,struct Array *c){
	int i,j,k;
	i=j=k=0;
	for(;j<b.l;j++){
		for(;i<a.l;i++){
			if(b.k[j]==a.k[i]){
				c->k[k++]=a.k[i++];
				break;
			}
		}}
	c->l=k;
}


void Dif(struct Array b,struct Array a,struct Array *c){
	int i,j,k,l=1;
	i=j=k=0;
	for(;j<b.l;j++){
		l=1;
		for(;i<a.l;i++){
			if(b.k[j]==a.k[i]){
				l=0;
				break;
			}
		}
	if(l==1){
		c->k[k++]=b.k[j];
	}
		}
	c->l=k;
}

void main(){
	int i,j;
	struct Array ar; 
	struct Array ar3;
	struct Array ar2;
	printf("Enter the size of Array.\n");
	scanf("%d",&ar.s);
	printf("Enter the length of Array.\n");
	scanf("%d",&ar.l);
	ar.k=(int*)malloc(ar.s*sizeof(int));
	printf("Enter the elements of Array.\n");
	for(i=0;i<ar.l;i++)
	{
		scanf("%d",&ar.k[i]);
	}
	while(1)
	{
		system("cls");
		switch(menu())
		{
			case 1:
				Display(ar);
				break;
			case 2:
				printf("Element to add\n");
				scanf("%d",&i);
				Append(&ar,i);
				break;
			case 3:
				printf("Element to add at index (element and index)\n");
				scanf("%d%d",&i,&j);
				Insert(&ar,i,j-1);
				break;
			case 4:
				printf("Element to delet at index\n");
				scanf("%d",&i);
				Delet(&ar,i-1);
				break;
			case 5:
				printf("Element to search\n");
				scanf("%d",&i);
				Search(ar,i);
				break;
			case 6:
				printf("Index to get Element\n");
				scanf("%d",&i);
				Get(&ar,i-1);
				break;
			case 7:
				printf("Set Element(element and index)\n");
				scanf("%d%d",&i,&j);
				Set(&ar,i,j-1);
				break;
			case 8:
				printf("Maximum Element is ");
				Max(&ar);
				break;
			case 9:
				printf("Minimum Element is ");
				Min(&ar);
				break;
			case 10:
				Reverse(&ar);
				break;
			case 11:
				Rotate(&ar);
				break;
			case 12:
				printf("Element to insert\n");
				scanf("%d",&i);
				sInsert(&ar,i);
				break;
			case 13:
				IsSort(&ar);
				break;
			case 14:
				arr(&ar);
				break;
			case 15:
				printf("Enter the size of Merging Array.\n");
				scanf("%d",&ar2.s);
				ar2.l=ar2.s;
				ar2.k=(int*)malloc(ar2.s*sizeof(int));
				printf("Enter the elements of Array to merg.\n");
				for(i=0;i<ar2.l;i++)
				{
					scanf("%d",&ar2.k[i]);
				}
				ar3.l=ar.l+ar2.l;
				ar3.s=ar3.l;
				ar3.k=(int*)malloc(ar3.s*sizeof(int));
				Merg(ar,ar2,&ar3);
				printf("\nThe merg array is :-\n");
				Display(ar3);
				break;
			case 16:
				printf("Enter the size of 2nd Array.\n");
				scanf("%d",&ar2.s);
				ar2.l=ar2.s;
				ar2.k=(int*)malloc(ar2.s*sizeof(int));
				printf("Enter the elements of Array for union.\n");
				for(i=0;i<ar2.l;i++)
				{
					scanf("%d",&ar2.k[i]);
				}
				ar3.s=ar.l+ar2.l;
				ar3.k=(int*)malloc(ar3.s*sizeof(int));
				Union(ar,ar2,&ar3);
				printf("\nThe union is :-\n");
				Display(ar3);
				break;
			case 17:
				printf("Enter the size of 2nd Array.\n");
				scanf("%d",&ar2.s);
				ar2.l=ar2.s;
				ar2.k=(int*)malloc(ar2.s*sizeof(int));
				printf("Enter the elements of Array for union.\n");
				for(i=0;i<ar2.l;i++)
				{
					scanf("%d",&ar2.k[i]);
				}
				ar3.s=ar.l;
				ar3.k=(int*)malloc(ar3.s*sizeof(int));
				Inter(ar,ar2,&ar3);
				printf("\nThe Inter is :-\n");
				Display(ar3);
				break;
			case 18:
				printf("Enter the size of 2nd Array.\n");
				scanf("%d",&ar2.s);
				ar2.l=ar2.s;
				ar2.k=(int*)malloc(ar2.s*sizeof(int));
				printf("Enter the elements of Array for union.\n");
				for(i=0;i<ar2.l;i++)
				{
					scanf("%d",&ar2.k[i]);
				}
				ar3.s=ar.l;
				ar3.k=(int*)malloc(ar3.s*sizeof(int));
				Dif(ar,ar2,&ar3);
				printf("\nThe different element is :-\n");
				Display(ar3);
				break;
			case 20:
				exit(0);
			default:
				printf("\nPlz Enter Valid choice...!!!...\n");
				
		}
		system("pause");
	}
}
