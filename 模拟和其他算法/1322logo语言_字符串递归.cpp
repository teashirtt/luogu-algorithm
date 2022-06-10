#include <iostream>
#include <cstring>
#include <cmath>
#define gc() getchar()
using namespace std;
int solve()
{
    int val=0,k;
    string str;
    char s,t;
    while(cin>>s)
    {
        if(s==']') break;
        cin>>str>>k;
        if(s=='R')
        {
            t=gc();
            val+=k*solve();
            t=gc();
        }
        if(s=='F') t=gc(),val+=k;
        if(s=='B') t=gc(),val-=k;
        if(t==']') break;
    }
    return val;
}
int main()
{
    cout<<abs(solve());
    return 0;
}

