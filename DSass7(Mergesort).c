//Merge sort

#include<stdio.h>

//Merge function
void Merge(int *K,int lb,int mid,int ub){
	int i,j,k;
	i=lb;
	j=mid+1;
	k=0;
	int B[ub-lb+1];
	while(i<=mid && j<=ub){
		if(K[i]<=K[j])
			B[k++]=K[i++];
		else
			B[k++]=K[j++];
	}
	while(j<=ub)B[k++]=K[j++];
	while(i<=mid)B[k++]=K[i++];
	for(i=0;i+lb<=ub;i++)
	{
	K[i+lb]=B[i];	
	}
}
//sorting function
void Mergesort(int *K,int lb,int ub){
	int mid;
	if(lb<ub)
	{
		mid=(lb+ub)/2;
		Mergesort(K,lb,mid);//Recursion
		Mergesort(K,mid+1,ub);//Recursion	
		Merge(K,lb,mid,ub);//Merge function call
	}
}
//returning address of array
int main(){
	int i,m;
	printf("Enter the no. of elements in an array.\n\t\t\t");
	scanf("%d",&m);
	int K[m];
	for(i=0;i<m;i++)
	{
		printf("Enter the value %d element of Array.\n\t\t\t\t",i+1);
		scanf("%d",&K[i]);
	}
	Mergesort(K,0,m-1);
	printf("\nMerge Sort\n");
	for(i=0;i<m;i++){
		printf("Enter the value %d element of Array.\n\t\t\t\t%d\n",i+1,K[i]);
	}
	return 0;
}
