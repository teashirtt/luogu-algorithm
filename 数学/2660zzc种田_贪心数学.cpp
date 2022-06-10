#include <iostream>
#include <algorithm>
using namespace std;
long long x,y,res;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>x>>y;
    if(x==y)
    {
        cout<<4*x;
        return 0;
    }
    while(x&&y)
    {
        if(x<y)
        {
            int q=y/x;
            res+=4*q*x;
            y-=q*x;
        }
        else
        {
            int q=x/y;
            res+=4*q*y;
            x-=q*y;
        }
    }
    cout<<res;
    return 0;
}