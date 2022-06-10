#include <iostream>
using namespace std;
const int N=2000010;
int n,a[N],sum[N],q[2*N],res;
void solve()
{
    int hh=0,tt=-1;
    q[++tt]=1;
    for(int i=2;i<=2*n-1;i++)
    {
        if(i-q[hh]+1>n) hh++;
        while(hh<=tt&&sum[q[tt]]>sum[i]) tt--;
        if(i>=n&&sum[q[hh]]>=sum[i-n]) res++;
        q[++tt]=i;
    }
    cout<<res;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],sum[i]=sum[i-1]+a[i],a[n+i]=a[i];
    for(int i=n+1;i<=2*n;i++) sum[i]=sum[i-1]+a[i];
    solve();
    return 0;
} 