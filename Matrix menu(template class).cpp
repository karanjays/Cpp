//#include<bits/stdc++.h>
//using namespace std;
//
//template <class X>
//class Diagonal{
//	private:
//		int n;
//		X *a;
//	public:
//		Diagonal(int n){
//			this->n=n;
//			a=new X[n];
//		}
//		void create(){
//			int i,j;
//			X x;
//			for(i=1;i<=n;i++){
//				for(j=1;j<=n;j++){
//					cin>>x;
//					if(i==j)
//						a[i-1]=x;
//				}
//			}
//		}
//		void set(int i,int j,X n){
//			if(i==j)
//				a[i-1]=n;
//		}
//		void get(int i,int j){
//			if(i==j)
//				cout<<a[i-1]<<endl;
//			else
//				cout<<"0"<<endl;
//		}
//		void display(){
//			int i,j;
//			for(i=1;i<=n;i++){
//				for(j=1;j<=n;j++){
//					if(i==j)
//						cout<<a[i-1]<<" ";
//					else
//						cout<<"0 ";
//				}
//				cout<<"\n";
//			}
//		}
//		
//		~Digonal(){
//			delete []a;
//		}
//};
//	int menu(){
//		int n;
//		cout<<"\n\t\t\t\t Menu";
//		cout<<"\n\t\t\t\t1. Create";
//		cout<<"\n\t\t\t\t2. Set";
//		cout<<"\n\t\t\t\t3. Get";
//		cout<<"\n\t\t\t\t4. Display";
//		cout<<"\n\t\t\t\t5. exit";
//		cout<<"\nEnter ur choice:-\n\t\t\t";
//		cin>>n;
//		return n;
//	}
//	int i,j;
//	int main(){
//		Diagonal <int>m(5);
//		while(1){
//			system("cls");
//			switch(menu()){
//				case 1:
//					m.create();
//					break;
//				case 2:
//					int n;
//					cin>>i>>j>>n;
//					m.set(i,j,n);
//					break;
//				case 3:
//					cin>>i>>j;
//					m.get(i,j);
//					break;
//				case 4:
//					m.display();
//					break;
//				case 5:
//					exit(0);
//				default:
//					printf("\nPlz Enter Valid choice...!!!...\n");
//			}
//			system("pause");			
//		}
//	}

//
//#include<bits/stdc++.h>
//using namespace std;
//
//template <class X>
//class LTM{
//	private:
//		int n;
//		X *a;
//	public:
//		LTM(int n){
//			this->n=n;
//			a=new X[(n*(n-1))/2];
//		}
//		void create(){
//			int i,j;
//			X x;
//			for(i=1;i<=n;i++){
//				for(j=1;j<=n;j++){
//					cin>>x;
//					if(i>=j)
//						a[i*(i-1)/2+j-1]=x;
//				}
//			}
//		}
//		void set(int i,int j,X n){
//			if(i>=j)
//				a[i*(i-1)/2+j-1]=n;
//		}
//		void get(int i,int j){
//			if(i>=j)
//				cout<<a[i*(i-1)/2+j-1]<<endl;
//			else
//				cout<<"0"<<endl;
//		}
//		void display(){
//			int i,j;
//			for(i=1;i<=n;i++){
//				for(j=1;j<=n;j++){
//					if(i>=j)
//						cout<<a[i*(i-1)/2+j-1]<<" ";
//					else
//						cout<<"0 ";
//				}
//				cout<<"\n";
//			}
//		}
//		~LTM(){
//			delete [] a;
//		}
//};
//	int menu(){
//		int n;
//		cout<<"\n\t\t\t\t Menu";
//		cout<<"\n\t\t\t\t1. Create";
//		cout<<"\n\t\t\t\t2. Set";
//		cout<<"\n\t\t\t\t3. Get";
//		cout<<"\n\t\t\t\t4. Display";
//		cout<<"\n\t\t\t\t5. exit";
//		cout<<"\nEnter ur choice:-\n\t\t\t";
//		cin>>n;
//		return n;
//	}
//	int i,j;
//	int main(){
//		LTM <int>m(3);
//		while(1){
//			system("cls");
//			switch(menu()){
//				case 1:
//					m.create();
//					break;
//				case 2:
//					int n;
//					cin>>i>>j>>n;
//					m.set(i,j,n);
//					break;
//				case 3:
//					cin>>i>>j;
//					m.get(i,j);
//					break;
//				case 4:
//					m.display();
//					break;
//				case 5:
//					exit(0);
//				default:
//					printf("\nPlz Enter Valid choice...!!!...\n");
//			}
//			system("pause");			
//		}
//	}


#include<bits/stdc++.h>
using namespace std;

template <class X>
class LTM{
	private:
		int n;
		X *a;
	public:
		LTM(int n){
			this->n=n;
			a=new X[(n*(n-1))/2];
		}
		void create(){
			int i,j;
			X x;
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					cin>>x;
					if(i>=j)
						a[n*(j-1)-(j-2)*(j-1)/2+i-j]=x;
				}
			}
		}
		void set(int i,int j,X n){
			if(i>=j)
				a[n*(j-1)-(j-2)*(j-1)/2+i-j]=n;
		}
		void get(int i,int j){
			if(i>=j)
				cout<<a[n*(j-1)-(j-2)*(j-1)/2+i-j]<<endl;
			else
				cout<<"0"<<endl;
		}
		void display(){
			int i,j;
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if(i>=j)
						cout<<a[n*(j-1)-(j-2)*(j-1)/2+i-j]<<" ";
					else
						cout<<"0 ";
				}
				cout<<"\n";
			}
		}
		~LTM(){
			delete [] a;
		}
};
	int menu(){
		int n;
		cout<<"\n\t\t\t\t Menu";
		cout<<"\n\t\t\t\t1. Create";
		cout<<"\n\t\t\t\t2. Set";
		cout<<"\n\t\t\t\t3. Get";
		cout<<"\n\t\t\t\t4. Display";
		cout<<"\n\t\t\t\t5. exit";
		cout<<"\nEnter ur choice:-\n\t\t\t";
		cin>>n;
		return n;
	}
	int i,j;
	int main(){
		LTM <int>m(3);
		while(1){
			system("cls");
			switch(menu()){
				case 1:
					m.create();
					break;
				case 2:
					int n;
					cin>>i>>j>>n;
					m.set(i,j,n);
					break;
				case 3:
					cin>>i>>j;
					m.get(i,j);
					break;
				case 4:
					m.display();
					break;
				case 5:
					exit(0);
				default:
					printf("\nPlz Enter Valid choice...!!!...\n");
			}
			system("pause");			
		}
	}


