#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,s=0,i,mx=-109,l=0;
	scanf("%d",&n);
	int m[n];
	for(i=0;i<n;i++){
		scanf("%d",&m[i]);
		if(mx<m[i])
			mx=m[i];
	}
	if(mx<0)
		printf("%d 1",mx);
	else{
		for(i=0;i<n;i++){
		if(m[i]>-1){
			s=s+m[i];
			l++;
		}
	}
	printf("%d %d",s,l);
	}
}
}

#include<stdio.h>
int main(){
	int i,j,n,t;
	scanf("%d",&t);
	while(t--){
		int mx=0;
		scanf("%d",&n);
		int A[n],B[n];
		
		for(i=0;i<n;i++)
		{scanf("%d",&A[i]);
		}
		for(i=0;i<n;i++)
		{
		scanf("%d",&B[i]);
}
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
			if(B[j]>=A[i])
			{
				if(j-i>mx)
				{
					mx=j-i;
				}
				
			}
			}
		}
		printf("%d",mx);
	}
}


