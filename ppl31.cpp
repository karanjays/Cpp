#include<bits/stdc++.h>
using namespace std;

int main(){
	string uname;
	int z=3;
	while(z--){
	cout<<"Enter user name : \t";
	cin>>uname;
	int k=uname.length();
	
	try{
		if((uname.size()>=7) && ((uname[0]>=97 && uname[0]<=122) || (uname[0]>=65 && uname[0]<=90)))
			cout<<uname<<" as user name is valid.\n";	
		else
			throw k;
	}
	
	catch(int x){
		if(x<7)
			cout<<uname<<" as user name is too short.\n";
		else
			cout<<uname<<" as user name is Invalid!.\n";
			
	}
	}	
	
	return 0;
}
