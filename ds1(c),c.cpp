
// Write a C program to find second maximum element in array.


#include<stdio.h>
int main(){
 int n,i,m=0,m2=0;
 scanf("%d",&n);
 int a[n];
 for(i=0;i<n;i++){
 scanf("%d",&a[i]);
 if(m<a[i])m=a[i];
 }
 for(i=0;i<n;i++){
 if(m2<a[i] && a[i]!=m)m2=a[i];
 }
 printf("The second maximum value is %d",m2);
}

/*
OUTPUT :-
 5
12 14 16 18 20
The second maximum value is 18
*/

