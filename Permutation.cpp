#include<bits/stdc++.h>
using namespace std;

//void perm(string m,int k){
//	int i=0;
//	static int z,a[30];
//	static char r[30];
//	if(m[k]=='\0'){
//		r[k]='\0';
//		cout<<"\t"<<++z<<endl;
//	}
//	else{
//		for(;m[i]!='\0';i++)
//			if(a[i]==0){
//				r[k]=m[i];
//				a[i]=1;
//				perm(m,k+1);
//				a[i]=0;
//		}
//	}
//}

void perm(string m,int l,int h){
	int i;
	static int z;
	if(l==h)
		cout<<++z<<"."<<m<<"\n";
	else{
		for(i=l;i<h;i++){
			swap(m[i],m[l]);
			perm(m,l+1,h);
			swap(m[i],m[l]);
		}
	}
}

int main(){
	string m;
	cin>>m;
	int h=m.length();
	perm(m,0,h);
}
