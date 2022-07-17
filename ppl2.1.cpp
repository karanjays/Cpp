#include <bits\stdc++.h>
using namespace std;

void ref_function(int *a, int *b){
    *a += *b;
    *b = abs(*a - 2*(*b));
}

int main()
{
    int val;
    int a,b;
    cout<<"Enter the value: ";
    cin>>a>>b;
    ref_function(&a,&b);
    cout<<"# values are "<<a<<" "<<b;
    return 0;
}

