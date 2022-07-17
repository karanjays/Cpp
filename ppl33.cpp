#include<bits/stdc++.h>
#define pi 3.14159

using namespace std;

class Polar{
	float r,a,x,y;
	
	public:
		Polar(){
		};
		Polar( float k, float m){
			r=k;
			a=m*(pi/180);
			x=r*cos(a);
			y=r*sin(a);
		}
		
		void show(){
			cout<<"Radius : "<<r<<"\nAngle :"<<a<<endl;
		}
		
		Polar operator +(Polar l){
				Polar U;
		
				U.x=x+l.x;
				U.y=y+l.y;
				U.a=atan(U.y/U.x);
				U.r=sqrt(U.x*U.x+U.y*U.y);
				
				return U;
			}
};

	

int main(){
	Polar P1,P2,P3;
	
	float r,a;
	cout<<"Enter radius and amgle p1:\N\t";
	cin>>r>>a;
	P1=Polar(r,a);
	
	cout<<"Enter radius and amgle p2:\N\t";
	cin>>r>>a;
	P2=Polar(r,a);
	
	P3=P1+P2;
	P3.show();
	
	return 0;
}
