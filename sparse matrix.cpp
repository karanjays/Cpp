#include<bits/stdc++.h>
using namespace std;

class Element{
	public:
	int i;
	int j;
	int n;
};

class sparse{
	private:
		int x;
		int y;
		int m;
		Element *e;
		
	public:
		sparse(int x,int y,int m){
			this->x=x;
			this->y=y;
			this->m=m;
			e=new Element[this->m];
		}
		~sparse(){
			delete []e;
		}
		
		friend istream & operator>>(istream &is,sparse &s);
		friend ostream & operator<<(ostream &os,sparse &s);
		sparse operator+(sparse &s);
	};
	
		
		
		istream & operator>>(istream &in,sparse &s)
		{
			int i;
			cout<<"Enter all non zero element with row and column:-\n";
			for(i=0;i<s.m;i++)
				cin>>s.e[i].i>>s.e[i].j>>s.e[i].n;	
				return in;
			}
		
		ostream & operator<<(ostream &ot,sparse &s)
		{
			int i,j,k=0;
			for(i=0;i<s.x;i++){
				for(j=0;j<s.y;j++){
					if(i==s.e[k].i&& j==s.e[k].j)
						cout<<s.e[k++].n<<" ";
					else
						cout<<"0 ";
				}
				cout<<"\n";
			}
			return ot;
		}
		sparse sparse::operator+(sparse &s)
		{
			int i,j,k;
//			if(x!=s.x || y!=s.y){
//				return NULL;
//			}
			sparse *s1=new sparse(x,y,m+s.m);
			i=0,j=0,k=0;
			while(i<m && j<s.m){
				if(e[i].i<s.e[j].i){
					s1->e[k++]=e[i++];
				}
				else if(e[i].i>s.e[j].i){
					s1->e[k++]=s.e[j++];
				}
				else{
					if(e[i].j<s.e[j].j){
					s1->e[k++]=e[i++];
					}
					else if(e[i].j>s.e[j].j){
						s1->e[k++]=s.e[j++];
					}
					else{
						s1->e[k]=e[i];
						s1->e[k++].n=e[i++].n+s.e[j++].n;
					}
				}
			}
				for(;i<m;i++)
					s1->e[k++]=e[i];
				for(;j<s.m;j++)
					s1->e[k++]=s.e[j];
				s1->m=k;
				return *s1;
	}
		
	int main(){
		sparse s1(2,2,4);
		sparse s2(2,2,4);
		cin>>s1;
		cin>>s2;
		sparse s=s1+s2;
		cout<<"First matrix:-\n"<<s1;
		cout<<"second matrix:-\n"<<s2;
		cout<<"final matrix:-\n"<<s;
		return 0;
	}
