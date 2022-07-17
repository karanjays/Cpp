#include<bits/stdc++.h>
using namespace std;

vector<int> ans[6];
void sieve()
{	
	
	int p[100001],p1[100001];
	
	for(int i=2;i<100001;++i)
		p[i]=1,p1[i]=0;
	
	for(int i=2;i*i<100001;++i)
	{
		if(p[i])
		{
			for(int j=i*i;j<100001;j+=i)
				p[j]=0;
		}
	}
	
	for(int i=2;i<100001;++i)
	{
		if(p[i])
		{
			for(int j=i;j<100001;j+=i)
			{
				++p1[j];
			}
		}
	}
	
	for(int i=2;i<100001;++i)
	{
		if(p1[i]<=5)
		{
			ans[p1[i]].push_back(i);
		}
		
	}
}


int main(){
	int z;
	cin>>z;
	while(z--)
	{
		int a,b,k;
		cin>>a>>b>>k;
		sieve();
		vector<int>::iterator it1=find(ans[k].begin(),ans[k].end(),a);
		vector<int>::iterator it2=find(ans[k].begin(),ans[k].end(),b);
		cout<<*it2-*it1<<endl;
			
	}
}
