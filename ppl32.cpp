#include<bits/stdc++.h>
using namespace std;
#define ln long long int


class Server{
	public:
		static int compute(ln A,ln B){
			if(A<0)
				throw invalid_argument("A is negative.");
			
			vector<int>C(A,0);
			int real=-1,cmplx=sqrt(-1);
			
			if(B==0)
				throw 0;
			
			real=(A/B)*real;
			int ans=C.at(B);
			return real+A-B*ans;
		}
};


int main(){
	ln A,B;
	int z=5;
	while(z--){
	cin>>A>>B;
	try{
		cout<<Server::compute(A,B)<<endl;
	}
	catch(bad_alloc &e){
		cout<<"Not enough space!.\n";
	}
	catch(exception &e){
		cout<<"Exception "<<e.what()<<"\n";
	}
	catch(int e){
		cout<<"Other Exception.\n";
	}
	}
	return 0;
}
