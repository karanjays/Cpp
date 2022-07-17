// 1.Write a program to find the length of a given string.


#include<stdio.h>
#include "mystring.h"
int main(){
char a[25];
printf("Enter any string:-");
scanf("%s",&a);
int l;
l=length(a);
printf("%d",l);
return 0;
}

//
//
//2.Write a program to concate two given string.
//
//
//#include<stdio.h>
//#include "mystring.h"
//int main(){
//char a[25],b[25],c[50];
//printf("Enter 1st string:-");
//scanf("%s",&a);
//printf("Enter 2nd string:-");
//scanf("%s",&b);
//concate(a,b,c);
//printf("%s",c);
//return 0;
//}
//
//
//
//3.Write a program to copy one string to another string.
//
//
//#include<stdio.h>
//#include "mystring.h"
//int main(){
//char a[25],b[25];
//printf("Enter 1st string:-");
//scanf("%s",&a);
//copy(a,b);
//printf("%s",b);
//return 0;
//}
//
//
//4.Write a program to compare two given string.
//
//
//#include<stdio.h>
//#include "mystring.h"
//int main(){
//char a[25],b[25],c[50];
//int k=3;
//while(k--){
//printf("Enter 1st string:-");
//scanf("%s",&a);
//printf("Enter 2nd string:-");
//scanf("%s",&b);
//printf("%s\n\n",cmp(a,b));
//}
//return 0;
//}
//
//
//
//5.Write a program to search for the first occurrence of the character ‘c’ in
//the given string.
//
//
//#include<stdio.h>
//#include "mystring.h"
//void main(){
//char a[25],b[2];
//int k,n=2;
//while((n--)){
//printf("Enter 1st string:-\n");
//scanf("%s",&a);
//printf("Enter char to search:-\n");
//scanf("%s",&b);
//k=src(a,b);
//printf("It lies at %d place in string %s\n",k,a);
//}
//return 0;
//}
//
//
//6.Write a program to find sub string is there in given string or not?
//
//
//#include<stdio.h>
//#include "mystring.h"
//int main(){
//char a[25],b[25],c[50];
//int k=2;
//while(k--){
//printf("Enter 1st string:-");
//scanf("%s",&a);
//printf("Enter 2nd string:-");
//scanf("%s",&b);
//printf("%s\n\n",issubstr(a,b));
//}
//return 0;
//}
//
//
//7.Write a program to generate reverse of a string.
//
//
//#include<stdio.h>
//#include "mystring.h"
//int main(){
//char a[25];
//printf("Enter 1st string:-");
//scanf("%s",&a);
//rev(a);
//printf("%s",a);
//return 0;
//}
