//Write a C program to find minimum element in Array.


#include<stdio.h>
int main(){
 int n,i,m=999999;
 scanf("%d",&n);
 int a[n];
 for(i=0;i<n;i++){
 scanf("%d",&a[i]);
 if(m>a[i])m=a[i];
 }
 printf("The minimum value is %d",m);
}

/*
OUTPUT :-
 5
12 14 16 18 20
The minimum value is 12
*/

