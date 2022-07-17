//bubble sort

#include<stdio.h>

//sorting function

int* Bubblesort(int K[],int m){
	int i,j,temp;
	for(i=m-1;i>0;i--){
		j=0;
		while(j<i){
			if(K[j]>K[j+1])
			{
			temp=K[j];
			K[j]=K[j+1];
			K[j+1]=temp;
		}
			j++;
		}
	}
	return K;
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
	K[m]=Bubblesort(K,m);
	printf("\n\n");
	for(i=0;i<m;i++){
		printf("Enter the value %d element of Array.\n\t\t\t\t%d\n",i+1,K[i]);
	}
}
