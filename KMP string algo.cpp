#include<bits/stdc++.h>
using namespace std;

void perparelps(string p,int *lps)
{
	int m=p.size();
	int i=0,j=1;
	
	while(j<m)
	{
		if(p[i]==p[j])
			lps[j++]=++i;
		else
		{
			if(i!=0)
				i=lps[i-1];
			else
				lps[j++]=0;
		}
	}
}

vector<int> kmp(string s,string p)
{
	int i=0,j=0,n=s.size(),m=p.size();
	int lps[m+1]={};
	vector<int>idx;
	
	perparelps(p,lps);
	
	while(i<n)
	{
		if(s[i]==p[j])
			++i,++j;
			
		if(j==m)
		{
			idx.push_back(i-m);
		}
		
		
		if(i<n && s[i]!=p[j])
		{
			if(j!=0)
				j=lps[j-1];
			else
				++i;
		}
	}
	return idx;
}

int main()
{
	string s,p;
	cin>>s>>p;
	
	auto v=kmp(s,p);
	for(auto a:v)
		cout<<a<<" ";
}
