#include<bits/stdc++.h>
using namespace std;

#define CALLS 10000000

class parent{
public:
    virtual int test(){
        int result=0;
        for(int i=0;i<1000;i++){
            result+=i;
        }
        return result;
    }
};

class child:public parent{
public:
    int test(){
        int result=0;
        for(int i=0;i<1000;i++){
            result+=i;
        }
        return result;
    }
};

int main(){
    parent pr;
    int res=0;
	
	cout<<"Calculating time...Please Wait...\n";
    int start_s=clock();
    for(int j=0;j<CALLS;j++){
        res=pr.test();
    }
    int stop_s=clock();

    cout << "Execution Time : " << (stop_s-start_s)/(double(CLOCKS_PER_SEC))*1000<<" milli seconds."<< endl;

    parent *ptr=new child;


    start_s=clock();
    for(int j=0;j<CALLS;j++){
        res=ptr->test();
    }
    stop_s=clock();

    cout << "Execution Time : " << (stop_s-start_s)/(double(CLOCKS_PER_SEC))*1000<<" milli seconds."<< endl;

    return 0;
}
