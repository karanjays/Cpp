#include <bits\stdc++.h>
using namespace std;

class hotelroom{
    int bedroom,bathroom;
public:
    hotelroom(int a, int b){
        this->bedroom=a;
        this->bathroom=b;
    }
    void input(int a,int b){
        this->bedroom=a;
        this->bathroom=b;
    }
    int cost(){
        return this->bedroom*50 + this->bathroom*100;
    }
};

class hotelapartment{
    int bedroom,bathroom;
public:
    hotelapartment(int a, int b){
        this->bedroom=a;
        this->bathroom=b;
    }
    void input(int a,int b){
        this->bedroom=a;
        this->bathroom=b;
    }
    int cost(){
        return this->bedroom*50 + this->bathroom*100+100;
    }
};
int main()
{
    hotelroom hr(12,14);
    hotelapartment ha(12,14);
    cout<<"room cost: "<<hr.cost()<<" apartment cost: "<<ha.cost()<<endl;
    return 0;
}


