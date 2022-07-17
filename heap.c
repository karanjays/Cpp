#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void mH(int A[],int L,int i);
void HS(int A[],int L);
void HI(int A[],int *L,int data);
void HD(int A[],int *L);
void DisplayHeap(int A[],int L);
void CreateHeap(int arr[], int L);


int main(){
int L,i,arr[20];
printf("Enter size: ");
scanf("%d",&L);
printf("Enter elements: ");
for(i=1;i<=L;i++){
scanf("%d",&arr[i]);
}
//Building Heap
CreateHeap(arr,L);
printf("\nAfter building the heap is: ");
DisplayHeap(arr,L);
//Inserting in Heap
HI(arr,&L,74);
//Deleting in Heap
HD(arr,&L);
//Sorting
HS(arr,L);
}
void mH(int A[],int L,int i){
int temp;
int largest=i;
int l=(2*i);
int r=(2*i)+1;
while(l<=L && A[l]>A[largest]){
largest=l;
}
while(r<=L && A[r]>A[largest]){
largest=r;
}
if(largest!=i){
temp=A[i];
A[i]=A[largest];
A[largest]=temp;
mH(A,L,largest);
}
}
void HS(int A[],int L){
int i,temp;
/* for(i=L/2;i>=1;i--){
mH(A,L,i);
}*/
for(i=L;i>1;i--){
temp=A[1];
A[1]=A[i];
A[i]=temp;
mH(A,i-1,1);
}
printf("Sorted heap is: ");
DisplayHeap(A,L);
}
void HI(int A[],int *L,int data){
int temp;
*L=*L+1;
A[*L]=data;
int i=*L,parent;
while(i>1){
parent=floor(i/2);
if(A[parent]<A[i]){
temp=A[i];
A[i]=A[parent];
A[parent]=temp;
i=parent;
}
else{
return;
}
}
printf("After insertion of %d heap is: ",data);
DisplayHeap(A,*L);
}
void HD(int A[],int *L){
if(*L<1){
return;
}
int temp;
temp=A[1];
A[1]=A[*L];
A[*L]=temp;
*L=*L-1;
int i=1;
while(i<=floor(*L/2)){
int r1=2*i;
int r2=(2*i)+1;
if(A[r1]>A[r2] && r1<=(*L)){
temp=A[r1];
A[r1]=A[i];
A[i]=temp;
i=r1;
}else if(A[r1]<=A[r2] && r2<=(*L)){
temp=A[r2];
A[r2]=A[i];
A[i]=temp;
i=r2;
}else{
break;
}
}
printf("After deletion heap is: ");
DisplayHeap(A,*L);
}
void DisplayHeap(int A[],int L){
int i;
for(i=1;i<=L;i++){
printf("%d ",A[i]);
}
printf("\n\n");
}
void CreateHeap(int arr[], int L)
{
 int startIdx = (L / 2);
 int i;
 for (i = startIdx; i >= 1; i--) {
 mH(arr, L, i); 
 }
}
