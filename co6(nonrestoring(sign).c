//signed binary numbers using Restoring and NonRestoring Methods.

#include<stdio.h>
void binaryaddition(int *ans,int *add);
void binarycomponent(int *a);
int f=0;
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
 int res[9]={0};
 for(int i=0;i<9;i++) res[i]=a[i]?0:1;
 int ones[9]={0};
 ones[0]=1;
 binaryaddition(res,ones);
 for(int i=0;i<9;i++) a[i]=res[i];
}
void binaryaddition(int *ans,int *add){
 int j=0;
 for(int i=0;i<9;i++){
 ans[i]=add[i]+ans[i]+j;
 if(ans[i]>1){
 ans[i]=ans[i]%2;
 j=1;
 }
 else j=0;
 }
}
void lsr(int *ans,int *div,int len){
 int k=div[7];
 for(int i=len-1;i>0;i--){
 ans[i]=ans[i-1];
 div[i]=div[i-1];
 }
 ans[0]=k;
}
void restoremethod(int divisor,int divident,int *ans){
 int b[9],a[9],q[9],nb[9];
 int count=8;
 decimaltobinary(divisor,b);
 decimaltobinary(divident,q);
 decimaltobinary(-divisor,nb);
 for(int i=0;i<9;i++) a[i]=0;
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
 for(int i=0;i<8;i++) ans[0]+=a[i]*(1ll<<i);
 for(int i=0;i<8;i++) ans[1]+=q[i]*(1ll<<i);
 if(f){
 binarycomponent(q);
 binarycomponent(a);
 ans[0]*=-1;
 ans[1]*=-1;
 }
 printf("\n\n-----------------------------\n\n");
 printf("The value of remainder in binary form is\n");
 for(int i=7;i>=0;i--) printf("%d",a[i]);
 printf("\nThe value of quotient in binary form is\n");
 for(int i=7;i>=0;i--) printf("%d",q[i]);
 printf("\n\n-----------------------------\n\n");
}
int main(){
 int n=0,m=0;
 int len;
 printf("Please enter the length of binary string\n");
 scanf("%d",&len);
 char div[len+1],divi[len+1];
 printf("Please enter the value of divisor\n");
 scanf("%s",&div);
 if(div[0]=='1'){
 f^=1;
 }
 for(int i=0;i<len;i++) div[i]=div[i+1];
 printf("Please enter the value of Dividend\n");
 scanf("%s",&divi);
 if(divi[0]=='1'){
 f^=1;
 }
 for(int i=0;i<len;i++) divi[i]=divi[i+1];
 for(int i=0,j=len-2;i<len;i++,j--) n+=(1ll<<j)*(div[i]-'0');
 for(int i=0,j=len-2;i<len;i++,j--) m+=(1ll<<j)*(divi[i]-'0');
 int ans[2];
 restoremethod(n,m,ans);
 printf("The remainder value is %d\n",ans[0]);
 printf("The quotient value is %d\n",ans[1]);
 printf("\n\n-----------------------------\n\n");
}
