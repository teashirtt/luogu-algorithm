#include <iostream>
using namespace std;
const int N=500010;
long long n,m,x,sum[N],q[3*N],res=-0x3f3f3f3f;
void solve()
{
    int hh=0,tt=-1;
    q[++tt]=0;
    for(int i=1;i<=n;i++)
    {
        if(hh<=tt&&i-q[hh]>m) hh++;
        while(hh<=tt&&sum[q[tt]]>sum[i]) tt--;
        res=max(res,sum[i]-sum[q[hh]]);
        q[++tt]=i;
    }
    cout<<res;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>x,sum[i]=sum[i-1]+x;
    solve();
    return 0;
}