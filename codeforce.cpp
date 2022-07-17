#include<bits/stdc++.h>
using namespace std;

class tree{
public:
    int root;
    tree *l;
    tree * r;
};

vector<int>in;

void sol(tree head)
{
    if(!head)
        return;
    sol(head.l);
    in.eplace_back(head.root);
    sol(head.r);
}

int main()
{
    vector<int>a;
    int n;
    cin>>n;
    while(n)
    {
        int z;
        cin>>z;
        a.emplace_back(z);
    }

    tree head,ans;
    head.root=a[0];
    head.l=NULL;
    head.r=NULL;
    ans=head;
    int f=0;
    for(int i=1;i<n;++i)
    {
        tree tmp;
        tmp.root=a[i];
        tmp.l=NULL;
        tmp.r=NULL;
        
        if(f==0)
        {
            ans.l=tmp;
            f=1;
        }
        else
        {
            ans.r=tmp;
            ans=ans.l;
            f=0;
        }
    }
    sol(head);
    for(auto it:in)
        cout<<it<<" ";
}