//1. In a classroom of 100 students you have to divide students in 10 sub list
//of equal
//students.
//Perfrom the following operation.
//1. Insertation of marks.
//2. Deletion of marks.
//3. Updation of marks.
//4. Display marks
//5. Replace one sub list with other
//6. Compare two sub list
//7. Enter nth element in jth list


#include<stdio.h>

int A[50],i,j,n;

int insert(){
for(i=10;i<20;i++){
scanf("%d",&A[i]);
}
}

void delet(int x){
if(x<0 || x>50)
printf("Invalud index.!.\n");
else
A[x]=0;
}

void display(){
printf("\tlist 1\tlist 2\tlist 3\tlist 4\tlist 5\n");
for(i=0;i<10;i++){
printf("\t%d= %d\t%d= %d\t%d= %d\t%d= %d\t%d=%d\n",i+1,A[i],i+1,A[i+10],i+1,A[i+20],i+1,A[i+30],i+1,A[i+40]);
}
}
void update(int x,int n){
if(x<0 || x>49)
printf("Invalud index.!.\n");
else
A[x]=n;
}
void exsub(int x,int y){
if(x<0 || y<0 || x>49 || y>49)
printf("Invalud index.!.\n");
else
for(i=0;i<10;i++){
n=A[x+i];
A[x+i]=A[x*10+i];
A[y+i]=n;
}
}
void cmp(int x,int y){
if(x<0 || x>49 ||y<0 || y>49)
printf("Invalud index.!.\n");
else
{
for(i=0;i<10;i++){
if(A[x+i]>A[y+i])
printf("The %d element of list %d is greater than list %d.\n",i+1,(x/10)+1,(y/10)+1);
else if(A[x+i]<A[y+i])
printf("The %d element of list %d is smaller than list %d.\n",i+1,(x/10)+1,(y/10)+1);
else
printf("Both are equal.\n");
}
}
}
void rev(int x,int y,int z){
if(x<0 || y<0 || x>49 || y>9 || z<0 || z>9)
printf("Invalud index.!.\n");
else{
A[x+z]=A[x+y];
}
}
int menu(){
int n;
printf("\n\t\t\t\t MENU");
printf("\n\t\t\t\t1. Insert a mark");
printf("\n\t\t\t\t2. Delet a mark");
printf("\n\t\t\t\t3. Update a mark");
printf("\n\t\t\t\t4. Display a mark");
printf("\n\t\t\t\t5. Replace one sub string with other");
printf("\n\t\t\t\t6. Compare 2 sublist");
printf("\n\t\t\t\t7. Replace nth element in jth");
printf("\n\t\t\t\t8. Exit");
printf("\nEnter ur choice:-\n\t\t");
scanf("%d",&n);
return n;
}
void main()
{while(1)
{
system("cls");
switch(menu())
{
case 1:
insert();
display();
break;
case 2:
printf("Mark to delet of list and sublist\n");
scanf("%d %d",&i,&j);
delet((i-1)*10+j-1);
display();
break;
case 3:
printf("Mark to update of list and sublist with update mark\n");
scanf("%d %d %d",&i,&j,&n);
update((i-1)*10+j-1,n);
display();
break;
case 4:
display();
break;
case 5:
printf("list to be replace with list\n");
scanf("%d %d",&i,&j);
exsub((i-1)*10,(j-1)*10);
display();
break;
case 6:
printf("list to be compare with list\n");
scanf("%d %d",&i,&j);
cmp((i-1)*10,(j-1)*10);
display();
break;
case 7:
printf("Replace nth element in jth of x list\n");
scanf("%d %d %d",&i,&j,&n);
rev((i-1)*10,j-1,n-1);
display();
break;
case 8:
exit(0);
default:
printf("\nPlz Enter Valid choice...!!!...\n");
}
system("pause");
}
}


//2. Write a program to generate sub matrices from the multidimensional
//matrix.


//#include<stdio.h>
//int main(){
//int m,n,i,j,l;
//printf("Enter the no. of Row and Columns.\n");
//scanf("%d%d",&m,&n);
//printf("Enter the no. of Row for sq sub matrix.\n");
//scanf("%d",&l);
//while(l*l>m*n){
//printf("\tThe entered no. of rows is incorrect.\nRe-enter the no. of Row for sq sub matrix.\n");
//scanf("%d",&l);
//}
//int K[m][n],L[l][l],M[l][l],S[l][l];
//printf("Enter the no. according to rows\n");
//for(i=0;i<m;i++){
//for(j=0;j<n;j++){
//K[i][j]=i+j;
//}
//}
//printf("The 1st matrix is:-\n");
//for(i=0;i<l;i++){
//for(j=0;j<l;j++){
//L[i][j]=K[i][j];
//M[i][j]=K[j][j];
//S[i][j]=M[i][j]+L[i][j];
//printf("%d\t",L[i][j]);
//}
//printf("\n");
//}
//printf("The 2nd matrix is:-\n");
//for(i=0;i<l;i++){
//for(j=0;j<l;j++){
//printf("%d\t",M[i][j]);
//}
//printf("\n");
//}
//printf("The Sum of matrix is:-\n");
//for(i=0;i<l;i++){
//for(j=0;j<l;j++){
//printf("%d\t",S[i][j]);
//}
//printf("\n");
//}
//}
