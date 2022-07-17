#include <bits\stdc++.h>
using namespace std;

class my_vector{
    int n;
    float *pt;
public:
    my_vector(int size){
        n=size;
        pt = new float[n];
    }
    void modify(int pos, float val){
        pt[pos] = val;
    }
    void operator *(float a){
        for(int i=0;i<n;i++)
            pt[i] *=a;
    }
    void vector_view(){
        cout<<"(";
        for(int i=0;i<n;i++){
            cout<<pt[i];
            if(i!=n-1)
                cout<<", ";
        }
        cout<<")"<<endl;
    }
};


int main()
{
    my_vector V(10);
    for(int i=0;i<10;i++)
        V.modify(i,1.2*i);
    V.vector_view();
    V*2;  
    V.vector_view(); 
    return 0;
}


