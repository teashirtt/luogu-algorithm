#include <iostream>
#define p cout<<"YES"<<'\n'
#define q cout<<"NO"<<'\n'
using namespace std;
int t,n,a,b;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int flag=0;
        cin>>a;
        for(int i=2;i<=n;i++)
        {
            cin>>b;
            if(b<=a) flag=1;
            a=b;
        }
        if(n%2==0||flag) p;
        else q;
    }
    return 0;
}