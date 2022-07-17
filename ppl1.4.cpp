#include<bits/stdc++.h>
using namespace std;

class STAFF{
	protected:
		int code;
		string name;
	public:
		void set_info(string n,int c){
			name=n;
			code=c;
		}
};

class EDUCATION:public STAFF{
	protected:
		string quali;
	public:
		void set_qualification(string q){
			quali=q;
		}
};

class TEACHER :public EDUCATION{
	protected:
		string sub,publication;
	public:
		void set_details(string s,string p){
			sub=s;
			publication=p;
		}
		void show(){
			cout<<" Name\t"<<"Code\t"<<"Subject\t"<<"Publication\t"<<"Qualification\n";
			cout<<name<<"\t"<<code<<"\t"<<sub<<"\t"<<publication<<"\t"<<quali<<"\n";
		}
	};
	
	class OFFICER:public EDUCATION{
		string grade;
		public:
			void set_details(string g){
				grade=g;
			}
			
			void show(){
				cout<<" Name\t"<<"Code\t"<<"Catagory\t"<<"Qualification\n";
				cout<<name<<"\t"<<code<<"\t"<<grade<<"\t"<<quali<<"\n";
			}
	};
	
	class TYPIST: public STAFF{
		protected:
			float speed;
		public:
			void set_speed(float s){
				speed=s;
			}
	};
	
	class REGULAR: public TYPIST{
		protected:
			float wage;
		public:
			void set_wage(float w){
				wage=w;
			}
			void show(){
				cout<<" Name\t"<<"Code\t"<<"Speed\t"<<"Wage\n";
				cout<<name<<"\t"<<code<<"\t"<<speed<<"\t"<<wage<<"\n";
			}
	};
	
	class CASUAL: public TYPIST{
		float wage;
		public:
			void set_wage(float w){
				wage=w;
			}
			void show(){
				cout<<" Name\t"<<"Code\t"<<"Speed\t"<<"Wage\n";
				cout<<name<<"\t"<<code<<"\t"<<speed<<"\t"<<wage<<"\n";
			}
	};
	
	int main(){
		TEACHER T;
		T.set_info("KARAN",450);
		T.set_details("PPL","Clous Computing");
		T.set_qualification("PHD in Cloud computing");
		
		OFFICER O;
		O.set_info("DR.Simaran",333);
		O.set_details("Prof.");
		O.set_qualification("5 years exp.");
		
		REGULAR RT;
		RT.set_info("Eqbal khan",444);
		RT.set_speed(112.45);
		RT.set_wage(18000);
		
		CASUAL CT;
		CT.set_info("Maulik Prajapati",555);
		CT.set_speed(94.85);
		CT.set_wage(31000);
		
		cout<<"\n\t\t\t\t TEACHER DETAILS:\n";
		T.show();
		
		cout<<"\n\t\t\t\t OFFICER DETAILS:\n";
		O.show();
		
		cout<<"\n\t\t\t\t REGULAR TYPIST DETAILS:\n";
		RT.show();
		
		cout<<"\n\t\t\t\t CASULA TYPIST DETAILS:\n";
		CT.show();
		
		return 0;
	}
