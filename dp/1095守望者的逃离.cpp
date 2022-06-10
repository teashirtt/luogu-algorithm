#include <iostream>
#include <cstring>
using namespace std;
const int N=300010;
int m,s,t,k1,k2;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>m>>s>>t;
    for(int i=1;i<=t;i++)
    {
        k1+=17;
        if(m>=10) k2+=60,m-=10;
        else m+=4;
        if(k1<k2) k1=k2;
        if(k1>=s)
        {
            cout<<"Yes"<<endl<<i<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl<<k1;
    return 0;
}