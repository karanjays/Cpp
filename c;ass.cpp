#include<bits/stdc++.h>
using namespace std;
class DB;
class DM{
	int m;
	float cm;
	
	public:
		void getdata(){
			cout<<"\nEnter the distance in meter & centimeter :\n";
			cin>>m>>cm;
		}
		
		void showdata(){
			cout<<"\n The distance is ";
			cout<<m<<" meter and "<<cm<<" centimeter.\n";
		}
		
		friend void add(DM &,DB &);
};

class DB{
	int f;
	float in;
	
	public:
		void getdata(){
			cout<<"\nEnter the distance in feet & inch :\n";
			cin>>f>>in;
		}
		
		void showdata(){
			cout<<"\n The distance is ";
			cout<<f<<" feet and "<<in<<" inch.\n";
		}
		
		friend void add(DM & , DB &);
};

void add(DM &x,DB &y){
	
		int n;
		cout<<"\n\t\t\t\t Menu";
		cout<<"\n\t\t\t\t1. Result in METER";
		cout<<"\n\t\t\t\t2. Result in FEET";
		cout<<"\nEnter ur choice:-\n\t\t\t";
		cin>>n;
		if(n==1){
			DM d;
			double ans=(x.m*100+x.cm+y.f*30.48+y.in*2.54)/100;
			d.m=(int)ans;
			d.cm=(ans-d.m)*100;
			d.showdata();
		}
		else{
			DB d;
			double ans=(x.m*39.37+x.cm*0.3937008+y.f*12+y.in)/12;
			d.f=(int)ans;
			d.in=(ans-d.f)*12;
			d.showdata();
		}
}


int main(){
		DM K;
		DB M;
		K.getdata();
		M.getdata();
		int z=2;
		while (z--)
			add(K,M);
		return 0;
}
