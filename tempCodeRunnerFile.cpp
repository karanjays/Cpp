#include <bits/stdc++.h>
#define ll long long int
#define ff(i, k, n) for (ll i = k, i < n, ++i)
using namespace std;

void solve()
{
	// ll n,m;
	string n,m,k="";
	cin>>n>>m;
	
	if(n==m){
		cout<<"YES\n";
		return;}
	unordered_map<char,int>mp;

	for(auto a:m)
		++mp[a];

	for(auto a:n)
		if(mp.count(a))
			k+=a;
	if(m.size()>k.size())
	{	cout<<"NO\n";
		return;}
	int x=k.size()+5,f;
	for(int i=m.size()-1;i>-1;--i)
	{
		f=1;
		for(int j=k.size()-1;j>-1;--j)
		{
			// cout<<j<<m[i]<<k[j]<<endl;
			if(m[i]==k[j])
			{
				f=0;
				k[j]='1';
				if(x<j)
				{
					cout<<"NO\n";
					return;
				}
				else
					x=j;
					break;
			}
		}
		
		if(f)
			{
				cout<<"NO\n";
				return;
			}
	}
	cout<<"YES\n";
	
	// cout << fixed << setprecision(9) <<ans*d/50;d
	// cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll karan;
	cin >> karan;
	while (karan--)
		solve();
}
