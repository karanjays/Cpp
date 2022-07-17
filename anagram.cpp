//#include <bits/stdc++.h>
//using namespace std;
//int anagram(string k,string m){
//	int i=0,j=0;
//	for(;k[i]!='\0';i++){
//		for(j=0;m[j]!='\0';j++){
//			if(k[i]==m[j]){
//				break;	
//			}
//		}
//		if(m[j]=='\0')
//			return 0;
//	}
//	return 1;
//}
//int main(){
//	string k,m;
//	cin>>k>>m;
//	int i,j;
//	i=anagram(k,m);
//	j=anagram(m,k);
//	if(i*j==1)
//		cout<<"Anagram";
//	else
//		cout<<"Not Anagram";
//}

#include <bits/stdc++.h>
using namespace std;
int main(){
	string k,m;
	cin>>k>>m;
	int i=0,h[26]={0};
	for(i=0;k[i]!='\0';i++)
		h[k[i]-97]+=1;
	for(i=0;m[i]!='\0';i++){
		h[m[i]-97]-=1;
		if(h[m[i]-97]<0){
			cout<<"Not Anagram";
			break;
		}
	}
	if(m[i]=='\0')
		cout<<"Anagram";
}


