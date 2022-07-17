#include<bits/stdc++.h>
using namespace std;

template<class k>
class addelements{
		k i;
		k j;
	public:
		addelements<k>(k i,k j){
			this->i=i;
			this->j=j;
		}
		void add(){
			k x=i+j;
			cout<<x<<endl;
		}
		
};

int main(){
	int z=4;
	while(z--){
		string tp;
		
		cin>>tp;
		
		if(tp=="int"){
			int x,y;
			cin>>x>>y;
			addelements<int> m(x,y);
			m.add();
		}
		else if(tp=="float"){
			float x,y;
			cin>>x>>y;
			addelements<float> m(x,y);
			m.add();
		}
		else if(tp=="string"){
			string x,y;
			cin>>x>>y;
			addelements<string> m(x,y);
			m.add();
		}
		else{
			cout<<"wrong data type !\n";
		}
	}
}
