#include<bits/stdc++.h>
using namespace std;



int main(){
	int n;
	cin>>n;
	while(n--)
	{
		int m,k;
		cin>>m>>k;
		cout<<min(min(m,k),(m+k)/3)<<endl;	
	}
	return 0;
}
