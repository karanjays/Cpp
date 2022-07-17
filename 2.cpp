#include <bits/stdc++.h>
#define ll long long int
#define ff(i, k, n) for (ll i = k, i < n, ++i)
using namespace std;

int main()
{
    string word, prev;
    int cnt = 0, maxCnt = 0;

    while (cin >> word)
    {
        if(word=="stop")
            break;
        if (word == prev)
            ++cnt;
            
        else
            cnt = 0;

        maxCnt = (cnt > maxCnt ? cnt : maxCnt);

        prev = word;
    }

    cout << "Max number of duplicates is " << maxCnt + 1 << endl;
}