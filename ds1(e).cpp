//Write a C Program to copy an array to another array in reverse.


#include<stdio.h>
int main(){
 int n,i,j;
 scanf("%d",&n);
 int a[n],b[n];
 for(i=0,j=n-1;i<n;i++){
 scanf("%d",&a[i]);
 b[j--]=a[i];
 }printf("The Reverse array is ");
 for(i=0;i<n;i++)
 printf("%d ",b[i]);
}
/*
OUTPUT :-
 5
14 16 18 20 22
The Reverse array is 22 20 18 16 14
*/

