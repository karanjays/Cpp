

//Write a C program to find second minimum element in array.


#include<stdio.h>
int main(){
 int n,i,m,m2;
 m2=m=999999;
 scanf("%d",&n);
 int a[n];
 for(i=0;i<n;i++){
 scanf("%d",&a[i]);
 if(m>a[i])m=a[i];
 }
 for(i=0;i<n;i++){
 if(m2>a[i] && a[i]!=m)m2=a[i];
 }
 printf("The second minimum value is %d",m2);
}

/*
OUTPUT :-
 8
 12 14 16 -9 1 4 6 8 10
The second minimum value is 1
*/


