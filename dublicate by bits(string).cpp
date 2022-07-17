#include <bits/stdc++.h>
using namespace std;

int main(){
	string m="KARANRAJJAYSWAL";
	char k;
	int h=0,i=0,x=0;
	for(i=0;m[i]!='\0';i++){
		x=1;
		x=x<<(m[i]-65);
		if((x&h)>0){
			cout<<m[i]<<" is dublicate.\n";
		}
		else
			h=x|h;
	}
}
