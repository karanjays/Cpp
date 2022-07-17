#include<stdio.h>
#include<string.h>

int main(){
	char cmt[200];
	int z=3;
	while(z--){
		
	printf("Enter your Statement :-\n\n\t\t");
	gets(cmt);
	int n=strlen(cmt);
	
	if(cmt[0]=='/' && cmt[1]=='/')
		printf("\n\t\t-->It is Single line comment.\n");
	
	else if(cmt[0]=='/' && cmt[1]=='*' && cmt[n-2]=='*' && cmt[n-1]=='/')
		printf("\n\t\t-->It is a Multi line comment.\n");
	
	else
		printf("\n\t\t-->It is not a comment.\n");
	}
	return 0;
}
