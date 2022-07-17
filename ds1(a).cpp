//Write a C program to find maximum element in Array.


#include<stdio.h>
int main(){
 int n,i,m=0;
 scanf("%d",&n);
 int a[n];
 for(i=0;i<n;i++){
 scanf("%d",&a[i]);
 if(m<a[i])m=a[i];
 }
 printf("The maximum value is %d",m);
}

/*
OUTPUT :-
 5
8 16 99 22 45
The maximum value is 99
*/


