#include<stdio.h>
#include<string.h>

int main(){
	char idf[20];
	int n,i,f=0,z=3;
	
	while(z--){	
	f=0;
	printf("Enter your statement.\n\t\t");
	gets(idf);
	n=strlen(idf);
	
	if(!( (idf[0]>='a' && idf[0]<='z') || (idf[0]>='A' && idf[0]<='Z') || idf[0]=='_' || idf[0]=='$'))
		f=1;
	
	
	for(i=1;i<n;i++)
		if(!( (idf[i]>='a' && idf[i]<='z') || (idf[i]>='A' && idf[i]<='Z') || (idf[i]>='0' && idf[i]<='9') || idf[i]=='_' || idf[i]=='$'))
			f=1;
			
	if(f==1)
		printf("\n\t\t Sorry ! identifier is not valid.\n");
	else
		printf("\n\t\t Identifier is valid.\n");
	}
}
