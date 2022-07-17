#include<bits/stdc++.h>
using namespace std;

int main(){
	ifstream file;
	file.open("book.txt");
	string name, number;
	cout<<"\t\tDetails.\n";
	cout<<"\tNAME\t\tCONTACT\n";
	while(file>>name>>number){
		cout<<"\t"<<name<<"\t\t"<<number<<"\n";		
	}
	file.close();
	return 0;
}
