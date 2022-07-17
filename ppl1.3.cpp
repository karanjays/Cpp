#include<bits/stdc++.h>
using namespace std;


class details{
	public:
		char name[100];
		long long int acc_no;
		int acc_typ;
		float balance=0;
		int min_bal=2000;
		void input(){
			cout<<"Enter name :-\n\t\t\t";
			cin>>name;
			cout<<"Enter account number :-\n\t\t\t";
			cin>>acc_no;
			cout<<"Enter balance :-\n\t\t\t";
			cin>>balance;
			cout<<"Enter Account type:-\n\tEnter 1 for SAVING ACCOUNT\n\tEnter 2 for CURRENT ACCOUNT\n\t\t\t";
			cin>>acc_typ;
		}
		void display(){
			cout<<"\n\t\t\t\tACCOUNT DETAILS:\n";
			cout<<"NAME : "<<name<<endl;
			cout<<"ACOUNT NUMBER : "<<acc_no<<endl;
			if(acc_typ==1)
				cout<<"ACOUNT TYPE : SAVING ACCOUNT"<<endl;
			else
				cout<<"ACOUNT TYPE : CURRENT ACCOUNT"<<endl;
			cout<<"BALANCE : RS."<<balance<<endl;
		}
		void deposit(){
			int amount;
			cout<<"Enter deposit amount\n\t\t\t";
			cin>>amount;
			balance+=amount;
			cout<<"\n Deposited Successful \n";	
			cout<<"\n New balance is : RS."<<balance;		
		}
		void wd(){
			int a;
			cout<<"Enter the amount to withdrawn :-\n\t\t\t";
			cin>>a;
			if(balance>=a & acc_typ==1){
				balance-=a;
				cout<<"\n New balance is : RS."<<balance;
				cout<<"\n Withdrawn Successful \n";
			}
			else if(balance>=a+2000 & acc_typ!=1){
				balance-=a;
				cout<<"\n New balance is : RS."<<balance;
				cout<<"\n Withdrawn Successful \n";
			}
			else{
				cout<<"\n Insufficient Balance \n";
			}
			
		}
};



class SA :public details{
	float inte;
	public:
		void interest(){
			int t,r=5;
			cout<<"Enter time duration :- \n\t\t\t";
			cin>>t;
			inte=balance*pow(1+r/100.0,t)-balance;
			cout<<"Actual Interest is : RS."<<inte<<endl;
			balance+=inte;
		}
};

class CA : public details{
	public:
		int penality=500;
		void check(){
		if(balance<=min_bal){
			balance-=penality;
			cout<<"\n Penality imposed :- RS."<<penality<<endl;
		}
		else{
			cout<<"\n No Penality imposed.\n";
		}
		}
};


int main(){
		CA c1;
		SA s1;
		c1.input();
		cout<<"\n\n";
		c1.display();
		cout<<"\n\n";
		c1.deposit();
		cout<<"\n\n";
		c1.wd();
		cout<<"\n\n";
		c1.display();
		cout<<"\n\n";
		s1.input();
		cout<<"\n\n";
		s1.display();
		cout<<"\n\n";
		s1.deposit();
		cout<<"\n\n";
		s1.wd();
		cout<<"\n\n";
		s1.interest();
		cout<<"\n\n";
		s1.display();
		cout<<"\n\n";
		
		
		return 0;
}
