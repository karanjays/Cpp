
//Write a C Program to concatenate array.


#include<stdio.h>
int main(){
 int n,m,i,j,k=0;
 scanf("%d %d",&n,&m);
 int a[n],b[m],c[m+n-1];
 printf("The 1st array value is\n");
 for(i=0;i<n;i++){
 printf("\t\t");
 scanf("%d",&a[i]);
 c[k++]=a[i];
 }
 printf("The 2nd array value is\n");
 for(i=0;i<m;i++){
 printf("\t\t");
 scanf("%d",&b[i]);
 c[k++]=b[i];
 }
 printf("The array concatenation is ");
 for(i=0;i<k;i++)
 printf("%d ",c[i]);
}

/*
OUTPUT :-
 5 7
The 1st array value is
 11
 22
 33
 44
 55
The 2nd array value is
 66
 77
 88
 99
 111
 222
 333
The array concatenation is 11 22 33 44 55 66 77 88 99 111 222 333
*/
