#include<iostream>
using namespace std;

class A{
public:
    virtual void karan(){
        cout<<"Hello, I am A.\n";
    }
};

class B:public A{
public:
    virtual void karan() override{
        cout<<"Hello, I am B.\n";
    }
};

class C:public B{
public:
    virtual void karan() override{
        cout<<"Hello, I am C.\n";
    }
};

class test{
public:
    test(){
        A *m;
        //static binding A
        m=new A;
        m->karan();
        delete m;
        //Dynamic binding B
        m=new B;
        m->karan();
        delete m;
        //Dynamic binding C
        m=new C;
        m->karan();
        delete m;
    }
};

int main(){
    test t;
    return 0;
}

