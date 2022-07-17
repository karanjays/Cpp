//1. Write a C code to perform division of two unsigned binary numbers using
//Restoring Method.
//CODE:-


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void binaryaddition(int *ans,int *add);
void binarycomponent(int *a);
void decimaltobinary(int n,int *a){
int i=0;
int flag=0;
if(n<0){
n=-n;
flag=1;
}
while(i<9){
a[i]=n%2;
n/=2;
i++;
}
if(flag){
binarycomponent(a);
}
}
void binarycomponent(int *a){
int res[9]={0},i;
for(i=0;i<9;i++) res[i]=a[i]?0:1;
int ones[9]={0};
ones[0]=1;
binaryaddition(res,ones);
for(i=0;i<9;i++) a[i]=res[i];
}
void binaryaddition(int *ans,int *add){
int j=0,i;
for(i=0;i<9;i++){
ans[i]=add[i]+ans[i]+j;
if(ans[i]>1){
ans[i]=ans[i]%2;
j=1;
}
else j=0;
}
}
void lsr(int *ans,int *div,int len){
int k=div[7],i;
for(i=len-1;i>0;i--){
ans[i]=ans[i-1];
div[i]=div[i-1];
}
ans[0]=k;
}
void restoremethod(int divisor,int divident,int *ans){
int b[9],a[9],q[9],nb[9];
int count=8,i;
decimaltobinary(divisor,b);
decimaltobinary(divident,q);
decimaltobinary(-divisor,nb);
for(i=0;i<9;i++) a[i]=0;
while(count--){
lsr(a,q,9);
binaryaddition(a,nb);
if(a[8]){
q[0]=0;
binaryaddition(a,b);
}
else{
q[0]=1;
}
}
ans[0]=0,ans[1]=0;
for(i=0;i<8;i++) ans[0]+=a[i]*(1ll<<i);
for(i=0;i<8;i++) ans[1]+=q[i]*(1ll<<i);
printf("\n\n");
printf("The value of remainder in binary form is: ");
for(i=7;i>=0;i--) printf("%d",a[i]);
printf("\nThe value of quotient in binary form is: ");
for(i=7;i>=0;i--) printf("%d",q[i]);
printf("\n\n");
}
int btod(char* b, int n)
{
int res = 0;
int i = n -1;
int p2 = 1;
for( ; i >= 0; i--)
{
res += p2*(b[i] - 48);
p2*=2;
}
return res;
}
int main(){
char* N[8],M[8];
printf("Enter dividend in binary form: ");
scanf("%s",M);
printf("Enter divisior in binary form: ");
scanf("%s",N);
int n = btod(N,strlen(N));
int m = btod(M,strlen(M));
int ans[2];
restoremethod(n,m,ans);
printf("The remainder value is: %d",ans[0]);
printf("\nThe quotient value is: %d\n",ans[1]);
printf("\n\n");
}
