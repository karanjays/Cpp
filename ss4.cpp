#include<stdio.h>
#include<string.h>

void recognize_str(char str[50]){
	int i=0,n=strlen(str);
	
	if(n==3 && str[0]=='a' && str[1]=='b' && str[2]=='b'){
		printf("\n\n%s is verified as abb.\n",str);
		return;
	}
	
	//a*
	for(i=0;i<n;i++){
		if(str[i]!='a')
			break;
	}
	if(i==n){
		printf("\n\n%s is verified as a*.\n",str);
		return;
	}
	
	
	//a*b+
	int v=0;
	for(i=0;i<n;i++){
		if(v==0 && str[i]=='a')
			v=0;
		else if((v==0 || v==1) && str[i]=='b')
			v=1;
		else if( v==1 && str[i]=='a'){
			printf("\n\n%s is unrecognized.\n",str);
			return;			
		}
		else if(str[i]!='b' && str[i]!='a'){
			printf("\n\n%s is unrecognized.\n",str);
			return;			
		}
	}
	if(v==1){
		printf("\n\n%s is verified as a*b+.\n",str);
		return;
	}
}

int main(){
	char str[50];
	int z=5;
	
	while(z--){
		printf("\nEnter any string :- \n\t\t");
		gets(str);
		recognize_str(str);
	}
	return 0;
}
