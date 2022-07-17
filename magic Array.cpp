#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

int fms(int s[3][3]) {
    int d[8][3][3]={
        {{8,1,6},{3,5,7},{4,9,2}},
        {{6,1,8},{7,5,3},{2,9,4}},
        {{4,9,2},{3,5,7},{8,1,6}},
        {{2,9,4},{7,5,3},{6,1,8}},
        {{8,3,4},{1,5,9},{6,7,2}},
        {{4,3,8},{9,5,1},{2,7,6}},
        {{6,7,2},{1,5,9},{8,3,4}},
        {{2,7,6},{9,5,1},{4,3,8}}
    };
    int b[8],i,m,j,k;
    for(i=0;i<8;i++){
        b[i]=0;
        for(j=0;j<3;j++){
            for(k=0;k<3;k++){
                if(s[j][k]!=d[i][j][k]){
                    b[i]+=abs(s[j][k]-d[i][j][k]);
                }
            }
        }
    }
    m=b[0];
    for(i=1;i<8;i++)
    {
        if(b[i]<m)
            m=b[i];
    }
    return m;
}

int main()
{
    int s[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }
    }
    int m;
    m=fms(s);
    cout<<m<<endl;

    return 0;
}

