#include<bits/stdc++.h>
using namespace std;

void rjmp(int x,int y,int a,int b)
{
//	int s=0;
//		while(1)
//		{
//			++s;
//			x=x+a;
//			y=y-b;
//			if(x==y)
//			{
//				cout<<s<<endl;
//				return;
//			}
//			else if(y<x)
//			{
//				cout<<-1<<"n";
//				return;
//			}
//			
//		}

	if( (y-x)% (a+b)==0 )
	{
		int t=(y-x)/(a+b);
		cout<<t<<endl;
	}
	else
		cout<<-1<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y,a,b;
		cin>>x>>y>>a>>b;
		rjmp(x,y,a,b);
	}
}
